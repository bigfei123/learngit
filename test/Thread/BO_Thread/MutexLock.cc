 ///
 /// @file    MutexLock.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-16 19:23:12
 ///
 
#include "MutexLock.h"
#include <stdio.h>
#include <errno.h>

namespace wd
{
MutexLock::MutexLock()
{
	if(pthread_mutex_init(&_mutex, NULL))
	//如果初始化失败，返回非0值
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
		perror("pthread_muetx_unlock");
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
