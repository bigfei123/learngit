 ///
 /// @file    WorkThread.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-11 20:03:23
 ///
 
#ifndef __WD_WORKERTHREAD_H__
#define __WD_WORKERTHREAD_H__

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
