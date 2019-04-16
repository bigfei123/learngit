 ///
 /// @file    SpellcorrectServer.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-23 12:42:10
 ///
 
#ifndef __ONLINE_SPELLCORRECTSERVER_H__
#define __ONLINE_SPELLCORRECTSERVER_H__

#include "Server.h"

namespace online
{

class SpellcorrectServer
: public Server
{
public:
	SpellcorrectServer();
	void start();

private:
	void onConnection(const TcpConnectionPtr &);
	void onMessage(const TcpConnectionPtr &);
	void onClose(const TcpConnectionPtr &);
};

}//end of namespace online


#endif
