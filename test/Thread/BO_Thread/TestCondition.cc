 ///
 /// @file    TestCondition.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-16 20:26:30
 ///
 
#include "Thread.h"
#include "MutexLock.h"
#include "Condition.h"

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#include <memory>
#include <iostream>
using std::cout;
using std::endl;
using std::unique_ptr;
 
class Example
{
public:
	Example()
	: _number(1000)
	, _flag(true)
	, _mutex()
	, _cond(_mutex)
	{}
	void executetask1();
	void executetask2();

private:
	int _number;
	bool _flag;
	wd::MutexLock _mutex;
	wd::Condition _cond;
};

void Example::executetask1()
{
	int cnt = 10;
	while(cnt --) {
		wd::MutexLockGuard autolock(_mutex);
		while(_flag == false) {
			_cond.wait();
		}

	--_number;
	
	printf("sub thread %ld, gNumber = %ld\n", (uint64_t)pthread_self(), (uint64_t)_number);

	if(_flag == true)
		_flag = false;
	_mutex.unlock();
	_cond.notify();
	sleep(1);
	}
}

void Example::executetask2()
{
	int cnt = 10;
	while(cnt --) {
		wd::MutexLockGuard autolock(_mutex);
		while(_flag == true) {
			_cond.wait();
		}

		--_number;
	
		printf("sub thread %ld, gNumber = %ld\n", (uint64_t)pthread_self(), (uint64_t)_number);
	
		if(_flag == true)
			_flag = false;
		_mutex.unlock();
		_cond.notify();
		sleep(1);
	}
}

int main()
{
	printf(">>> main thread start running ~\n");
	Example example;

	unique_ptr<wd::Thread> thread1(new wd::Thread(
		std::bind(&Example::executetask1, &example)
	));

	unique_ptr<wd::Thread> thread2(new wd::Thread(
		std::bind(&Example::executetask2, &example)
	));

	thread1->start();
	thread2->start();

	printf("main thread: %ld sub threadid = %ld, %ld\b",
			(uint64_t)pthread_self(),
			(uint64_t)thread1->getThreadid(),
			(uint64_t)thread2->getThreadid());
	thread1->join();
	thread2->join();

	printf(">> main thread exit!\n");
}

