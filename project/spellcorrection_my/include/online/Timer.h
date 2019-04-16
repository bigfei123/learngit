 ///
 /// @file    Timer.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-17 10:47:26
 ///
 
#ifndef __WD_TIMER_H__
#define __WD_TIMER_H__

#include <functional>

namespace online
{

class Timer
{
public:
	using TimerCallback = std::function<void()>;
	Timer(TimerCallback && callback, int initialTime, int peoriodicTime);
	~Timer();

	void start();
	void stop();
private:
	int createTimerfd();
	void setTimerfd(int initialTime, int periodicTime);
	void handleRead();

private:
	int _fd;
	int _initialTime;
	int _periodicTime;
	TimerCallback _callback;
	bool _isStarted;

};

}//end of namespace wd

#endif
