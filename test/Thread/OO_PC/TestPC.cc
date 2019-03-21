 ///
 /// @file    TestPC.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-17 13:21:55
 ///
 
#include "Producer.h"
#include "Consumer.h"
#include "TaskQueue.h"
#include <iostream>
#include <stdlib.h>
#include <memory>
#include <unistd.h>
using std::cout;
using std::endl;
using std::unique_ptr;
 
void test0()
{
	cout << "main Thread " << pthread_self() << endl;
	wd::TaskQueue taskque(10);
	unique_ptr<wd::Thread> producer(new wd::Producer(taskque));
	unique_ptr<wd::Thread> consumer(new wd::Consumer(taskque));

	producer->start();
	consumer->start();

	producer->join();
	consumer->join();
}

int main(void)
{
	test0();
	return 0;
}
