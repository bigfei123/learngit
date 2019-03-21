 ///
 /// @file    Condition.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-16 19:32:13
 ///
 
#include "Condition.h"
#include "MutexLock.h"
#include <stdio.h>
#include <errno.h>
namespace wd
{
Condition::Condition(MutexLock& mutex)
: _mutex(mutex)
{
	if(pthread_cond_init(&_cond, NULL)) {
		perror("pthread_cond_init");
	}
}

void Condition::wait()
{
	if(pthread_cond_wait(&_cond, _mutex.getMutexLockptr())) {
		perror("pthread_cond_wait");
	}
}

void Condition::notify()
{
	if(pthread_cond_signal(&_cond)) {
		perror("pthread_cond_signal");
	}
}

void Condition::notifyall()
{
	if(pthread_cond_signal(&_cond)) {
		perror("pthread_cond_signalall");
	}
}
Condition::~Condition()
{
	if(pthread_cond_destroy(&_cond)) {
		perror("pthread_cond_destroy");
	}
}

}//end of namespace wd
