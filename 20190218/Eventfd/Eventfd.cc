 ///
 /// @file    Eventfd.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-17 10:55:04
 ///
 
#include "Eventfd.h"

#include <unistd.h>
#include <errno.h>
#include <poll.h>
#include <sys/eventfd.h>

#include <iostream>
using namespace std;

namespace wd
{

Eventfd::Eventfd(EventfdCallback && callback)
: _fd(createEventfdfd())
, _isStarted(false)
, _callback(std::move(callback))
{

}

Eventfd::~Eventfd()
{
	if(_isStarted){
		stop();
	}
}

//运行在子线程
void Eventfd::start()
{
	struct pollfd pfd;
	pfd.fd = _fd;
	pfd.events = POLLIN;

	_isStarted = true;
	while(_isStarted){
		int ready = ::poll(&pfd, 1, 6000);//定时器结合poll的使用
		if(ready == -1 && errno == EINTR)
			continue;
		else if(ready == -1){
			perror(">> poll");
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

void Eventfd::stop()
{
	if(_isStarted){
		_isStarted = false;
	}
}

void Eventfd::wakeup()
{
	uint64_t one = 1;
	int ret = ::write(_fd, &one, sizeof(one));
	if(ret != sizeof(one)) {
		::perror(">> write");
	}
}

int Eventfd::createEventfdfd()
{
	int fd = ::eventfd(1, 0);
	if(fd == -1){
		perror(">> eventfd_create");
	}
	return fd;
}

void Eventfd::handleRead()
{
	uint64_t howmany = 0;
	//char *howmany = 0;
	int ret = ::read(_fd, &howmany, sizeof(uint64_t));
	if(ret != sizeof(howmany)){
		perror(">>read");
	}
}

}//end of namespace wd
