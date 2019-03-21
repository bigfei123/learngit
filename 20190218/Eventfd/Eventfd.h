 ///
 /// @file    Eventfd.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-17 10:47:26
 ///
 
#ifndef __WD_TIMER_H__
#define __WD_TIMER_H__

#include <functional>

namespace wd
{

class Eventfd
{
public:
	using EventfdCallback = std::function<void()>;
	Eventfd(EventfdCallback && callback);
	~Eventfd();

	void start();
	void stop();
	void wakeup();
private:
	int createEventfdfd();
	void handleRead();

private:
	int _fd;
	bool _isStarted;
	EventfdCallback _callback;
};

}//end of namespace wd

#endif
