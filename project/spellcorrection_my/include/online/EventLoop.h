 ///
 /// @file    EventLoop.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-27 11:19:24
 ///
 
#ifndef __WD_EVENTLOOP_H__
#define __WD_EVENTLOOP_H__

#include "../../include/online/MutexLock.h"
#include "../../include/online/TcpConnection.h"
#include <sys/epoll.h>
#include <map>
#include <memory>
#include <vector>
#include <functional>
using std::map;
using std::shared_ptr;
using std::vector;
using std::function;

namespace online
{

class Acceptor;
class TcpConnection;
class EventLoop
{
public:
	using EpollCallback = TcpConnection::TcpConnectionCallback;
	using Functor = std::function<void()>;

	EventLoop(Acceptor & acceptor);
	~EventLoop();

	void loop();
	void unloop();
	void runInLoop(Functor && cb);

	void doPendingFunctors();
	
	void setConnectionCallback(EpollCallback && cb);
	void setMessageCallback(EpollCallback && cb);
	void setCloseCallback(EpollCallback && cb);
private:
	int createEpollFd();
	int createEventFd();
	void addEpollReadFd(int, int);
	void delEpollReadFd(int, int);

	void waitEpollFds();
	void handleNewConnection();
	void handleMessage(int peerfd);
	void handleRead();
	void wakeup();

private:
	int _efd;
	int _listenfd;
	int _eventfd;
	Acceptor & _acceptor;
	map<int, TcpConnectionPtr> _connMap;
	vector<struct epoll_event> _events;
	bool _isLooping;
	MutexLock _mutex;
	vector<Functor> _pendingFunctors;

	EpollCallback _onConnectionCallback;
	EpollCallback _onMessageCallback;
	EpollCallback _onCloseCallback;
};

}// end of namespace wd


#endif
