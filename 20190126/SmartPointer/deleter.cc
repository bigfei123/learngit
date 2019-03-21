 ///
 /// @file    deleter.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-01 19:44:10
 ///
 
#include <iostream>
#include <stdio.h>
#include <string>
#include <memory>
using std::cout;
using std::endl;
using std::string;
using std::unique_ptr;
using std::shared_ptr;
 
//使用函数对象完成资源的定制化回收方式
struct FilePointCloser
{
	void operator()(FILE * fp)
	{
		if(fp){
			fclose(fp);
			cout << "fclose(fp)" << endl;
		}
	}
};

void test0()
{
	unique_ptr<FILE, FilePointCloser> up(fopen("test.txt", "w"));
	string msg = "hello,world";
	fwrite(msg.c_str(), 1, msg.size(), up.get());
}

void test1()
{
	shared_ptr<FILE> sp(fopen("test.txt", "a+"), FilePointCloser());
	string msg = "hello,world";
	fwrite(msg.c_str(), 1, msg.size(), sp.get());
}

int main()
{
	test0();
	test1();
	return 0;
}
