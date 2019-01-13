 ///
 /// @file    Stack.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-10 16:26:47
 ///
#include "Stack.h" 
#include <iostream>
#define SIZE 10
using std::cout;
using std::endl;

Stack::Stack()
:_data( new int[SIZE]())
{
	if(_data != NULL)
	{
		_size = SIZE;
		_top = 0;
	}
	cout << " Stack()" << endl;
}

Stack::Stack(const Stack & stack)
:_data(new int[stack._size+1]())
{
	if(_data != NULL)
	{
		for(int i =0; i != stack._top; ++i)
		{
			_data[i] = stack._data[i];
		}
	}
	_size = stack._size;
	_top = stack._top;
	cout << " Stack(const Stack &)" << endl;
}

Stack::~Stack()
{
	if(_data != NULL)
	{
		delete[] _data;
		_data = NULL;
	}
	cout << " ~Stack()" <<endl;
}


bool Stack::empty()
{
	if(_top == 0)
		return true;
	return false;

}

bool Stack::full()
{
	if(_top == _size)
		return true;
	return false;
}



void Stack:: Push(int val)
{
	if(full())
	{
		cout<< "the stack is full " << endl;
	}
	_data[_top++] = val;	

}

void Stack::Pop()
{
	if(empty())
	{
		cout << "the stack is empty" << endl;
	}
	--_top; 
}


int Stack::top()
{
	if(empty())
	{
		cout << "the stack is empty" << endl ;
	}
	return _data[_top -1];
}



