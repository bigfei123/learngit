 ///
 /// @file    TaskQueue.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-10 22:54:01
 ///
 
#ifndef  _WD_TASKQUEUE_H__
#define  _WD_TASKQUEUE_H__

#include "MutexLock.h"
#include "Condition.h"
#include <queue>

namespace wd
{

class Task;
using TaskType = Task*;

class TaskQueue
{
public:
	TaskQueue(size_t size);

	bool full() const;
	bool empty() const;
	void push(const TaskType & t);
	TaskType pop();

private:
	size_t _queSize;
	std::queue<TaskType> _que;
	MutexLock _mutex;
	Condition _notFull;
	Condition _notEmpty;
};

}// end of namspace wd


#endif

