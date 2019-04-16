 ///
 /// @file    Noncopyable.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-21 21:11:36
 ///
 
#ifndef __ONLINE__NOCOPYABLE_H__
#define __ONLINE__NOCOPYABLE_H__

namespace online
{

class Noncopyable
{
protected:
	Noncopyable() = default;
	~Noncopyable() = default;
	Noncopyable(const Noncopyable & ) = delete;
	Noncopyable & operator=(const Noncopyable &) = delete;
};


}//end of namespace online


#endif
