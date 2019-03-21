 ///
 /// @file    MutexLock.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-16 19:16:52
 ///
 
#ifndef __WD_MUTEXLOCK_H__
#define __WD_MUTEXLOCK_H__

#include "Noncopyable.h"
#include <pthread.h>

namespace wd
{
class MutexLock
: Noncopyable
{
public:
	MutexLock();
	~MutexLock();
	void lock();
	void unlock();

	pthread_mutex_t * getMutexLockptr()
	{	return & _mutex;	}
		
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

}//end of namespace wd

#endif
