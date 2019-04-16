 ///
 /// @file    MyResult.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-22 21:14:34
 ///
 
#include "../../include/online/MyResult.h"

namespace online
{

bool operator<(const MyResult & lhs, const MyResult & rhs)
{
	if(lhs._dist != rhs._dist) {
		return lhs._dist > rhs._dist;
	}
	if(lhs._freq != rhs._freq) {
		return lhs._freq < rhs._freq;
	}

	return lhs._word > rhs._word;
}

}
