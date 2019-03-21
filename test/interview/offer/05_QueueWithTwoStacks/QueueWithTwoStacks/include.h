 ///
 /// @file    include.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-17 20:45:35
 ///
 
#ifndef __INCLUDE_H__
#define __INCLUDE_H__
#include <stack>
using std::stack;

template<class T> 
class CQueue
{
public:
	CQueue();
	~CQueue();
	void appenndTail(const T& node);
	T deleteHead();
	bool empty();

private:
	stack<T> stackIn;
	stack<T> stackOut;
};



#endif
