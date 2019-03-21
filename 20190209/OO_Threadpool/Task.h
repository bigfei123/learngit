 ///
 /// @file    Task.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-11 19:45:35
 ///
 
#ifndef __WDTASK_H__
#define __WDTASK_H__

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
