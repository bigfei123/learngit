 ///
 /// @file    Consumer.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-17 13:17:03
 ///

#ifndef __CONSUMER_H__
#define __CONSUMER_H__

#include "TaskQueue.h"
#include "Thread.h"
#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;

namespace wd
{

class Consumer
{
public:
	void consume(TaskQueue & taskque) 
	{
		int cnt = 10;
		while(cnt--) {
			int number = taskque.pop();
			cout << ">> Consumer  " << pthread_self()
				 << ": consumer a number = " << number << endl;
			sleep(1);
		}
	}
};

}//end of namespace wd

#endif
