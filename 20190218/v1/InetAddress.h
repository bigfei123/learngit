 ///
 /// @file    InetAddress.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-18 15:51:22
 ///
 
#ifndef __WD_INETADDRESS_H__
#define __WD_INETADDRESS_H__
#include <netinet/in.h>
#include <string>

using std::string;


namespace wd
{

class InetAddress
{
public:
	InetAddress(const string & ip, unsigned short port);
	InetAddress(unsigned short port);
	InetAddress(const struct sockaddr_in & addr)
	: _addr(addr)
	{}

	string ip() const;
	unsigned short port() const;
	struct sockaddr_in * getSockaddrPtr() {	return &_addr;	}

	
private:
	struct sockaddr_in _addr;
};

}//end of namespace wd

#endif

