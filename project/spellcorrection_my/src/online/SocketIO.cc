 ///
 /// @file    SocketIO.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-18 17:34:30
 ///
 
#include "../../include/online/SocketIO.h"
#include "../../include/online/Mylogger.h"
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <iostream>
using std::cout;
using std::endl;

namespace online
{

bool SocketIO::isClosed()
{
	int nret = 0;
	char buff[1024];
	::memset(buff, 0, sizeof(buff));
	do {
		nret = ::recv(_fd, buff, sizeof(buff), MSG_PEEK);
	}while(nret == -1 && errno == EINTR);
	return (nret == 0);
}

size_t SocketIO::readn(char * buff, size_t len)
{
	char * p = buff;
	int left = len;
	while(left > 0) {
		int ret = ::read(_fd, p, left);	
		LogDebug("read %d bytes", ret);
		if(ret == -1 && errno == EINTR)
			continue;
		else if(ret == -1) {
			::perror(">> read");
			LogError("read error");
			return len - left;
		} else if(ret == 0) {//连接断开的情况
			return len - left;
		} else if(ret > 0) {
			left -= ret;
			p += ret;
		}
	}
	return len - left;
}

size_t SocketIO::writen(const char * buff, size_t len)
{
	const char * p = buff;
	int left = len;
	while(left > 0) {
		int ret = ::write(_fd, p, left);	
		LogDebug("write %d bytes", ret);
		if(ret == -1 && errno == EINTR)
			continue;
		else if(ret == -1) {
			::perror(">> write");
			LogError("write error");
			return len - left;
		} else {
			left -= ret;
			p += ret;
		}
	}
	return len - left;
}

size_t SocketIO::recvPeek(char * buff, size_t len)
{
	int ret = 0;
	do {
		ret = ::recv(_fd, buff, len, MSG_PEEK);//并未移走内核缓冲区中的数据
	}while(ret == -1 && errno == EINTR);
	return ret;
}

//@parameter buff 代表应用缓冲区
size_t SocketIO::readline(char * buff, size_t maxlen)//接收一行数据,采用'\n'表示数据的结束
{
	int left = maxlen - 1;	
	char * p = buff;
	int total = 0;//已经从内核缓冲区中移走的数据
	while(left > 0) {
		size_t ret = recvPeek(p, left);//没有移走
		LogDebug("recvPeer %d bytes", ret);
		if(ret <= 0) {
			return ret;
		}

		for(size_t idx = 0; idx != ret; ++idx) {
			if(p[idx] == '\n') {
				size_t size = idx + 1;
				if(size != readn(p, size)) {//从内核缓冲区中移走数据
					LogError("read error");
					return -1;
				}

				total += size;
				p += size;
				*p = '\0';
				return total;
			}
		}
		if(ret != readn(p, ret)) {
			LogError("read error");
			return -1;
		}
		p += ret;
		left -= ret;
		total += ret;
	}
	*p = '\0';
	return total;
}



}//end of namespace wd
