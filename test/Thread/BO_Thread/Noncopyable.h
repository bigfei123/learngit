 ///
 /// @file    Noncopyable.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-16 19:18:49
 ///
 
#ifndef __WD_NONCOPYABLE_H__
#define __WD_NONCOPYABLE_H__

namespace wd
{
class Noncopyable
{
protected:
	Noncopyable() {}
	~Noncopyable(){}

	Noncopyable(const Noncopyable &) = delete;
	Noncopyable & operator=(const Noncopyable &) = delete;
};

}//end of namespace wd

#endif
