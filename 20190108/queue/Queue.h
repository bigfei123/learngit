 ///
 /// @file    Queue.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-10 18:35:11
 ///
#ifndef __QUEUE_H__
#define __QUEUE_H__
#include <iostream>
using std::cout;
using std::endl;


class Queue
{
public:
	Queue();
	~Queue();
	void Push(int);
	void Pop();
	int  front();
	int  back();
	bool empty();
	bool full();
private:
	int *_data;
	int _Front;
	int _Rear;
	int _size;
};

#endif
