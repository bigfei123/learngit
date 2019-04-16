 ///
 /// @file    test.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-21 14:45:26
 ///
 
#include "../include/Configuration.h"
#include "../include/Mylogger.h"
#include "../include/DictProducer.h"
#include "../include/SplitToolCppJieba.h"
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	cout << dict::getConfig("dictionarySourceFile") << endl;
	dict::SplitToolCppJieba jieba;
	dict::DictProducer dict(&jieba);
	dict.buildDict();
	dict.buildIndex();
	dict.store();
}
