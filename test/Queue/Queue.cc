 ///
 /// @file    Queue.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-03 15:25:24
 ///

#include "Queue.h"
#include <iostream>
using std::endl;
using std::cout;

#define SIZE 10

Queue::Queue()
: _data(new int[SIZE]())
, _front(0)
, _rear(0)
, _size(SIZE)
{
	cout << "Queue()" << endl;
}

Queue::~Queue()
{
	if(_data != NULL){
		delete [] _data;
		_data = nullptr;
	}
	cout << "~Queue()" << endl;
}

void Queue::Push(int val)
{
	if(full())
		cout << "Queue is full" << endl;
	_data[_rear++] = val;
}

void Queue::Pop()
{
	if(empty())
		cout << "Queue is empty" << endl;
	_front++;
}

int Queue::front()
{
	if(empty())
		cout << "Queue is empty" << endl;
	return _data[_front];

}

int Queue::back()
{
	if(empty())
		cout << "Queue is empty" << endl;
	return _data[_rear-1];
}

bool Queue::empty()
{
	return _front == _rear;
}

bool Queue::full()
{
	return (_rear+ 1) % _size == _front;
}
