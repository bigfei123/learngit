 ///
 /// @file    TestThreadpool.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-11 20:36:57
 ///
 
#include "Threadpool.h"

#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <memory>
using namespace std;
using namespace wd;
 
class MyTask
: public wd::Task
{
public:
	void process()
	{
		::srand(::time(NULL));
		int number = ::rand() % 100;
		cout << "pthid " << pthread_self() << ", number = " << number << endl;
		::sleep(1);
	}
};

void test()
{
	unique_ptr<Task> up(new MyTask());
	unique_ptr<Threadpool> threadpoolPtr(new Threadpool(4, 10));
	threadpoolPtr->start();
	int cnt = 20;//先创建20个任务到任务队列中
	while(cnt--){
		threadpoolPtr->addTask(up.get());
	}

	cout << ">> test(): exit while(cnt --)" << endl;
	threadpoolPtr->stop();
}


int main(void)
{
	test();
	return 0;
}
