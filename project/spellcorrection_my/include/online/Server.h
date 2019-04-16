 ///
 /// @file    Server.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-23 12:45:10
 ///

#ifndef __ONLINE_SERVER_H__
#define __ONLINE_SERVER_H__

#include "TcpConnection.h"
#include "TcpServer.h"
#include "Threadpool.h"

namespace online
{

class Server
{
public:
	Server(const string &, unsigned short, int, int );

	virtual ~Server();

	virtual void start() = 0;
	void stop();
protected:
	virtual void onConnection(const TcpConnectionPtr &) = 0;
	virtual void onMessage(const TcpConnectionPtr &) = 0;
	virtual void onClose(const TcpConnectionPtr &) = 0;

protected:
	TcpServer _tcpServer;
	Threadpool _threadpool;


};

}//end of namespace online


#endif
