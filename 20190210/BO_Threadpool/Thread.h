 ///
 /// @file    Thread.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-02 22:13:29
 ///
 
#ifndef __THREAD_H__
#define __THREAD_H__
#include <iostream>
#include <functional>
#include <pthread.h>
#include "Noncopyable.h"
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

	static void * threadFunc(void *);

private:
	pthread_t _pthid;
	bool _isRunning;//判断当前线程是否运行
	ThreadCallback _callback;
};

}//end of namespace wd

#endif
