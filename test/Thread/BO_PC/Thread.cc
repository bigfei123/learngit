 ///
 /// @file    Thread.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-02 22:18:27
 ///
 
#include "Thread.h"
#include <iostream>
namespace wd
{

Thread::Thread(ThreadCallback && callback)
: _pthid(0)
, _isRunning(false)
, _callback(callback)
{}

void Thread::start()
{
	//
	pthread_create(&_pthid, NULL, threadFunc, this);
	_isRunning = true;
}

void * Thread::threadFunc(void *arg)
{
	//要调用成员函数,必须通过传参的方式将this传进来,并进行强制转换为Thread*类型
	Thread *p = static_cast<Thread *>(arg);
	if(p)
		p->_callback();//表现虚函数机制
	return NULL;
}

void Thread::join()
{
	if(_isRunning){
		pthread_join(_pthid, NULL);
		_isRunning = false;//如果等待成功，线程执行完毕
	}
}

Thread::~Thread()
{
	if(_isRunning){
		pthread_detach(_pthid);//无论当前线程是否运行，都将资源回收
		_isRunning = false; 
	} 
}



}//end of namespace wd
