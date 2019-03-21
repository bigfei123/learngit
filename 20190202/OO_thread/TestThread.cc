 ///
 /// @file    TestThread.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-02 22:41:56
 ///
 
#include "Thread.h"
#include <iostream>
#include <stdlib.h> //srand(clock());设置种子
#include <memory>
#include <unistd.h> //sleep()
using std::cout;
using std::endl;
using std::unique_ptr;
 
class MyThread
: public wd::Thread
{
public:
	~MyThread() {	cout << "~MyThread() " << endl;}
private:
	void run()
	{
		int cnt = 10;
		::srand(::clock());
		while(cnt--){
			int number = ::rand() % 100;
			cout << "sub Thread" << pthread_self() 
			     << ": getnumber = " << number << endl;
			::sleep(1);
		}
	}
};

int test0(void)
{
	cout << "main thread : " << pthread_self() << endl;
	unique_ptr<wd::Thread> mythread(new MyThread());
	mythread->start();
	mythread->join(); //等待线程执行完毕
	return 0;
}

void test1()
{
	cout << "main thread : " << pthread_self() << endl;
	MyThread mythread;
	mythread.start();
	mythread.join();

	//复制构造函数被delete
	//MyThread mythread2(mythread);//error 用户态禁止复制进程
}

int main()
{
	test0();
	//test1();
	return 0;
}
