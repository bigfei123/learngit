 ///
 /// @file    Threadpool.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-11 19:59:16
 ///
 
#include "Threadpool.h"
#include "Thread.h"

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
	for(size_t idx = 0; idx != _threadNum; ++idx){
		unique_ptr<Thread> up(new Thread(
			std::bind(&Threadpool::threadFunc, this)
		));
		_threads.push_back(std::move(up));//创建线程对象,并压入vector中
	}

	for(auto & threadPtr: _threads)
		threadPtr->start();//对vector中的每个线程对象调用pthread_create()
}

void Threadpool::addTask(Task && task)
{
	_taskque.push(std::move(task));
}

Task Threadpool::getTask()
{
	return _taskque.pop();
}

//每一个子线程要执行的任务: 不断的去任务队列中获取任务并执行
void Threadpool::threadFunc()
{
	while(!_isExit){
		Task task = getTask(); //获取任务
		if(task)
			task();
	}
}

void Threadpool::stop()
{
	if(!_isExit){
		//在退出线程池之前，要确保所有的任务都被执行完毕了
		while(!_taskque.empty()){
			::usleep(100);
		}
		_isExit = true;
		_taskque.wakeup();

		for(auto & threadPtr : _threads){
			threadPtr->join();//等待每一个子线程执行完毕
		}
	}
}



}//end of namespace wd
