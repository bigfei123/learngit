 ///
 /// @file    Consumer.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-10 23:19:03
 ///
 
#ifndef __WD_CONSUMER_H__
#define __WD_CONSUMER_H__

#include "Thread.h"
#include "TaskQueue.h"

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
		int cnt = 20;
		while(cnt--){
			int number = _taskque.pop();
			cout << ">> consumer " << pthread_self()
				 << " : consume a number = " << number << endl;
		}
	}

private:
	TaskQueue & _taskque;
};
}//end of namspace wd




#endif