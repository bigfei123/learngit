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
#include "Noncopyable.h"

#include <string>
#include <memory>
#include <functional>
using std::string;
using std::function;
using std::shared_ptr;

namespace wd
{

class EventLoop;
class TcpConnection
: Noncopyable
, public std::enable_shared_from_this<TcpConnection>
{
public:
	using TcpConnectionCallback = std::function<void(const std::shared_ptr<TcpConnection>&)>;

	explicit
	//TcpConnection(int peerfd, EventLoop & loop);
	TcpConnection(int peerfd);
	~TcpConnection();

	string receive();
	void send(const string & msg);
	void shutdown();

	bool isClosed();
	string toString() const;

	void setConnectionCallback(TcpConnectionCallback && cb)
	{	_onConnectionCallback = std::move(cb);	}

	void setMessageCallback(TcpConnectionCallback && cb)
	{	_onMessageCallback = std::move(cb);	}

	void setCloseCallback(TcpConnectionCallback && cb)
	{	_onCloseCallback = std::move(cb);	}

	void handleConnectionCallback();
	void handleMessageCallback();
	void handleCloseCallback();
private:
	InetAddress localInetAddr();
	InetAddress peerInetAddr();

private:
	Socket		_sock;
	InetAddress _localAddr;
	InetAddress _peerAddr;
	SocketIO    _socketIO;
	bool        _isShutdownWrite;
	TcpConnectionCallback _onConnectionCallback;
	TcpConnectionCallback _onMessageCallback;
	TcpConnectionCallback _onCloseCallback;
	//EventLoop & _loop;
};

}

#endif
