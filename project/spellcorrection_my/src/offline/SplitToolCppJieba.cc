 ///
 /// @file    SplitToolCppJieba.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-20 20:30:03
 ///
 
#include "../include/SplitToolCppJieba.h"
#include "../include/Configuration.h"

namespace dict
{
SplitToolCppJieba::SplitToolCppJieba()
: _jieba(getConfig("dictPath"),
		 getConfig("hmmPath"),
		 getConfig("userDictPath"),
		 getConfig("idfPath"),
		 getConfig("stopWordPath")){}

//调用cppjieba的Cut方法
void SplitToolCppJieba::cut(vector<string> & result, const string & sentence)
{
	_jieba.Cut(sentence, result, true);
}

}//end of namespace wd
