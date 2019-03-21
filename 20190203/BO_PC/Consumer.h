 ///
 /// @file    Consumer.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-10 23:19:03
 ///
 
#ifndef __WD_CONSUMER_H__
#define __WD_CONSUMER_H__

#include "TaskQueue.h"
#include <iostream>
using namespace std;

namespace wd
{
class Consumer
{
public:
	void consume(TaskQueue & taskque) 
	{
		int cnt = 20;
		while(cnt--){
			int number = taskque.pop();
			cout << ">> consumer " << pthread_self()
				 << " : consume a number = " << number << endl;
		}
	}
};
}//end of namspace wd

#endif
