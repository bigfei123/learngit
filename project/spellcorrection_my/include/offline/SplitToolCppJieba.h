 ///
 /// @file    SplitToolCppJieba.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-20 20:31:59
 ///
 
#ifndef __DICT_SPLITTOOLCPPJIEBA_H__
#define __DICT_SPLITTOOLCPPJIEBA_H__

#include "SplitTool.h"
#include "../lib/cppjieba/include/cppjieba/Jieba.hpp"

namespace dict
{

class SplitToolCppJieba
: public SplitTool
{
public:
	SplitToolCppJieba();
	void cut(vector<string> &, const string &);
private:
	cppjieba::Jieba _jieba;
};

}//end of namespace dict

#endif
