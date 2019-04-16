 ///
 /// @file    MyResult.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-22 20:45:10
 ///
 
#ifndef __ONLINE_MYRESULT_H__
#define __ONLINE_MYRESULT_H__

#include <string>
using std::string;
 
namespace online
{

struct MyResult
{
	MyResult(const string & word, size_t freq, int dist)
	: _word(word)	
	, _freq(freq)
	, _dist(dist)
	{}

	string _word;
	size_t _freq;
	int _dist;
};

//候选词选择策略
//1.优先比较最小编辑距离
//2.次优比较词频
//3.否则比较候选词的字母表顺序

bool operator<(const MyResult & lhs, const MyResult & rhs);

}//end of namespace online

#endif
