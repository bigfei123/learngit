///
/// @file    TestString.cc
/// @author  bigfei775655478@qq.com)
/// @date    2019-03-05 20:58:36
///

#include "String.h"
#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	String s1("hello,world");
	String s2 = s1;//copy constructor
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s1' refcount = " << s1.refcount() << endl;
	cout << "s2' refcount = " << s2.refcount() << endl;
	printf("s1'address = %p\n", s1.c_str());
	printf("s2'address = %p\n", s2.c_str());

	String s3("hubei wuhan");
	cout << ">> 执行s3 = s1 之后: " << endl;
	s3 = s1;//调用operator=()
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s1' refcount = " << s1.refcount() << endl;
	cout << "s2' refcount = " << s2.refcount() << endl;
	cout << "s3' refcount = " << s3.refcount() << endl;
	printf("s1'address = %p\n", s1.c_str());
	printf("s2'address = %p\n", s2.c_str());
	printf("s3'address = %p\n", s3.c_str());

	cout << endl << "对s3[0]执行写操作:" << endl;
	s3[0] = 'H';//要去修改字符串内容，此时才去进行深拷贝
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s1' refcount = " << s1.refcount() << endl;
	cout << "s2' refcount = " << s2.refcount() << endl;
	cout << "s3' refcount = " << s3.refcount() << endl;
	printf("s1'address = %p\n", s1.c_str());
	printf("s2'address = %p\n", s2.c_str());
	printf("s3'address = %p\n", s3.c_str());

	cout << endl << "对s1[0]执行读操作" << endl;
	cout << "s1[0] = " << s1[0] << endl;//要去修改字符串内容，此时才去进行深拷贝
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s1' refcount = " << s1.refcount() << endl;
	cout << "s2' refcount = " << s2.refcount() << endl;
	cout << "s3' refcount = " << s3.refcount() << endl;
	printf("s1'address = %p\n", s1.c_str());
	printf("s2'address = %p\n", s2.c_str());
	printf("s3'address = %p\n", s3.c_str());

	return 0;
}
