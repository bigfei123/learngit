 ///
 /// @file    Queue.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-10 18:35:22
 ///
#include "Queue.h" 
#include <iostream>
#define SIZE 10
using std::cout;
using std::endl;

Queue::Queue()
:_data(new int[SIZE]())
,_size(SIZE)
,_Front(0)
,_Rear(0)
{
	cout << " Queue() " << endl;
}

Queue::~Queue()
{
	if(_data != NULL)
	{
		delete[] _data;
		_data = NULL;
	}
	cout << "~Queue() " << endl;
}


bool Queue::empty()
{
	return _Front == _Rear;
}

bool Queue::full()
{
	return (_Rear + 1)%SIZE == _Front;
}

void Queue::Push(int val)
{
	if(full())
		cout << "the queue is full" << endl;
	_data[_Rear] = val;
	_Rear = (_Rear + 1)% SIZE;
}

void Queue::Pop()
{
	if(empty())
		cout << "the queue is empty " << endl;
	_Front = (_Front + 1) % SIZE;
}

int Queue::front()
{
	if(empty())
		cout << " the queue is empty" << endl;
	return _data[_Front];
}

int Queue::back()
{
	if(empty())
		cout << "the queue is empty" << endl;
	return _data[(_Rear-1 + SIZE)% SIZE];
	cout << "  _Rear = " << endl; 
}


