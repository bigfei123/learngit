 ///
 /// @file    TestThread.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-02 22:41:56
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
	cout << " main Thread" << pthread_self() << endl;
	wd::TaskQueue taskque(5);//队列最多存放是个元素,而生产者要生产20个元素,故无法一次执行完毕
	unique_ptr<wd::Thread> producer(new wd::Thread(
		std::bind(&Producer::produce, Producer(), std::ref(taskque))
									//匿名对象表示this指针
									//taskque使用的是值传递,会调用复制构造函数
									//而应该使用std::ref传递非const引用
	));
	unique_ptr<wd::Thread> consumer(new wd::Thread(
		std::bind(&Consumer::consume, Consumer(), std::ref(taskque))
	));

	producer->start();
	consumer->start();

	producer->join();
	consumer->join();
}


int main()
{
	test0();
	return 0;
}
