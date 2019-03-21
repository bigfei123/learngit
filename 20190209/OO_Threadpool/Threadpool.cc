 ///
 /// @file    Threadpool.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-11 19:59:16
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
	for(size_t idx = 0; idx != _threadNum; ++idx){
		unique_ptr<Thread> up(new WorkerThread(*this));
		_threads.push_back(std::move(up));//创建线程对象,并压入vector中
	}

	for(auto & threadPtr: _threads)
		threadPtr->start();//对vector中的每个线程对象调用pthread_create()
}

void Threadpool::addTask(Task * ptask)
{
	_taskque.push(ptask);
}

Task * Threadpool::getTask()
{
	return _taskque.pop();
}

//每一个子线程要执行的任务: 不断的去任务队列中获取任务并执行
void Threadpool::threadFunc()
{
	while(!_isExit){
		Task * ptask = getTask(); //获取任务
		if(ptask)
			ptask->process(); //执行任务
	}
}

void Threadpool::stop()
{
	cout << ">>> main thread Threadpool::stop() entering" << endl;
	if(!_isExit){
		//在退出线程池之前，要确保任务队列中的任务都被执行完毕了
		while(!_taskque.empty()){
			::usleep(100);
			//Bug::让主线程休眠1s,若在休眠过程中，所有子线程执行完毕，会等待任务到来进入,进入wait()阻塞 
			//即使将_isExit设置为true，子线程也不会正常退出
		}
		//退出while循环，表示所有的任务都被子线程取走了(任务是否执行完毕是不确定的)
		_isExit = true;
		//Bug解决::唤醒所有的子线程
		_taskque.wakeup();				
		//回收每一个子线程的资源
		for(auto & threadPtr : _threads){
			threadPtr->join();//等待每一个子线程执行完毕
		}
	}
	cout << ">> main thread Threadpool::stop() exit" << endl;
}



}//end of namespace wd
