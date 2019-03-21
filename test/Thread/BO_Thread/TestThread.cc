 ///
 /// @file    TestThread.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-16 19:38:47
 ///
 
#include "Thread.h"
#include <stdlib.h> //srand(clock())
#include <memory>
#include <unistd.h> //sleep()
#include <iostream>
using std::cout;
using std::endl;
using std::unique_ptr;
 
class Task
{
public:
	void process()
	{
		int cnt = 10;
		::srand(::clock());
		while(cnt --) {
			int number = ::rand() % 100;
			cout << "sub Thread" << pthread_self()
				 << ": getnumber = " << number << endl;
			::sleep(1);
		}
	}
};

void test0()
{
	cout << "main thread: " << pthread_self() << endl;
	Task task;
	unique_ptr<wd::Thread> mythread(new wd::Thread(
		std::bind(&Task::process, &task)
	));
	mythread->start();
	mythread->join();
}

void process()
{
	int cnt = 10;
	::srand(::clock());
	while(cnt --) {
		int number = ::rand() % 100;
		cout << "sub Thread" << pthread_self()
			 << ": getnumber = " << number << endl;
		::sleep(1);
	}
}

void test1()
{
	cout << "main thread: " << pthread_self() << endl;
	wd::Thread mythread(process);
	mythread.start();
	mythread.join();
}

int main()
{
	test0();
	test1();
	return 0;
}
