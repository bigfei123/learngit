 ///
 /// @file    WorkerThread.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-11 20:11:42
 ///
 
#include "WorkerThread.h" 
#include "Threadpool.h"

namespace wd
{

WorkerThread::WorkerThread(Threadpool & threadpool)
: _threadpool(threadpool)
{}

void WorkerThread::run() 
{
	_threadpool.threadFunc();
}


}// end of namespace wd
