 ///
 /// @file    Consumer.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-17 13:17:03
 ///

#ifndef __CONSUMER_H__
#define __CONSUMER_H__

#include "TaskQueue.h"
#include "Thread.h"

namespace wd
{

class Consumer
: public Thread
{
public:
	Consumer(TaskQueue & taskque)
	: _taskque(taskque)
	{}

private:
	void run() override
	{
		int cnt = 10;
		while(cnt--) {
			int number = _taskque.pop();
			cout << ">> Consumer  " << pthread_self()
				 << ": consumer a number = " << number << endl;
		}
	}
private:
	TaskQueue & _taskque;
};

}//end of namespace wd

#endif
