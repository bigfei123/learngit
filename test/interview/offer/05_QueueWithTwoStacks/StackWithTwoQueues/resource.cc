 ///
 /// @file    resource.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-17 21:09:42
 ///
 
#include "include.h"
#include <queue>
#include <iostream>
using std::cout;
using std::endl;
using std::queue;
 
template<class T>
CStack<T>::CStack()
{	
	cout << "CStack()" << endl;
}

template<class T>
CStack<T>::~CStack()
{	
	cout << "~CStack()" << endl;
}

template<class T>
void CStack<T>::appendTail(const T & element)
{
	queue1.push(element);
}

template<class T>
void CStack<T>::deleteHead()
{
	if(queue1.size() == 0) {
		if(queue2.size() == 0) {
			cout << "the stack is null" << endl;
		}
		while(queue2.size() > 1) {
			T & data = queue2.front();
			queue2.pop();
			queue1.push(data);
		}
		if(queue2.size() == 0) {
			return ;
		}
		T head = queue2.front();
		cout << "queue2.head = " << head << endl;
		queue2.pop();
	}

	while(queue1.size() > 1)
	{
		//cout << queue1.front() << endl;
		T & data = queue1.front();
		queue1.pop();
		queue2.push(data);
	}
	if(queue1.size() == 0) {
		return ;
	}
	T head = queue1.front();
	cout << "queue1.head = " << head << endl;
	queue1.pop();
}

template <class T>
int CStack<T>::empty() const
{
	return (queue1.empty() == true && queue2.empty() == true);
}


int main(void)
{
	CStack<char> stack; 
	stack.appendTail('1');
	stack.appendTail('2');
	stack.appendTail('3');
	stack.appendTail('4');
	while(!stack.empty()) {
		stack.deleteHead();
	}
	return 0;
}
