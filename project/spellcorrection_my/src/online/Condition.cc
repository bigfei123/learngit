 ///
 /// @file    Condition.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-08 21:43:22
 ///
 
#include "../../include/online/Condition.h"
#include "../../include/online/MutexLock.h"
#include <stdio.h>
#include <errno.h>
namespace online
{
Condition::Condition(MutexLock& mutex)
: _mutex(mutex)
{
	if(pthread_cond_init(&_cond,NULL)){
		perror("pthread_cond_init");
	}
}

void Condition::wait()
{
	if(pthread_cond_wait(&_cond, _mutex.getMutexLockptr())){
		perror("pthread_cond_wait");
	}
}

void Condition::notify()
{
	if(pthread_cond_signal(&_cond)){
		perror("pthread_cond_signal");
	}
}

void Condition::notifyall()
{
	if(pthread_cond_broadcast(&_cond)){
		perror("pthread_cond_broadcast");
	}
}

Condition::~Condition()
{
	if(pthread_cond_destroy(&_cond))
	{
		perror("pthread_cond_destroy");
	}
}

}//end of namespace wd
