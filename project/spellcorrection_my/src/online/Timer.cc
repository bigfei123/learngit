 ///
 /// @file    Timer.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-17 10:55:04
 ///
 
#include "../../include/online/Timer.h"
#include "../../include/online/Mylogger.h"

#include <unistd.h>
#include <errno.h>
#include <poll.h>
#include <netinet/in.h>
#include <sys/timerfd.h>

#include <iostream>
using namespace std;

namespace online
{

Timer::Timer(TimerCallback && callback, int initialTime, int periodicTime)
: _fd(createTimerfd())
, _initialTime(initialTime)
, _periodicTime(periodicTime)
, _callback(move(callback))
, _isStarted(false)
{

}

Timer::~Timer()
{
	if(_isStarted){
		stop();
	}
}

void Timer::start()
{
	struct pollfd pfd;
	pfd.fd = _fd;
	pfd.events = POLLIN;

	_isStarted = true;
	setTimerfd(_initialTime, _periodicTime);

	while(_isStarted){
		int ready = ::poll(&pfd, 1, 6000);//定时器结合poll的使用
		if(ready == -1 && errno == EINTR)
			continue;
		else if(ready == -1){
			perror(">> poll");
			LogError("poll error");
			exit(EXIT_FAILURE);
		}else if(ready == 0){
			cout << ">> poll timeout!" << endl;
		}else {
			if(pfd.fd == _fd && (pfd.revents & POLLIN)){
				//对读事件进行处理,否则会一直循环输出
				handleRead();
				//执行任务
				if(_callback)
					_callback();
			}
		}
	}
}

void Timer::stop()
{
	if(_isStarted){
		_isStarted = false;
		setTimerfd(0, 0);
	}
}

int Timer::createTimerfd()
{
	int fd = ::timerfd_create(CLOCK_REALTIME, 0);
	if(fd == -1){
		perror(">> timerfd_create");
		LogError("timerfd_create error");
	}
	return fd;
}

void Timer::setTimerfd(int initialTime, int periodicTime)
{
	struct itimerspec value;
	value.it_value.tv_sec = initialTime;
	value.it_value.tv_nsec = 0;
	value.it_interval.tv_sec = periodicTime;
	value.it_interval.tv_nsec = 0;
 
	int ret = ::timerfd_settime(_fd, 0, &value, nullptr);
	if(ret == -1){
		perror(">> timerfd_settime");
		LogError("timerfd_settime error");
	}
}

void Timer::handleRead()
{
	uint64_t howmany = 0;
	int ret = ::read(_fd, &howmany, sizeof(uint64_t));
	if(ret != sizeof(howmany)){
		perror(">>read");
		LogError("read error");
	}
}

}//end of namespace online
