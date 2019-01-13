 ///
 /// @file    TestStack.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-10 18:16:12
 ///
#include "Stack.h" 
#include <iostream>
using std::cout;
using std::endl;



void test()
{
	Stack stack;
	stack.Push(10);
	stack.Push(14);
	stack.Push(16);
	stack.top();
	cout << "top()" << stack.top() << endl;
	stack.Pop();
	stack.top();
	cout << "top()" << stack.top() << endl;
}




int main(void)
{
	test();
}
