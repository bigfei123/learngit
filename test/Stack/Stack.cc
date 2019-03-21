 ///
 /// @file    Stack.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-03 14:39:42
 ///
 
#include "Stack.h"
#include <iostream>
using std::cout;
using std::endl;

Stack::Stack()
: _data(new int[5]())
, _size(5)
, _top(0)
{
	cout << "Stack()" << endl;
}

Stack::Stack(const Stack & rhs)
: _data(new int[rhs._size + 1]())
{
	if(_data != NULL)
	{
		for(int i = 0; i != rhs._size; ++i)
		{
			_data[i] = rhs._data[i];	
		}
	}
	_size = rhs._size;
	_top = rhs._top;
	cout << "Stack(const Stack &)" << endl;
}

Stack::~Stack()
{
	if(_data != NULL) {
		delete [] _data;
		_data = NULL;//容易忘记
	}
	cout << "~Stack()" << endl;
}

void Stack::Push(int val)
{
	if(Full())
		cout << "Stack is full" << endl;
	_data[_top++] = val;
}

void Stack::Pop()
{
	if(Empty())
		cout << "Stack is empty" << endl;
	--_top;
}

int Stack::top()
{
	if(Empty())
		cout << "Stack is empty" << endl;
	return _data[_top - 1];
}

bool Stack::Empty()
{
	return _top == 0;
}

bool Stack::Full()
{
	return _top == _size;
}
