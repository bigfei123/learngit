 ///
 /// @file    Threadpool.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-17 15:03:41
 ///
 
#include "Threadpool.h"
#include "WorkerThread.h"
#include <unistd.h>

namespace wd
{

Threadpool::Threadpool(size_t threadNum, size_t queSize)
: _threadNum(threadNum)
, _threads()
, _queSize(queSize)
, _taskque(_queSize)
, _isExit(false)
{	
	_threads.reserve(threadNum);
}

Threadpool::~Threadpool()
{
	if(!_isExit)
		stop();
}

void Threadpool::start()
{
	//创建_threadNum个工作线程,并压入vector
	for(size_t idx = 0; idx != _threadNum; ++idx) {
		unique_ptr<Thread> up(new WorkerThread(*this));
		_threads.push_back(std::move(up));
	}
	for(auto & threadPtr : _threads)
		threadPtr->start(); 
		//调用Thread::start(),对每一个工作线程调用pthread_create()
}

void Threadpool::addTask(Task * ptask)
{
	_taskque.push(ptask);
}

Task * Threadpool::getTask()
{
	return _taskque.pop();
}

//每一个子线程不断的去任务队列中获取任务并执行
void Threadpool::threadFunc()
{
	while(!_isExit) {
		Task * ptask = getTask(); //获取任务
		if(ptask)
			ptask->process();     //执行任务
	}
}

void Threadpool::stop()
{
	if(!_isExit) {
		//在退出线程池之前，要确保所有的任务都被执行完毕
		while(!_taskque.empty()) {
			::usleep(100);
		}
		//退出while循环，表示所有的任务都被子线程取走了
		_isExit = true;
		for(auto & threadPtr : _threads) {
			threadPtr->join();   //等待每一个子线程执行完毕
		}
	}
}

}//end of namespace wd

