 ///
 /// @file    Stack.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-03 14:37:35
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
class Stack
{
public:
	Stack();
	Stack(const Stack &);
	~Stack();
	void Push(int);
	void Pop();
	int top();
	bool Empty();
	bool Full();

private:
	int * _data;
	int _size;
	int _top;
};
