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
 
class Task 
{
public:
	void process()
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

//以成员函数进行调用
int test0(void)
{
	cout << "main thread : " << pthread_self() << endl;
	Task task;
	unique_ptr<wd::Thread> mythread(new wd::Thread(
		std::bind(&Task::process, &task)
	));
	mythread->start();
	mythread->join(); //等待线程执行完毕
	return 0;
}

void process()
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

//以普通函数进行调用
void test1()
{
	cout << "main thread : " << pthread_self() << endl;
	wd::Thread mythread(std::bind(process));
	mythread.start();
	mythread.join();

	//复制构造函数被delete
	//MyThread mythread2(mythread);//error 用户态禁止复制进程
}

int main()
{
	//test0();
	test1();
	return 0;
}
