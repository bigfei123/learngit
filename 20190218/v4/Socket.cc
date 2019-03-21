 ///
 /// @file    Socket.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-18 16:06:54
 ///
 
#include "Socket.h"

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>

namespace wd
{
Socket::Socket()
{
	_fd = ::socket(AF_INET, SOCK_STREAM, 0);//TCP协议
	if(_fd == -1) {
		::perror(">>> socket");
		//LogError("socket create error");//引进log4cpp日志系统
	}
	//LogDebug(">> socket create ");
}

Socket::~Socket()
{
	::close(_fd);
	printf("~Socket()\n");
}

Socket::Socket(int fd)
: _fd(fd)
{
	//LogDebug("Socket(int)");
}

int Socket::fd() const
{
	return _fd;
}

void Socket::nonblock()
{
	int flags = ::fcntl(_fd, F_GETFL, 0);
	if(flags == -1) {
		perror("fcntl");
	}
	int ret = ::fcntl(_fd, F_SETFL, O_NONBLOCK | flags);
	if(ret == -1) {
		perror("fcntl");
	}
}

void Socket::shutdownWrite() 
{
	if(::shutdown(_fd, SHUT_WR)) {
		::perror(">> shutdown");
		//LogError("shutdownWrite()");
	}
}



}// end of namespace wd
