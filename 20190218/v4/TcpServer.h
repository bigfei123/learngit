 ///
 /// @file    TcpServer.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-27 18:52:34
 ///
 
#ifndef __WD_TCPSERVER_H__
#define __WD_TCPSERVER_H__

#include "Acceptor.h"
#include "EventLoop.h"

#include <string>
#include <memory>
#include <functional>
using std::string;
using std::shared_ptr;
using std::function;

namespace wd
{
class TcpConnection;
class TcpServer
{
public:
	using TcpConnectionCallback = function<void (const shared_ptr<TcpConnection>)>;
	TcpServer(const string & ip, unsigned short port)	
	: _acceptor(ip, port)
	, _loop(_acceptor)
	{}

	void start()
	{
		_acceptor.ready();
		_loop.loop();
	}

	void setConnectionCallback(TcpConnectionCallback && cb)
	{	_loop.setConnectionCallback(std::move(cb));  }

	void setMessageCallback(TcpConnectionCallback && cb)
	{	_loop.setMessageCallback(std::move(cb));  }

	void setCloseCallback(TcpConnectionCallback && cb)
	{	_loop.setCloseCallback(std::move(cb));  }

private:
	Acceptor _acceptor;
	EventLoop _loop;

};
}// end of namespace wd


#endif
