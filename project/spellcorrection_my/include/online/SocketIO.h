 ///
 /// @file    SocketIO.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-18 17:06:22
 ///
 
#ifndef __WD_SOCKETIO_H__
#define __WD_SOCKETIO_H__

#include "Noncopyable.h"
#include <sys/types.h>

namespace online
{
class SocketIO
{
public:
	explicit 
	SocketIO(int fd) : _fd(fd){}

	bool isClosed();

	size_t readn(char * buff, size_t len);//接收len字节的数据
	size_t writen(const char * buff, size_t len);//发送len字节的数据
	size_t readline(char * buff, size_t maxlen);//接收一行数据,采用'\n'表示数据的结束

private:
	size_t recvPeek(char * buff, size_t len);

private:
	int _fd;
};

}//end of namespace wd


#endif
