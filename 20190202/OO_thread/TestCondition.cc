 ///
 /// @file    pthreadTest.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-02 14:19:34
 ///
 
#include "MutexLock.h"
#include "Condition.h"

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#include <iostream>
using std::cout;
using std::endl;
 
//线程的执行在进程的空间里面
//
//如果当进程执行结束时，线程也无法执行
//
//线程有各自的栈空间

//全局变量，临界资源,采用互斥访问

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
	int			  _number;
	bool		  _flag;
	wd::MutexLock _mutex;
	wd::Condition _cond;
};

void Example::executetask1()
{
	//线程1-》当flag为true时，执行减一的操作,同时把flag设为false,通知线程2;
	//		  当flag为false时，阻塞挂起，等待条件成立
	int cnt = 100;
	while(cnt--){
		//pthread_mutex_lock(&mutex1);
		_mutex.lock();
		while(_flag == false){ //循环等待,防止意外
			//pthread_cond_wait(&cond1, &mutex1);
			_cond.wait();
		}
		
		--_number;

		printf("sub thread %ld, gNumber = %ld\n", (uint64_t)pthread_self(), (uint64_t)_number);

		if(_flag == true)
			_flag = false;
		//pthread_mutex_unlock(&mutex1);
		_mutex.unlock();
		_cond.notify();
		//pthread_cond_signal(&cond1);
		sleep(1);
	}
}

void Example::executetask2()
{
	//线程2-》当flag为false时，执行减一的操作，同时把flag设为true,通知线程1；
	//		  当flag为true时，阻塞挂起，等待条件成立
	int cnt = 100;
	while(cnt--){
		//pthread_mutex_lock(&mutex1);//1>防止两次加锁造成死锁
		//pthread_mutex_lock(&mutex1);//使用条件变量前，必须进行加锁
		_mutex.lock();
		while(_flag == true){
			//pthread_cond_wait(&cond1, &mutex1); //阻塞,在阻塞的同时解锁,防止死锁
			_cond.wait();
			//如果被其他线程signal之后，当前wait被激活，激活之后首先要进行加锁
		}

		--_number;

		printf("sub thread %ld, gNumber = %ld\n", (uint64_t)pthread_self(), (uint64_t)_number);
		if(_flag == false)
			_flag = true;

		_cond.notify();
		_mutex.unlock();
		//pthread_cond_signal(&cond1); //给另外一个线程发信号,唤醒wait方法
		//pthread_mutex_unlock(&mutex1);//2>忘记解锁也会造成死锁
		//通知其他线程
		sleep(1);
	}
}

//面向对象不好实现
int main()
{
	printf(">>> main thread start running~\n");
	Example example;


	//在linux里面，线程的本质其实还是一个进程=》struct task_struct{}

	pthread_t pthid1 = 0, pthid2 = 0;

	pthread_create(&pthid1, NULL, threadFunc1, NULL); //创建线程
	pthread_create(&pthid2, NULL, threadFunc2, NULL); //创建线程
	printf("main thread:%ld, sub thread1 = %ld, sub thread2 = %ld\n",
			(uint64_t)pthread_self(), (uint64_t)pthid1,(uint64_t)pthid2);

	pthread_join(pthid1, NULL); //等待线程pthid执行结束，阻塞(线程挂起，不再占用CPU)
	pthread_join(pthid2, NULL); 
	printf(">>> main thread exit!\n");

	pthread_cond_destroy(&cond1);
	return 0;
}
