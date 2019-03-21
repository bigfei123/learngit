 ///
 /// @file    EventLoop.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-27 11:25:15
 ///
 
#include "EventLoop.h"
#include "Acceptor.h"
#include "TcpConnection.h"

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <iostream>

using std::cout;
using std::endl;
namespace wd
{

EventLoop::EventLoop(Acceptor & acceptor)
: _efd(createEpollFd()) 
, _acceptor(acceptor) 
, _eventsList(1024) 
, _isLooping(false)
{
	addEpollReadFd(_acceptor.fd());
}
EventLoop::~EventLoop()
{
	::close(_efd);
}

void EventLoop::loop()
{
	_isLooping = true;
	while(_isLooping) {
		waitEpollFds();
	}
}

void EventLoop::unloop()
{
	if(_isLooping)
		_isLooping = false;
}

void EventLoop::waitEpollFds()
{
	int nready;
	do {
		nready = ::epoll_wait(_efd, &*_eventsList.begin(), _eventsList.size(), 5000);
	}while(nready == -1 && errno == EINTR);

	if(nready == 0) {
		cout << ">> epoll_wait timeout!\n" << endl;
	}else if(nready == -1) {
		::perror(">> epoll_wait");
		return ;
	}else {
		if(nready == _eventsList.size()) {
			_eventsList.resize(2 * _eventsList.size());
		}

		for(int idx = 0; idx < nready; ++idx) {
			if(_eventsList[idx].data.fd == _acceptor.fd() &&
			   _eventsList[idx].events & EPOLLIN) {
				handleNewConnection();
			}else {
				handleMessage(_eventsList[idx].data.fd);
			}
		}
	}
}

void EventLoop::handleNewConnection()
{
	int peerfd = _acceptor.accept();
	addEpollReadFd(peerfd);

	shared_ptr<TcpConnection> conn(new TcpConnection(peerfd));
	cout << ">> " << conn->toString() << "has connected!" << endl;

	_conns.insert(std::make_pair(peerfd, conn));
}

void EventLoop::handleMessage(int peerfd)
{
	auto iter = _conns.find(peerfd);
	if(iter != _conns.end()) {
		//先判断连接是否断开
		auto conn = iter->second;
		bool closed = conn->isClosed();
		if(!closed) { //收到数据的情况
			string msg = conn->receive();
			cout << ">> server receive:" << msg << endl;
			conn->send(msg);
		}else {//连接断开的情况
			//cout << ">> " << conn->toString() << "has closed!" << endl;
			delEpollReadFd(peerfd);
			_conns.erase(peerfd);
		}
	}
}

int EventLoop::createEpollFd()
{
	int fd = ::epoll_create1(0);
	if(fd == -1) {
		::perror(">> epoll_create1");
	}
	return fd;
}

void EventLoop::addEpollReadFd(int fd)
{
	struct epoll_event value;
	value.data.fd = fd;
	value.events = EPOLLIN;
	int ret = ::epoll_ctl(_efd, EPOLL_CTL_ADD, fd, &value);
	if(ret == -1) {
		perror(">> epoll_ctl");
	}
}

void EventLoop::delEpollReadFd(int fd)
{
	struct epoll_event value;
	value.data.fd = fd;
	value.events = EPOLLIN;
	int ret = ::epoll_ctl(_efd, EPOLL_CTL_DEL, fd, &value);
	if(ret == -1) {
		perror(">> epoll_ctl");
	}
}

}//end of namespace wd
