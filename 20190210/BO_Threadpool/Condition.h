 ///
 /// @file    Condition.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-08 21:40:06
 ///
 
#ifndef __WD_CONDITION_H__
#define __WD_CONDITION_H__

#include "Noncopyable.h"
#include <pthread.h>

namespace wd
{

class MutexLock;
class Condition
: Noncopyable
{
public:
	Condition(MutexLock & mutex);
	~Condition();

	void wait();
	void notify();
	void notifyall();

private:
	MutexLock & _mutex;
	pthread_cond_t _cond;
};
}//end of namespace wd

#endif
