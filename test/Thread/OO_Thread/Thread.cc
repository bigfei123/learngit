 ///
 /// @file    Thread.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-16 19:04:19
 ///
 
#include "Thread.h"
#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;

namespace wd
{

Thread::Thread()
: _pthid(0)
, _isAction(false)
{}

void Thread::start()
{
	pthread_create(&_pthid, NULL, threadFunc, this);
	_isAction = true;
}

void * Thread::threadFunc(void * arg)
{
	//要调用成员函数，必须通过传参的方式将this指针传进来，并进行强制转换为Thread*类型
	Thread * p = static_cast<Thread *>(arg);//static_cast将void*类型转为类类型指针
	if(p)
		p->run();//表现虚函数机制
	return NULL;
}

void Thread::join()
{
	if(_isAction) {
		pthread_join(_pthid, NULL);
		_isAction = false;//如果等待成功，线程执行完毕
	}
}

Thread::~Thread()
{
	if(_isAction) {
		pthread_detach(_pthid);//无论当前线程是否运行，都将资源回收
		_isAction = false;
	}
}

}//end of namespace wd

