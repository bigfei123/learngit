 ///
 /// @file    Socket.h
 /// @author  bigfei775655478@qq.com
 /// @date    2019-02-18 16:04:23
 ///
 
#ifndef __WD_SOCKET_H__
#define __WD_SOCKET_H__
#include "Noncopyable.h"

namespace online
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
