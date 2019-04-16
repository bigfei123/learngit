 ///
 /// @file    BitMap.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-22 21:45:03
 ///
 
#ifndef __ONLINE_BITMAP_H__
#define __ONLINE_BITMAP_H__

#include <vector>
using std::vector;
namespace online
{

class BitMap
{
public:
	BitMap(const size_t);

	bool isSet(const size_t) const;
	void setMap(const size_t);
	size_t size() const;

private:
	size_t _size;
	vector<char> _bitmap;
};

}//end of namespace online

#endif
