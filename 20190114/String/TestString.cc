 ///
 /// @file    TestString.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-16 19:52:57
 ///

#include "String.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
 
int main(void)
{
	String();
	const char *p = "Huangshi";
	cout << "p[0] = " << p[0] << endl;
	String str1("hello");
	cout << "str1 =" << str1 << endl;
	cout << "str1[0] = " << str1[0] << endl;
	str1[0] = 'H'; 
	cout << "str1[0] = " << str1[0] << endl;
	str1+= p;
	cout << "str1 =" << str1 << endl;
	String str2 = str1;
	cout << "str2 =" << str2 << endl;
	String str3="Wuhan";
	str3 = str1;
	cout << "str3 =" << str3<< endl;
	str3 = p;	
	cout << "str3 =" << str3<< endl;
	for(size_t idx = 0; idx != str3.size();++idx)
		cout << str3[idx]; 
	cout << "str2 == str1: " << (str2 == str1) << endl;
	cout << "str2 != str1: " << (str2 != str1) << endl;
	cout << "str2 <= str1: " << (str2 <= str1) << endl;
	cout << "str2 >= str1: " << (str2 >= str1) << endl;
	cout << "str2 >str1: " << (str2 > str1) << endl;
	cout << "str2 <str1: " << (str2 < str1) << endl;
	String str4 = "Hubei";
	cin >> str4;
	for(size_t idx = 0; idx != str4.size();++idx)
		cout << str4[idx] ;

}
