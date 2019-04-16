 ///
 /// @file    MutexLock.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-08 21:32:14
 ///
 
#include "../../include/online/MutexLock.h"
#include <stdio.h>
#include <errno.h>

namespace online
{
MutexLock::MutexLock()
{
	if(pthread_mutex_init(&_mutex, NULL))//如果初始化失败，返回非0值
	{
		perror("pthread_mutex_init");
	}


}
void MutexLock::lock()
{
	if(pthread_mutex_lock(&_mutex))
	{
		perror("pthread_mutex_lock");
	}
}

void MutexLock::unlock()
{
	if(pthread_mutex_unlock(&_mutex))
	{
		perror("pthread_mutex_unlock");
	}
}

MutexLock::~MutexLock()
{
	if(pthread_mutex_destroy(&_mutex))
	{
		perror("pthread_mutex_destroy");
	}
}
}//end of namespace wd

