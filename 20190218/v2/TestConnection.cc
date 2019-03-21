 ///
 /// @file    TestConnection.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-18 18:22:17
 ///
 
#include "Acceptor.h"
#include "EventLoop.h"

#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;

void test0(void)
{
	wd::Acceptor acceptor("192.168.31.128", 8888);
	acceptor.ready();

	wd::EventLoop loop(acceptor);
	loop.loop();

#if 0
	int peerfd = acceptor.accept();
	wd::TcpConnection conn(peerfd);
	cout << conn.toString() << " has connected!" << endl;

	string msg = conn.receive();
	cout << ">> server receive: " << msg << endl;
	conn.send(msg);
	::sleep(2);
#endif
}
 
int main(void)
{
	test0();
	return 0;
}
