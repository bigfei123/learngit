 ///
 /// @file    TcpConnection.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-18 17:09:13
 ///
 
#include "TcpConnection.h"
#include <string.h>
#include <sys/socket.h>
#include <iostream>

#include <sstream>
namespace wd
{
TcpConnection::TcpConnection(int peerfd)
: _sock(peerfd)
, _localAddr(localInetAddr())
, _peerAddr(peerInetAddr())
, _socketIO(peerfd)
, _isShutdownWrite(false)
{
	//_sock.nonblock();
}

TcpConnection::~TcpConnection()
{
	shutdown();
	std::cout << toString() << " has closed!" << std::endl;
}

string TcpConnection::receive()
{
	char buff[65536] = {0};//栈空间开辟，O(1)
	::memset(buff, 0, sizeof(buff));
	int ret = _socketIO.readline(buff, sizeof(buff));
	//根据ret的返回值，做相应处理
	if(ret <= 0) {//连接断开
		return string();
	}else {
		return string(buff);
	}
}
	
void TcpConnection::send(const string & msg)
{
	size_t ret = _socketIO.writen(msg.data(), msg.size());
	if(ret != msg.size()) {
		//LogInfo("send msg error");
	}
}

void TcpConnection::shutdown()
{
	if(!_isShutdownWrite) {
		_sock.shutdownWrite();
		_isShutdownWrite = true;
	}
}

bool TcpConnection::isClosed()
{
	return _socketIO.isClosed();
}

string TcpConnection::toString() const
{
	std::ostringstream oss;
	oss << _localAddr.ip() << ":" << _localAddr.port() << " --> " 
		<< _peerAddr.ip() << ":" << _peerAddr.port();
	return oss.str();
}


InetAddress TcpConnection::localInetAddr()
{
	struct sockaddr_in localaddr;
	socklen_t len = sizeof(struct sockaddr_in);
	int ret = ::getsockname(_sock.fd(), (struct sockaddr*)&localaddr, &len);
	if(ret == -1) {
		::perror(">> getsockname");
	}
	return InetAddress(localaddr);
}

InetAddress TcpConnection::peerInetAddr()
{
	struct sockaddr_in peeraddr;
	socklen_t len = sizeof(struct sockaddr_in);
	int ret = ::getpeername(_sock.fd(), (struct sockaddr*)&peeraddr, &len);
	if(ret == -1) {
		::perror(">> getpeername");
	}
	return InetAddress(peeraddr);
}

}//end of namespace wd
