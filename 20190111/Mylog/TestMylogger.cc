 ///
 /// @file    TestMylog.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-13 19:00:27
 ///
 
#include "Mylogger.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;
//using namespace::log4cpp;
using namespace DF;

//string prefix(const char *msg)
//{
//	string prefix = "[" + string(__FILE__) 
//			+ ":" + std::to_string(__LINE__)  //to_string() 在std的命名空间里 
//			+ ":" + (__FUNCTION__) + "]";
//	return prefix + msg;
//}


void test0()
{
	Mylogger ::getInstance()->error(prefix("this is an error message"));
	//warn为 const char * 类型，prefix为string类型,用到c_str()转换 
	//此时输出的函数名和行号为调用它的函数名和行号
	//解决办法：把prefix定义为宏定义而不是函数
	Mylogger ::getInstance()->error("this is an error message");
	Mylogger ::getInstance()->debug("this is an error message");
	Mylogger ::getInstance()->warn("this is an error message");
	Mylogger ::getInstance()->Set_Priority(Mylogger::Priority::WARN);
	
	cout << __FILE__<< " " << __LINE__ << " " <<__FUNCTION__<< endl;
	//输出本文件名、所在行号、所在函数名
}

void test1()
{
	LogError("this is a error message!");
	LogWarn("this is a warn message!");
	LogInfo("this is a iofo message!");
	LogDebug("this is a debug message!");

}

int main(void)
{	
	test1();
	//test0();
}
