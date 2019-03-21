 ///
 /// @file    EventLoop.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-27 11:19:24
 ///
 
#ifndef __WD_EVENTLOOP_H__
#define __WD_EVENTLOOP_H__

#include "MutexLock.h"

#include <sys/epoll.h>
#include <map>
#include <memory>
#include <vector>
#include <functional>
using std::map;
using std::shared_ptr;
using std::vector;
using std::function;

namespace wd
{

class Acceptor;
class TcpConnection;
class EventLoop
{
public:
	using TcpConnectionCallback = function<void(const shared_ptr<TcpConnection>)>;
	using Functor = std::function<void()>;
	EventLoop(Acceptor & acceptor);
	~EventLoop();

	void loop();
	void unloop();
	void runInLoop(Functor && cb);

	void doPendingFunctors();
	
	void setConnectionCallback(TcpConnectionCallback && cb)
	{	_onConnectionCallback = std::move(cb);	}

	void setMessageCallback(TcpConnectionCallback && cb)
	{	_onMessageCallback = std::move(cb);	}

	void setCloseCallback(TcpConnectionCallback && cb)
	{	_onCloseCallback = std::move(cb);	}
private:
	int createEpollFd();
	int createEventFd();
	void addEpollReadFd(int fd);
	void delEpollReadFd(int fd);

	void waitEpollFds();
	void handleNewConnection();
	void handleMessage(int peerfd);
	void handleRead();
	void wakeup();

private:
	int _efd;
	int _eventfd;
	Acceptor & _acceptor;
	map<int, shared_ptr<TcpConnection>> _conns;
	vector<struct epoll_event> _eventsList;
	bool _isLooping;
	
	MutexLock _mutex;
	vector<Functor> _pendingFunctors;

	TcpConnectionCallback _onConnectionCallback;
	TcpConnectionCallback _onMessageCallback;
	TcpConnectionCallback _onCloseCallback;
};

}// end of namespace wd


#endif
