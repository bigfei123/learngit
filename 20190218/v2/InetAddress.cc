 ///
 /// @file    InetAddress.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-18 15:56:10
 ///
 
#include "InetAddress.h"

#include <string.h>
#include <arpa/inet.h>

namespace wd
{
InetAddress::InetAddress(const string & ip, unsigned short port)
{
	::memset(&_addr, 0, sizeof(struct sockaddr_in));
	_addr.sin_family = AF_INET;
	_addr.sin_port = htons(port);
	_addr.sin_addr.s_addr = inet_addr(ip.data());
}

InetAddress::InetAddress(unsigned short port)
{
	::memset(&_addr, 0, sizeof(struct sockaddr_in));
	_addr.sin_family = AF_INET;
	_addr.sin_port = htons(port);
	_addr.sin_addr.s_addr = INADDR_ANY;//代表本机地址
}

string InetAddress::ip() const
{
	return	string(inet_ntoa(_addr.sin_addr));
}
	
unsigned short InetAddress::port() const
{
	return ntohs(_addr.sin_port);
}


}//end of namespace wd
