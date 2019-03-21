 ///
 /// @file    TestThreadpool.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-17 15:36:41
 ///
 
#include "Threadpool.h"
#include <unistd.h>
#include <stdlib.h>
#include <memory>
#include <iostream>
using std::cout;
using std::endl;
using namespace wd;
 
class MyTask
: public Task
{
public:
	void process()
	{
		::srand(::time(NULL));
		int number = ::rand() % 100;
		cout << "pthid " << pthread_self() << ", number = " << number << endl;
		sleep(1);
	}
};

void test()
{
	unique_ptr<Task> up(new MyTask());
	unique_ptr<Threadpool> threadpoolPtr(new Threadpool(4, 10));
	threadpoolPtr->start();
	int cnt = 20;//先创建20个任务到队列中
	while(cnt--) {
		threadpoolPtr->addTask(up.get());
	}

	threadpoolPtr->stop();
	cout << ">> test(): exit while(cnt--)" << endl;
}

int main(void)
{
	test();
	return 0;
}
