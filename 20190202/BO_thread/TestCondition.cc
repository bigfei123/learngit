 ///
 /// @file    pthreadTest.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-02 14:19:34
 ///
 
#include "Thread.h"
#include "MutexLock.h"
#include "Condition.h"

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::unique_ptr;
 
class Example
{
public:
	//初始化全局变量、互斥锁、条件变量
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
	//线程1-》当flag为true时，执行减一的操作,同时把flag设为false,通知线程2;
	//		  当flag为false时，阻塞挂起，等待条件成立
	int cnt = 10;
	while(cnt--){
		wd::MutexLockGuard autolock(_mutex);
		while(_flag == false){ //循环等待,防止意外
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
	//线程2-》当flag为false时，执行减一的操作，同时把flag设为true,通知线程1；
	//		  当flag为true时，阻塞挂起，等待条件成立
	int cnt = 10;
	while(cnt--){
		wd::MutexLockGuard autolock(_mutex);
		while(_flag == true){
			//pthread_cond_wait(&cond1, &mutex1); //阻塞,在阻塞的同时解锁,防止死锁
			_cond.wait();
			//如果被其他线程signal之后，当前wait被激活，激活之后首先要进行加锁
		}

		--_number;

		printf("sub thread %ld, gNumber = %ld\n", (uint64_t)pthread_self(), (uint64_t)_number);
		if(_flag == false)
			_flag = true;

		//通知其他线程
		_mutex.unlock();
		_cond.notify();
		sleep(1);
	}
}

int main()
{

	printf(">>> main thread start running~\n");
	Example example;
	
	unique_ptr<wd::Thread> thread1(new wd::Thread(
		std::bind(&Example::executetask1, &example)
	));
	
	unique_ptr<wd::Thread> thread2(new wd::Thread(
		std::bind(&Example::executetask2, &example)
	));

	thread1->start();
	thread2->start();

	printf("main thread: %ld, sub threadid = %ld, %ld\b",
			(uint64_t)pthread_self(),
			(uint64_t)thread1->getThreadid(),
			(uint64_t)thread2->getThreadid());

	thread1->join();
	thread2->join();

	printf(">> main thread exit!\n");
	return 0;
}
