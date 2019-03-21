 ///
 /// @file    testQueue.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-03 15:37:55
 ///
 
#include "Queue.h"
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	Queue queue;
	queue.Push(1);
	cout << queue.back() << endl;
	queue.Push(2);
	cout << queue.back() << endl;
	queue.Push(3);
	cout << queue.back() << endl;
	queue.Push(4);
	cout << queue.back() << endl;
	queue.Push(5);
	cout << queue.back() << endl;
	queue.Pop();
	queue.Pop();
	cout << queue.back() << endl;
	cout << queue.front() << endl;
}
