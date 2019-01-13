 ///
 /// @file    TestDic.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-12 16:15:37
 ///
#include "dictionary.h" 
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	Dictionary dic;
	dic.read("The_Holy_Bible.txt");
	dic.store("dictionary.txt");
	return 0;
}
