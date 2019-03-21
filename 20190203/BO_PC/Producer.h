 ///
 /// @file    Producer.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-10 23:13:07
 ///
 
#ifndef _WD_PRODUCER_H__
#define _WD_PRODUCER_H__

#include "TaskQueue.h"

#include <unistd.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
namespace wd
{
class Producer
{
public:
	void produce(TaskQueue & taskque) 
	{
		::srand(::clock());
		int cnt = 20;
		while(cnt--){
			int number = ::rand() % 100;
			taskque.push(number);
			cout << ">> Producer " << pthread_self() << ":"
				 << " produce a number = " << number << endl;
			::sleep(1);
		}
	}
};
}// end of namespace wd

#endif
