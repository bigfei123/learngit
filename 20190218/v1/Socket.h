 ///
 /// @file    Socket.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-18 16:04:23
 ///
 
#ifndef __WD_SOCKET_H__
#define __WD_SOCKET_H__

namespace wd
{

class Socket
{
public:
	Socket();
	explicit Socket(int);

	~Socket();

	int fd() const;
	void nonblock();

	void shutdownWrite();
	
private:
	int _fd;
};

}//end of namespace wd


#endif
