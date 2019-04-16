 ///
 /// @file    BitMap.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-22 22:18:24
 ///
 
#include "../../include/online/BitMap.h"
#include <math.h>
#include <iostream>
using std::cout;
using std::endl;
 
namespace online
{
BitMap::BitMap(const size_t size)
: _size(size)
, _bitmap(ceil(size / 8), 0)
{}

//获取一位
bool BitMap::isSet(const size_t idx) const
{
	size_t i = idx / 8, j = idx % 8;
	return _bitmap[i] & (1 << j);
}

//设置一位
void BitMap::setMap(const size_t idx)
{
	size_t i = idx / 8, j = idx % 8;
	_bitmap[i] |= (1 << j);
}

size_t BitMap::size() const
{
	return _size;
}

}//end of namespace online
