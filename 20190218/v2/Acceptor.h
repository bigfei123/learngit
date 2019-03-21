 ///
 /// @file    Acceptor.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-18 16:21:18
 ///
 
#ifndef __WD_ACCEPTOR_H__
#define __WD_ACCEPTOR_H__
#include "Socket.h"
#include "InetAddress.h"

namespace wd
{

class Acceptor
{
public:
	Acceptor(const string & ip, unsigned short port);
	Acceptor(unsigned short port);

	void ready();
	int accept();
	int fd() const;

private:
	void setReuseAddr();
	void setReusePort();
	void bind();
	void listen();

private:
	Socket _sock;
	InetAddress _addr;
};

}//end of namespace wd


#endif
