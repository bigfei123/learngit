 ///
 /// @file    EventLoop.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-27 11:25:15
 ///
 
#include "../../include/online/EventLoop.h"
#include "../../include/online/Acceptor.h"
#include "../../include/online/TcpConnection.h"
#include "../../include/online/Mylogger.h"

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/eventfd.h>

#include <iostream>

using std::cout;
using std::endl;
namespace online
{

EventLoop::EventLoop(Acceptor & acceptor)
: _efd(createEpollFd()) 
, _listenfd(acceptor.fd())
, _eventfd(createEpollFd())
, _acceptor(acceptor) 
, _events(1024) 
, _isLooping(false)
{}

EventLoop::~EventLoop()
{
	::close(_efd);
}

void EventLoop::loop()
{
	addEpollReadFd(_efd, _listenfd);
	addEpollReadFd(_efd, _eventfd);
	_isLooping = true;
	LogInfo("Loop start");
	while(_isLooping) {
		waitEpollFds();
	}
}

void EventLoop::unloop()
{
	if(_isLooping)
		_isLooping = false;
	LogInfo("Loop stop");
}

void EventLoop::runInLoop(Functor && cb)
{
	//成为临界资源
	{
		MutexLockGuard autolock(_mutex);
		_pendingFunctors.push_back(std::move(cb));
	}
	wakeup();//通知IO线程
}

//IO线程中执行的就是该方法
void EventLoop::waitEpollFds()
{
	int nready;
	do {
		nready = ::epoll_wait(_efd, &*_events.begin(), _events.size(), 5000);
	}while(nready == -1 && errno == EINTR);

	if(nready == 0) {
		cout << ">> epoll_wait timeout!\n" << endl;
	}else if(nready == -1) {
		::perror(">> epoll_wait");
		LogError("epoll_wait error");
		return ;
	}else {
		if((size_t)nready == _events.size()) {
			_events.resize(2 * _events.size());
		}

		for(int idx = 0; idx < nready; ++idx) {
			if(_events[idx].data.fd == _acceptor.fd() &&
			   _events[idx].events & EPOLLIN) {
				handleNewConnection();
			}else if(_events[idx].data.fd == _eventfd){
				handleRead();
				doPendingFunctors();
			}else {
				handleMessage(_events[idx].data.fd);
			}
		}
	}
}

void EventLoop::handleNewConnection()
{
	int peerfd = _acceptor.accept();
	if(-1 == peerfd) {
		return ;
	}

	TcpConnectionPtr conn(new TcpConnection(peerfd, *this));
	_connMap.insert(std::make_pair(peerfd, conn));
	addEpollReadFd(_efd, peerfd);

	conn->setConnectionCallback(_onConnectionCallback);
	conn->setMessageCallback(_onMessageCallback);
	conn->setCloseCallback(_onCloseCallback);

	conn->handleConnectionCallback();
}

void EventLoop::setConnectionCallback(EpollCallback && cb)
{
	_onConnectionCallback(std::move(cb));
}

void EventLoop::handleMessage(int peerfd)
{
	auto iter = _connMap.find(peerfd);
	if(iter != _connMap.end()) {
		//先判断连接是否断开
		auto conn = iter->second;
		bool closed = conn->isClosed();
		if(!closed) { //收到数据的情况
			conn->handleMessageCallback();
		}else {//连接断开的情况
			conn->handleCloseCallback();
			delEpollReadFd(_efd, peerfd);
			_connMap.erase(peerfd);
		}
	}
}

int EventLoop::createEpollFd()
{
	int fd = ::epoll_create1(0);
	if(fd == -1) {
		::perror(">> epoll_create1");
		LogError("create epollfd error");
		exit(EXIT_FAILURE);
	}
	return fd;
}

int EventLoop::createEventFd()
{
	int fd = ::eventfd(0, 0);
	if(fd == -1) {
		::perror(">> eventfd");
		LogError("create epollfd error");
		exit(EXIT_FAILURE);
	}
	return fd;
}

void EventLoop::addEpollReadFd(int efd ,int readfd)
{
	struct epoll_event value;
	value.data.fd = readfd;
	value.events = EPOLLIN;
	int ret = ::epoll_ctl(efd, EPOLL_CTL_ADD, readfd, &value);
	if(ret == -1) {
		perror(">> epoll_ctl");
		LogError("add epollfd read error");
		exit(EXIT_FAILURE);
	}
}

void EventLoop::delEpollReadFd(int efd, int delfd)
{
	int ret = ::epoll_ctl(efd, EPOLL_CTL_DEL, delfd, nullptr);
	if(ret == -1) {
		perror(">> epoll_ctl");
		LogError("delete epollfd read error");
		exit(EXIT_FAILURE);
	}
}

void EventLoop::handleRead()
{
	uint64_t howmany = 0;
	int ret = ::read(_eventfd, &howmany, sizeof(howmany));
	if(ret != sizeof(howmany)) {
		::perror(">> read");
		LogWarn("read event error");
	}
}

void EventLoop::wakeup()
{
	uint64_t one = 1;
	int ret = ::write(_eventfd, &one, sizeof(one));
	if(ret != sizeof(one)) {
		::perror(">> write");
		LogWarn("write event error");
	}
}

void EventLoop::doPendingFunctors()
{
	vector<Functor> tmp;
	{
		MutexLockGuard autolock(_mutex);
		tmp.swap(_pendingFunctors);
	}

	for(auto & functor : tmp)
		functor();
}

}//end of namespace wd
