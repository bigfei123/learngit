 ///
 /// @file    MutexLock.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-08 21:28:51
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
	{	return & _mutex; }
private:
	pthread_mutex_t _mutex;
};
}//end of namesapace wd

#endif
