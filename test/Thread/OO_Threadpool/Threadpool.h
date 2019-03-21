 ///
 /// @file    Threadpool.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-17 14:57:02
 ///
 
#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__

#include "TaskQueue.h"
#include "Task.h"
#include <vector>
#include <memory>
using namespace std;

namespace wd
{
class Thread;
class Threadpool
{
	friend class WorkerThread;
public:
	Threadpool(size_t threadNum, size_t queSize);
	~Threadpool();

	void addTask(Task*);
	void start(); //开启线程池
	void stop();  //关闭线程池

private:
	void threadFunc(); 
	Task * getTask();

private:
	size_t _threadNum;
	vector<unique_ptr<Thread>> _threads;
	size_t _queSize;
	TaskQueue _taskque;
	bool _isExit;
};

}//end of namespace wd

#endif
