 ///
 /// @file    EventLoop.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-27 11:19:24
 ///
 
#ifndef __WD_EVENTLOOP_H__
#define __WD_EVENTLOOP_H__

#include <sys/epoll.h>
#include <map>
#include <memory>
#include <vector>
using std::map;
using std::shared_ptr;
using std::vector;

namespace wd
{

class Acceptor;
class TcpConnection;

class EventLoop
{
public:
	EventLoop(Acceptor & acceptor);
	~EventLoop();

	void loop();
	void unloop();

private:
	int createEpollFd();
	void addEpollReadFd(int fd);
	void delEpollReadFd(int fd);
	void waitEpollFds();
	void handleNewConnection();
	void handleMessage(int peerfd);

private:
	int _efd;
	Acceptor & _acceptor;
	map<int, shared_ptr<TcpConnection>> _conns;
	vector<struct epoll_event> _eventsList;
	bool _isLooping;
};

}// end of namespace wd


#endif
