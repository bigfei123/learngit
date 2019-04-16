 ///
 /// @file    TimerTest.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-17 11:22:58
 ///
 
#include "TimerThread.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

struct Example
{
	void process() {
		::srand(::clock());
		int number = ::rand() % 100;
		cout << "number = " << number << endl;
	}
};

//int main(void)
//{
//	cout << ">>> main thread: " << pthread_self() << endl;
//	wd::Timer timer(std::bind(&Example::process, Example()), 3, 5);
//	wd::Thread thread(std::bind(&wd::Timer::start, &timer));
//	thread.start();
//	cout << ">>> main thread: sub thread start running a timer..." << endl;
//	cout << ">>> main thread sleep..." << endl;
//	sleep(14);
//	cout << ">>> main thread wakeup..." << endl;
//	cout << ">>> main thread stop timer..." << endl;
//	timer.stop();
//	thread.join();
//	return 0;
//} 


int main(void)
{
	//将start(),  stop()方法分别放入子线程和主线程中,避免程序无法结束
	//主线程等待15s后执行stop(),结束定时
	cout << ">>> main thread" << pthread_self() << endl;
	wd::TimerThread timer(std::bind(&Example::process, Example()), 3, 5);
	timer.start(); //应该让其在子线程中执行
	cout << ">>> main thread: sub thread start running a timer..." << endl;
	cout << ">>> main thread sleep..." << endl;
	sleep(15);
	cout << ">>> main thread wakeup..." << endl;
	cout << ">>> main thread stop timer..." << endl;
	timer.stop(); //在主线程中执行
	return 0;
}
 
