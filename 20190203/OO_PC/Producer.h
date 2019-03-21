 ///
 /// @file    Producer.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-10 23:13:07
 ///
 
#ifndef _WD_PRODUCER_H__
#define _WD_PRODUCER_H__

#include "TaskQueue.h"
#include "Thread.h"

#include <stdlib.h>
namespace wd
{
class Producer
: public Thread
{
public:
	Producer(TaskQueue & taskque)
	: _taskque(taskque)
	{}
	
private:
	void run() override
	{
		::srand(::clock());
		int cnt = 20;
		while(cnt--){
			int number = ::rand() % 100;
			_taskque.push(number);
			cout << ">> Producer " << pthread_self() << ":"
				 << " produce a number = " << number << endl;
		}
	}
private:
	TaskQueue & _taskque;
};
}// end of namespace wd

#endif
