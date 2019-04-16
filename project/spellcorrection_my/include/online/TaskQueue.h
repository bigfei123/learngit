 ///
 /// @file    TaskQueue.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-10 22:54:01
 ///
 
#ifndef  _ONLINE_TASKQUEUE_H__
#define  _ONLINE_TASKQUEUE_H__

#include "../../include/online/MutexLock.h"
#include "../../include/online/Condition.h"

#include <functional>
#include <queue>

namespace online
{
using TaskType = std::function<void()>;

class TaskQueue
{
public:
	TaskQueue(size_t size);

	bool full() const;
	bool empty() const;
	void push(const TaskType & t);
	TaskType pop();

	void wakeup(); //激活所有等待_notEmpty条件变量的线程

private:
	size_t _queSize;
	std::queue<TaskType> _que;
	MutexLock _mutex;
	Condition _notFull;
	Condition _notEmpty;
	bool _used;
};

}// end of namspace wd


#endif

