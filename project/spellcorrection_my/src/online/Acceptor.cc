 ///
 /// @file    Acceptor.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-18 16:25:18
 ///
 
#include "../../include/online/Acceptor.h"
#include "../../include/online/Mylogger.h"
#include <sys/socket.h>

namespace online
{

Acceptor::Acceptor(const string & ip, unsigned short port)
: _sock()
, _addr(ip, port)
{}

Acceptor::Acceptor(unsigned short port)
: _sock()
, _addr(port)
{}

void Acceptor::ready()
{
	setReuseAddr();
	setReusePort();
	bind();
	listen();
}

int Acceptor::fd() const
{	return _sock.fd();	}		

void Acceptor::setReuseAddr()
{
	int reuse = 1;
	if(setsockopt(fd(), SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(int))) { 
		::perror(">> setsockopt");
		LogError("setsockopt");
	}
}

void Acceptor::setReusePort()
{
	int reuse = 1;
	if(setsockopt(fd(), SOL_SOCKET, SO_REUSEPORT, &reuse, sizeof(int))) {
		::perror(">> setsockopt");
		LogError("setsockopt");
	}
}

void Acceptor::bind()
{
	int ret = ::bind(fd(), (const struct sockaddr *)_addr.getSockaddrPtr(), sizeof(InetAddress));
	if(ret == -1) {
		::perror(">> bind");
		LogError("bind error");
	}
}

void Acceptor::listen()
{
	int ret = ::listen(fd(), 10);
	if(-1 == ret) { 
		::perror("listen");
		LogError("listen error");
	}
}

int Acceptor::accept() 
{
	int peerfd = ::accept(fd(), nullptr, nullptr);
	if(peerfd == -1) {
		::perror(">> accept");
		LogError("accept error");
	}
	return peerfd;
}


}//end of namespace wd

