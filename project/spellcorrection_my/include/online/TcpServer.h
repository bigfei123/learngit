 ///
 /// @file    TcpServer.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-27 18:52:34
 ///
 
#ifndef __ONLINE_TCPSERVER_H__
#define __ONLINE_TCPSERVER_H__

#include "../../include/online/Acceptor.h"
#include "../../include/online/EventLoop.h"

#include <string>
#include <memory>
#include <functional>
using std::string;
using std::shared_ptr;
using std::function;

namespace online
{
class TcpServer
{
public:
	using TcpServerCallback = TcpConnection::TcpConnectionCallback;
	TcpServer(const string & ip, unsigned short port);
	TcpServer(unsigned short port);

	void start();
	void stop();

	void setConnectionCallback(TcpServerCallback && cb);
	void setMessageCallback(TcpServerCallback && cb);
	void setCloseCallback(TcpServerCallback && cb);

private:
	Acceptor _acceptor;
	EventLoop _loop;

};
}// end of namespace wd


#endif
