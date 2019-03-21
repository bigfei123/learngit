 ///
 /// @file    include.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-17 21:05:58
 ///
 
#ifndef __INCLUDE_H__
#define __INCLUDE_H__
#include <queue>
using std::queue;

template <class T>
class CStack
{
public:
	CStack();
	~CStack();

	void appendTail(const T & element);
	void deleteHead();
	int empty() const;

private:
	queue<T> queue1;
	queue<T> queue2;
};


#endif
