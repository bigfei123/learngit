 ///
 /// @file    cowtest.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-01-15 16:30:23
 ///
 

#include <stdio.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
 
int main(void)
{
	string s1 = "hello";// &s1;
//	string s2 = "hello";// &s2;
	string s2 = s1;

	string s3 = "world";
	string s4 = "helloworldhello";//15个字节还在栈上
	string s5 = "helloworldhellol";//16个在堆上了
	int * pint = new int(10);
	s3 = s1;


	s3[0] = 'H';
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s4 = " << s4 << endl;
	cout << "s5 = " << s5 << endl;

	printf("s1'address = %p\n", s1.c_str());
	printf("s2'address = %p\n", s2.data());
	printf("s3'address = %p\n", s3.data());
	printf("s4'address = %p\n", s4.data());
	printf("s5'address = %p\n", s5.data());
	printf("pint address = %p\n", pint);
	cout << "sizeof(s1) = " << sizeof(s1) << endl;

	return 0;
}
