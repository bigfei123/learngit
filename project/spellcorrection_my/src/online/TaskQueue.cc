 ///
 /// @file    TaskQueue.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-10 22:57:29
 ///
 
#include "../../include/online/TaskQueue.h"

#include <iostream>
using std::cout;
using std::endl;
 
namespace online
{
TaskQueue::TaskQueue(size_t size)
: _queSize(size)
, _que()
, _mutex()
, _notFull(_mutex)
, _notEmpty(_mutex)
, _used(true)
{}

bool TaskQueue::full() const
{
	return _que.size() == _queSize;
}

bool TaskQueue::empty() const
{
	return _que.empty();
}

//push方法运行在生产者线程
void TaskQueue::push(const TaskType & t)
{
	MutexLockGuard autolock(_mutex);//加锁
	while(full()){ //是否队满,满则等待
		_notFull.wait();//使用while可以防止_notFull被异常唤醒
	}
	_que.push(t);//生产者线程放数据
	_notEmpty.notify(); //通知消费者线程取数据
}

//pop方法运行在消费者线程
TaskType TaskQueue::pop()
{
	MutexLockGuard autolock(_mutex);
	while(empty()){//是否队空,空则等待
		_notEmpty.wait();
	}
	TaskType ret = _que.front();
	_que.pop(); //消费者线程拿数据
	_notFull.notify(); //通知生产者线程放数据

	return ret;
}

void TaskQueue::wakeup()
{
	if(_used) {
		_used = false;
	}
	_notEmpty.notifyall();
}

}// end of namespace wd
