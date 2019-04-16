 ///
 /// @file    TcpServer.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-23 14:14:12
 ///
 
#include "../../include/online/TcpServer.h" 

namespace online
{

TcpServer::TcpServer(const string & ip, unsigned short port)
: _acceptor(ip, port)
, _loop(_acceptor)
{}

TcpServer::TcpServer(unsigned short port)
: _acceptor(port)
, _loop(_acceptor)
{}

void TcpServer::start()
{
	_acceptor.ready();
	_loop.loop();
}

void TcpServer::stop()
{
	_loop.unloop();
}

void TcpServer::setConnectionCallback(TcpServerCallback && cb)
{
	_loop.setConnectionCallback(std::move(cb));
}

void TcpServer::setMessageCallback(TcpServerCallback && cb)
{
	_loop.setMessageCallback(std::move(cb));
}

void TcpServer::setCloseCallback(TcpServerCallback && cb)
{
	_loop.setCloseCallback(std::move(cb));
}

}//end of namespace online
