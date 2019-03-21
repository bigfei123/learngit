 ///
 /// @file    TestString.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-05 14:17:27
 ///
 
#include "String.h"
#include <iostream>
using std::cout;
using std::endl;

void test()
{
	String();
	String str1 = "hello";
	String str2 = str1;//复制构造函数,有参构造函数
	String str3;
	str3 = str2;//赋值运算符函数
	const char * p = "world";
	str3 = p;
	String str4;
	str4 = str1 + str3;
}
 
int main(void)
{
	test();
	return 0;
}
