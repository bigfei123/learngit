 ///
 /// @file    EventfdThread.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-17 11:16:13
 ///
 
#ifndef __WD_TIMERTHREAD_H__
#define __WD_TIMERTHREAD_H__

#include "Thread.h"
#include "Eventfd.h"

namespace wd
{

class EventfdThread
{
	using EventfdCallback = std::function<void()>;
public:
	EventfdThread(EventfdCallback && cb);
	
	void start();
	void stop();
	void wakeup();

private:
	Eventfd _eventfd;
	Thread _thread;
};

}//end of namesapce wd

#endif
