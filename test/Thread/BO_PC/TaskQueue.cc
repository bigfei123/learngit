 ///
 /// @file    TaskQueue.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-17 13:03:12
 ///
 
#include "TaskQueue.h"
#include <iostream>
using std::cout;
using std::endl;

namespace wd
{
TaskQueue::TaskQueue(size_t size)
: _queSize(size)
, _que()
, _mutex()
, _notFull(_mutex)
, _notEmpty(_mutex)
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
void TaskQueue::push(int number)
{
	MutexLockGuard autolock(_mutex);//加锁
	while(full()) {		//满则等待
		_notFull.wait();//使用while防止异常唤醒
	}
	_que.push(number);//生产者线程放数据
	_notEmpty.notify();//通知消费者线程取数据
}

//pop方法运行在消费者线程
int TaskQueue::pop()
{
	MutexLockGuard autolock(_mutex);
	while(empty()) {		//空则等待
		_notEmpty.wait();
	}
	
	int ret = _que.front(); //消费者拿数据
	_que.pop();				//通知生产者防数据
	_notFull.notify();

	return ret;
}

}//end of namespace wd
