 ///
 /// @file    TestConnection.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-18 18:22:17
 ///
 
#include "TcpConnection.h"
#include "TcpServer.h"

#include <unistd.h>
#include <memory>
#include <iostream>
using std::cout;
using std::endl;
using std::shared_ptr;
using namespace wd;

class MyTask
{
public:
	MyTask(const string & request, shared_ptr<TcpConnection> conn)
	: _request(request)
	, _conn(conn)
	{}

	//process方法是线程池中的子线程来执行的
	void process()
	{
		//...do something
		//decode compute encode
		string response = doTask();//业务逻辑处理

		//_conn->send(response);//不能直接发送,因为现在处于计算线程,不是IO线程
		//这里涉及到线程间通信：计算线程要通知IO线程发送数据
	}


	string doTask();
private:
	string _request;
	shared_ptr<TcpConnection> _conn;
};

void onConnection(const shared_ptr<wd::TcpConnection> & conn)
{
	cout << ">>> " << conn->toString() << " has connected!" << endl;
}

void onMessage(const shared_ptr<wd::TcpConnection> & conn)
{
	string msg = conn->receive();
	cout << ">>> server receive:" << msg << endl;
	//do something //处理的事件不宜过长(1ms, 1us, 1ns)
	//
	//decode
	//compute  当处理业务逻辑的时间过长时,必须引入线程池
	//encode
	//MyTask task(msg);
	//pthreadpool->addTask(std::bind(&MyTask::process, task));
	conn->send(msg);//不能再直接发送数据了
}

void onClose(const shared_ptr<wd::TcpConnection> & conn)
{
	cout << ">>> " << conn->toString() << " has closed!" << endl;
}


void test0(void)
{
	wd::TcpServer server("192.168.31.128", 8888);
	server.setConnectionCallback(onConnection);
	server.setMessageCallback(onMessage);
	server.setCloseCallback(onClose);
	
	server.start();
}
 
int main(void)
{
	test0();
	return 0;
}
