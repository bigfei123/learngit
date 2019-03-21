 ///
 /// @file    Thread.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-02 22:13:29
 ///
 
#ifndef __THREAD_H__
#define __THREAD_H__
#include <iostream>
#include <pthread.h>
#include "Noncopyable.h"
#include <functional>
using std::cout;
using std::endl;
 
namespace wd 
{

class Thread
: Noncopyable 
{//具有对象语义的类==》不能被复制
public:
	using ThreadCallback = std::function<void()>;
	Thread(ThreadCallback && callback);

	~Thread();
	void start(); //开启子线程
	void join(); //回收子线程

	bool isRunning() const {	return _isRunning;	}
	pthread_t getThreadid() const {	return _pthid;	}
private:
	//threadFunc成员函数参数列表里隐含this指针,无法满足pthread_create函数条件
	//设置为static,消除this指针
	static void * threadFunc(void *);

private:
	ThreadCallback _callback; //回调函数,线程即将要执行的任务
	pthread_t _pthid;
	bool _isRunning;//判断当前线程是否运行
};

}//end of namespace wd

#endif
