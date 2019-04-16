 ///
 /// @file    SplitTool.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-20 20:24:20
 ///
 
#ifndef __DICT_STLITTOOL_H__
#define __DICT_STLITTOOL_H__

#include <vector>
#include <string>
using std::vector;
using std::string;

namespace dict
{
class SplitTool
{
public:
	virtual ~SplitTool() {}
	virtual void cut(vector<string> &, const string &) = 0;
};


};//end of namespace dict

#endif
