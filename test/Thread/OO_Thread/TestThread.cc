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
 
class MyThread
: public wd::Thread
{
public:
	~MyThread() {	cout << "~MyThread()" << endl;  }
private:
	void run()
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

int test0(void)
{
	cout << "main thread: " << pthread_self() << endl;
	unique_ptr<wd::Thread> mythread(new MyThread());
	mythread->start();
	mythread->join();
	return 0;
}

int main()
{
	test0();
	return 0;
}
