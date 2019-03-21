 ///
 /// @file    TcpConnection.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-18 16:40:22
 ///

#ifndef __WD_TCPCONNECTION_H__
#define __WD_TCPCONNECTION_H__
#include "Socket.h"
#include "InetAddress.h"
#include "SocketIO.h"

#include <string>
using std::string;

namespace wd
{

class TcpConnection
{
public:
	explicit
	TcpConnection(int peerfd);
	~TcpConnection();

	string receive();
	void send(const string & msg);
	void shutdown();

	string toString() const;
private:
	InetAddress localInetAddr();
	InetAddress peerInetAddr();

private:
	Socket		_sock;
	InetAddress _localAddr;
	InetAddress _peerAddr;
	SocketIO    _socketIO;
	bool        _isShutdownWrite;
};

}


#endif
