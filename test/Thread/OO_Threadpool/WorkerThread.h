 ///
 /// @file    WorkerThread.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-17 15:22:25
 ///
 
#ifndef __WORKERTHREAD_H__
#define __WORKERTHREAD_H__

#include "Thread.h"
namespace wd
{
class Threadpool;

class WorkerThread
: public Thread
{
public:
	WorkerThread(Threadpool & threadpool);
private:
	void run();
private:
	Threadpool & _threadpool;
};
}//end of namespace wd


#endif
