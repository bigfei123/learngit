 ///
 /// @file    Producer.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-17 13:12:21
 ///

#ifndef _PRODUCER_H__
#define _PRODUCER_H__

#include "TaskQueue.h"
#include "Thread.h"
#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;

namespace wd
{

class Producer
{
public:
	void produce(TaskQueue & taskque)
	{
		::srand(::clock());
		int cnt = 10;
		while(cnt--) {
			int number = ::rand() % 100;
			taskque.push(number);
			cout << ">> Producer " << pthread_self() << ":"
				 << " produce a number = " << number << endl;
			sleep(1);
		}
	}
	
};

}//end of namespace wd

#endif
