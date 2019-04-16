 ///
 /// @file    SpellcorrectServer.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-23 13:10:28
 ///
 
#include "../../include/online/Configuration.h"
#include "../../include/online/SpellcorrectServer.h"
#include "../../include/online/MyTask.h"
#include <iostream>
using std::endl;
using std::cout;

namespace online
{

SpellcorrectServer::SpellcorrectServer()
: Server(getConfig("ip"),
		 atoi(getConfig("port").c_str()),
		 atoi(getConfig("listenFdNum").c_str()),
		 atoi(getConfig("threadNum").c_str()),
		 atoi(getConfig("taskQueueSize").c_str()))
{}

void SpellcorrectServer::start()
{
	_threadpool.start();
	_tcpServer.setConnectionCallback(std::bind(&SpellcorrectServer::onConnection, this));
	_tcpServer.setMessageCallback(std::bind(&SpellcorrectServer::onMessage, this));
	_tcpServer.setCloseCallback(std::bind(&SpellcorrectServer::onClose, this));

	_tcpServer.start();
}

void SpellcorrectServer::onConnection(const TcpConnectionPtr & conn)
{
	cout << conn->toString() << std::endl;
	conn->send("hello, welcome to SpellcorrectServer server. \r\n");
}

void SpellcorrectServer::onMessage(const TcpConnectionPtr & conn)
{
	std::string s(conn->receive());
	MyTask task(s, conn);//在IO线程中，将任务的执行交给线程池处理
	_threadpool.addTask(std::bind(&MyTask::excute(), task));
	cout << ">>> add task to _threadpool" << endl;
}

void SpellcorrectServer::onClose(const TcpConnectionPtr & conn)
{
	cout << conn->toString() << " close" << endl;
}

}//end of namespace online

