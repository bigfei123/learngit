 ///
 /// @file    TestQueue.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-10 18:35:33
 ///
 
#include "Queue.h"
#include <iostream>
using std::cout;
using std::endl;

void test()
{
	Queue queue;
	cout << "此时queue是否为空？" << queue.empty() << endl;
	queue.Push(10);
	cout << "Rear =" << queue.back() << endl;
	queue.Push(12);
	cout << "Rear = " << queue.back() << endl;
	queue.Push(14);
	cout << "Rear =" << queue.back() << endl;
	queue.Pop();
	cout << "front =" << queue.front() << endl;
}

int main()
{
	test();
	return 0;
}
