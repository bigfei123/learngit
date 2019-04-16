 ///
 /// @file    MutexLock.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-08 21:28:51
 ///
 
#ifndef __ONLINE_MUTEXLOCK_H__
#define __ONLINE_MUTEXLOCK_H__

#include "Noncopyable.h"
#include <pthread.h> 

namespace online 
{

class MutexLock
: private Noncopyable
{
public:
	MutexLock();
	~MutexLock();
	void lock();
	void unlock();
	
	pthread_mutex_t * getMutexLockptr()
	{	return & _mutex; }
private:
	pthread_mutex_t _mutex;
};

class MutexLockGuard
{
public:
	MutexLockGuard(MutexLock & mutex)
	: _mutex(mutex)
	{
		_mutex.lock();
	}

	~MutexLockGuard()
	{
		_mutex.unlock();
	}
private:
	MutexLock & _mutex;
};


}//end of namesapace wd

#endif
