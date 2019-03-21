 ///
 /// @file    TaskQueue.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-17 13:00:37
 ///
 
#ifndef _TASKQUEUE_H__
#define _TASKQUEUE_H__

#include "MutexLock.h"
#include "Condition.h"
#include <queue>

namespace wd
{

//class Task;
//using TaskType = Task*;

class TaskQueue
{
public:
	TaskQueue(size_t size);

	bool full() const;
	bool empty() const;
	void push(int number);
	int pop();

private:
	size_t _queSize;
	std::queue<int> _que;
	MutexLock _mutex;
	Condition _notFull;
	Condition _notEmpty;
};

}//end of namespace wd


#endif
