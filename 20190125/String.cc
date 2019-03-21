///
/// @file    String.cc
/// @author  bigfei775655478@qq.com)
/// @date    2019-01-30 08:22:00
///

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class String
{
public:
	String()
	: _pstr(new char[1]())
	{	cout << "String()" << endl;	}

	String(const char * pstr)
	: _pstr(new char[strlen(pstr) + 1]())
	{
		strcpy(_pstr, pstr);
		cout << "String(const char*)" << endl;
	}

	//具有复制控制语义的函数
	String(const String & rhs) //const引用作为参数时，并不能区分出传递过来的实参是左值还是右值
	: _pstr(new char[strlen(rhs._pstr) + 1]())
	{
		strcpy(_pstr, rhs._pstr);
		cout << "String(const String &)" << endl;
	}

	//赋值运算符函数
	String & operator=(const String & rhs)
	{
		cout << "String & operator=(const String &)" << endl;
		if(this != &rhs) {//自复制
			delete [] _pstr;
			_pstr = new char[strlen(rhs._pstr) + 1]();
			strcpy(_pstr, rhs._pstr);
		}
		return *this;
	}


	// 具有移动语义的函数优先于具有复制控制语义函数的执行
	//移动构造函数
	String(String && rhs)
	: _pstr(rhs._pstr)
	{
		rhs._pstr = nullptr;//对右值进行修改
		cout << "String(String && rhs)" << endl;
	}

	//移动赋值运算符函数
	String & operator=(String && rhs)
	{
		cout << "String & operator=(String &&)" << endl;
		if(this != &rhs) {
			delete [] _pstr;// 回收左操作数开辟的空间
			_pstr = rhs._pstr;// 进行转移操作
			rhs._pstr = nullptr;//对右值进行修改
		}
		return *this;
	}

	~String()
	{
		delete [] _pstr;
		cout << "~String()" << endl;
	}


	friend std::ostream & operator<<(std::ostream & os, const String & rhs);
private:
	char * _pstr;
};

std::ostream & operator<<(std::ostream & os, const String & rhs)
{
	os << rhs._pstr;
	return os;
}

int main()
{
	vector<String> vec;
	vec.push_back("hello,world");//临时对象

	String s1("hello");
	cout << "s1 = " << s1 << endl;

	//可以直接取地址
	printf("str's address = %p\n", &"world");//存在文字常量区

	s1 = "world";//"world"本身不是右值,而是经过隐式转换之后得到的对象是右值
	//s1 = String("world");//显式的创建String对象
	cout << endl;

	s1 = std::move(s1);
	cout << endl << "执行std::move之后" << endl;

	String s2 = std::move(s1);//std::move的作用是显式的将一个左值转换成右值，在内部做一个强制转换
	//同时意味着s1以后不再使用了
	
	cout << "s2 = " << s2 << endl;
	s1 = "wuhan";//如还要再使用，必须重新进行赋值
	cout << "s1 = " << s1 << endl;

	return 0;
}
