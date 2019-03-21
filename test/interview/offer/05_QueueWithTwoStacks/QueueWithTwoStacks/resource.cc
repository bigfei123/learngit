 ///
 /// @file    resource.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-17 20:49:44
 ///
 
/*始终维护s1作为输入栈，以s2作为输出栈
 *入队时，将元素压入s1
 *出队时，判断s2是否为空，如不为空，则直接弹出顶元素；
 *如为空，则将s1的元素逐个倒入s2，把最后一个元素弹出并出队。
 *这样避免了反复倒栈
 *
 *
 *
*/

#include "include.h"
#include <stack>
#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::stack;
 
template<class T>
CQueue<T>::CQueue()
{
	cout << "CQueue()" << endl;
}

template<class T>
CQueue<T>::~CQueue()
{
	cout << "~CQueue()" << endl;
}

template<class T>
void CQueue<T>::appenndTail(const T& element)
{
	stackIn.push(element);
}

template<class T> 
T CQueue<T>::deleteHead()
{
	if(this->empty() == true)
	{
		cout << "the queue is null" << endl;
		exit(0);
	}
	else {
		//否则队列中有元素
		//此时分两种情况
		//当输出栈不为空的时候，直接将输出占中元素弹出即可
		//当输出栈为null，但是输入栈不空的时候，需要将输入栈的元素全部倒入输出栈中
	
		if(stackOut.empty() == true) {
			while(stackIn.size() > 0)
			{
				T & data = stackIn.top();
				stackIn.pop();
				stackOut.push(data);
			}
		}
		T head = stackOut.top();
		stackOut.pop();
		return head;
	}

}

template <class T>
bool CQueue<T>::empty()
{
	return (stackIn.empty() == true && stackOut.empty() == true);
}

int main(void)
{
	CQueue<char> queue;
	queue.appenndTail('a');
	queue.appenndTail('b');
	queue.appenndTail('c');
	queue.appenndTail('d');
	while(queue.empty() != true) {
		cout << queue.deleteHead() << endl;
	}
	return 0;
}
