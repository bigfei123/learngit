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
pthread_cond_t cond1; //条件变量
bool flag = true;

void * threadFunc1(void *arg)
{
	//线程1-》当flag为true时，执行减一的操作,同时把flag设为false,通知线程2;
	//		  当flag为false时，阻塞挂起，等待条件成立
	int cnt = 10;
	while(cnt--){
		pthread_mutex_lock(&mutex1);
		while(flag == false){ //循环等待,防止意外
			pthread_cond_wait(&cond1, &mutex1);
		}
		
		--gNumber;

		printf("sub thread %ld, gNumber = %ld\n", (uint64_t)pthread_self(), (uint64_t)gNumber);

		if(flag == true)
			flag = false;
		pthread_mutex_unlock(&mutex1);
		//通知其他线程
		pthread_cond_signal(&cond1);
		sleep(1);
	}
	return NULL;
}

void * threadFunc2(void *arg)
{
	//线程2-》当flag为false时，执行减一的操作，同时把flag设为true,通知线程1；
	//		  当flag为true时，阻塞挂起，等待条件成立
	int cnt = 10;
	while(cnt--){
		pthread_mutex_lock(&mutex1);//使用条件变量前，必须进行加锁
		while(flag == true){
			pthread_cond_wait(&cond1, &mutex1); //阻塞,在阻塞的同时解锁,防止死锁
			//如果被其他线程signal之后，当前wait被激活，激活之后首先要进行加锁
		}

		--gNumber;

		printf("sub thread %ld, gNumber = %ld\n", (uint64_t)pthread_self(), (uint64_t)gNumber);
		if(flag == false)
			flag = true;

		pthread_cond_signal(&cond1); //给另外一个线程发信号,唤醒wait方法
		pthread_mutex_unlock(&mutex1);//2>忘记解锁也会造成死锁
		//通知其他线程
		sleep(1);
	}
	return NULL;
}

int main()
{

	pthread_mutex_init(&mutex1, NULL); //初始化互斥锁
	pthread_cond_init(&cond1, NULL); //初始化条件变量

	printf(">>> main thread start running~\n");
	pthread_t pthid1 = 0, pthid2 = 0;//pthread_t线程的标识符,定义线程的id
	pthread_create(&pthid1, NULL, threadFunc1, NULL); //创建线程
	pthread_create(&pthid2, NULL, threadFunc2, NULL); //创建线程
	printf("main thread:%ld\n sub thread1 = %ld\n sub thread2 = %ld\n",
			(uint64_t)pthread_self(), (uint64_t)pthid1,(uint64_t)pthid2);

	pthread_join(pthid1, NULL); //等待线程pthid执行结束，阻塞(线程挂起，不再占用CPU)
	pthread_join(pthid2, NULL); 
	printf(">>> main thread exit!\n");
	pthread_mutex_destroy(&mutex1);
	pthread_cond_destroy(&cond1);
	
	return 0;
}
