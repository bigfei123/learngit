 ///
 /// @file    pthread.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-21 21:10:05
 ///
 
#ifndef __ONLINE__PTHREAD_H__
#define __ONLINE__PTHREAD_H__

#include "Noncopyable.h"
#include <pthread.h>
#include <string>
#include <functional>

namespace online
{

class Thread
: private Noncopyable
{
public:
	using ThreadCallback = std::function<void()>;
	Thread(ThreadCallback && callback);

	~Thread();
	void start(); 
	void join();
	bool isRunning() const {	return _isRunning;   }
	pthread_t getThreadid() const  {  return _pthid; }

private:
	static void * threadFunc(void *);

private:
	pthread_t _pthid;
	bool _isRunning;
	ThreadCallback _callback;
};

}//end of namespace online

#endif
