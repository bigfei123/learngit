 ///
 /// @file    TimerThread.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-17 11:16:13
 ///
 
#ifndef __WD_TIMERTHREAD_H__
#define __WD_TIMERTHREAD_H__

#include "Thread.h"
#include "Timer.h"

namespace wd
{

class TimerThread
{
	using TimerCallback = std::function<void()>;
public:
	TimerThread(TimerCallback && cb, int initialTime, int periodicTime);
	
	void start();
	void stop();

private:
	Timer _timer;
	Thread _thread;
};

}//end of namesapce wd

#endif
