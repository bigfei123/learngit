 ///
 /// @file    TestPC.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-17 13:21:55
 ///
 
#include "Producer.h"
#include "Consumer.h"
#include "Thread.h"

#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;
using namespace wd;
 
void test0()
{
	cout << "main Thread " << pthread_self() << endl;
	wd::TaskQueue taskque(10);
	unique_ptr<Thread> producer(new Thread(
		std::bind(&Producer::produce, Producer(), std::ref(taskque)
	)));				//传递taskque的引用，目的是防止复制，使之操作同一对象
	unique_ptr<Thread> consumer(new Thread(
		std::bind(&Consumer::consume, Consumer(), std::ref(taskque)
	)));

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
