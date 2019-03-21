 ///
 /// @file    pthreadTest.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-02 14:19:34
 ///
 
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
int gNumber = 1000;

pthread_mutex_t mutex1; //互斥锁

void * threadFunc1(void *arg)
{
	int cnt = 10;
	while(cnt--){
		pthread_mutex_lock(&mutex1);
		--gNumber;
		pthread_mutex_unlock(&mutex1);
		printf("sub thread %ld, gNumber = %ld\n", (uint64_t)pthread_self(), (uint64_t)gNumber);
		sleep(1);
	}
	return NULL;
}

void * threadFunc2(void *arg)
{
	int cnt = 10;
	while(cnt--){
		//pthread_mutex_lock(&mutex1);//1>防止两次加锁造成死锁
		pthread_mutex_lock(&mutex1);
		--gNumber;
		pthread_mutex_unlock(&mutex1);//2>忘记解锁也会造成死锁
		printf("sub thread %ld, gNumber = %ld\n", (uint64_t)pthread_self(), (uint64_t)gNumber);
		sleep(1);
	}
	return NULL;
}

int main()
{
	pthread_mutex_init(&mutex1, NULL); //初始化互斥锁

	printf(">>> main thread start running~\n");
	pthread_t pthid1 = 0, pthid2 = 0;//pthread_t线程的标识符,定义线程的id
	pthread_t pthid3 = 0, pthid4 = 0;
	pthread_create(&pthid1, NULL, threadFunc1, NULL); //创建线程
	pthread_create(&pthid2, NULL, threadFunc1, NULL); //创建线程
	pthread_create(&pthid3, NULL, threadFunc2, NULL); //创建线程
	pthread_create(&pthid4, NULL, threadFunc2, NULL); //创建线程
	printf("main thread:%ld\n sub thread1 = %ld\n sub thread2 = %ld\n sub thread3 = %ld\n sub thread4 = %ld\n",
			(uint64_t)pthread_self(), (uint64_t)pthid1,(uint64_t)pthid2,(uint64_t)pthid3,(uint64_t)pthid4);

	pthread_join(pthid1, NULL); //等待线程pthid执行结束，阻塞(线程挂起，不再占用CPU)
	//while(1);//使用死循环时，还是有CPU的调度，还会占用CPU的时间片
	pthread_mutex_destroy(&mutex1);
	printf(">>> main thread exit!\n");
	return 0;
}
