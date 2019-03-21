 ///
 /// @file    testStack.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-03 14:57:46
 ///
 
#include "Stack.h"
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	Stack stack;
	cout << "The stack is empty? " << stack.Empty() << endl;
	stack.Push(1);
	cout << stack.top() << endl;
	stack.Push(2);
	cout << stack.top() << endl;
	stack.Push(3);
	cout << stack.top() << endl;
	stack.Push(4);
	cout << stack.top() << endl;
	stack.Push(5);
	cout << stack.top() << endl;
	cout << "The stack is full? " << stack.Full() << endl;
	stack.Pop();
	cout << stack.top() << endl;
	stack.Pop();
	cout << stack.top() << endl;
	stack.Pop();
	cout << stack.top() << endl;
	stack.Pop();
	cout << stack.top() << endl;
	stack.Pop();
	cout << stack.top() << endl;
	cout << "The stack is empty? " << stack.Empty() << endl;
}
