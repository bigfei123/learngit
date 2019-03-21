 ///
 /// @file    Task.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-17 14:58:05
 ///
 
#ifndef __TASK_H__
#define __TASK_H__

namespace wd
{

class Task
{
public:
	virtual void process() = 0;
	virtual ~Task() {}
};

}//end of namespace wd



#endif
