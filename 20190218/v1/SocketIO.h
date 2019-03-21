 ///
 /// @file    SocketIO.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-18 17:06:22
 ///
 
#ifndef __WD_SOCKETIO_H__
#define __WD_SOCKETIO_H__

namespace wd
{
class SocketIO
{
public:
	explicit 
	SocketIO(int fd) : _fd(fd){}

	int readn(char * buff, int len);//接收len字节的数据
	int writen(const char * buff, int len);//发送len字节的数据

	int readline(char * buff, int maxlen);//接收一行数据,采用'\n'表示数据的结束
private:
	int recvPeek(char * buff, int len);

private:
	int _fd;
};

}//end of namespace wd


#endif
