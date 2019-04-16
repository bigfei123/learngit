 ///
 /// @file    Server.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-23 12:55:07
 ///
 
#include "../../include/online/Server.h"

namespace online
{

Server::Server(const string & ip, unsigned short port, int threadNum, int taskNum)
: _tcpServer(ip, port)
, _threadpool(threadNum, taskNum)
{}

Server::~Server()
{
	stop();
}

void Server::stop()
{
	_threadpool.stop();
	_tcpServer.stop();
}


}//end of namespace online
