 ///
 /// @file    String.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-01 12:16:50
 ///
 
#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
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
		cout << "String(const char *)" << endl;
	}

	//具有复制控制语义的函数
	//const引用作为参数时，并不能区分传递过来的实参,是左值还是右值
	String(const String & rhs) 
	: _pstr(new char[strlen(rhs._pstr) + 1]())
	{
		strcpy(_pstr, rhs._pstr);
		cout << "String(const char &)" << endl;
	}
	
	//赋值运算符函数
	String & operator=(const String & rhs)
	{
		cout << "String & operator=(const String &)" << endl;	
		if(this != &rhs){
			delete [] _pstr;
			_pstr = new char[strlen(rhs._pstr) + 1]();
			strcpy(_pstr, rhs._pstr);
		}
		return *this;
	}

	//具有移动语义的函数优先于具有复制控制语义函数的执行
	//移动构造函数
	String(String && rhs)
	: _pstr(rhs._pstr)
	{
		rhs._pstr = nullptr; //对右值进行修改
		cout << "String(String && rhs)" << endl;
	}

	//移动赋值运算符函数
	String & operator=(String && rhs)
	{
		cout << "String & operator=(String && rhs)" << endl;
		if(this != &rhs){
			delete [] _pstr; //回收左操作数开辟的空间
			_pstr = rhs._pstr;// 进行转移操作
			rhs._pstr = nullptr;
		}
		return *this;
	}

	~String()
	{
		delete [] _pstr;
		cout << "~String()" << endl;
	}
	friend std::ostream & operator<<(std::ostream & os, const  String & rhs);

private:
	char * _pstr;
};

std::ostream & operator<<(std::ostream & os, const String & rhs)
{
	os << rhs._pstr;
	return os;
}

//返回一个右值引用,右值引用本身可能是右值
//String && func()
//{
//
//}

int main()
{
	vector<String> vec;
	String str;//调用构造函数
	vec.push_back(str); //调用复制构造函数
	vec.push_back("hello,world"); //调用移动构造函数,
						//push_back具有移动语义,采用右值引用传递效率更高

	//String s0("hello, world");
	//cout << "s0 = " << s0 << endl; 

	//world可以直接取地址,不是右值
	//printf("str's address = %p\n", &"world" );//存在文字常量区

	String s1 = "world"; //world本身不是右值,而是经过隐式转化之后得到的对象是右值
	//String s1 = String("world");//显式地创建String对象,
	//cout << "s1 = " << s1 << endl;
	
	//s1 = std::move(s1);
	//cout << "s1 = " << s1 << endl;

	//cout << endl << "执行std::move之后:" << endl;
	String s2 = std::move(s1);//std::move的作用就是显式将一个左值转换为右值
	////在内部做一个强制转换,同时意味着s1以后不再使用了
	//
	cout << "s2 = " << s2 <<  endl;
	//s1 = "Wuhan";
	//cout << "s1 = " << s1 <<  endl; //若不重新对s1重新赋值,此时s1为空,程序崩溃
}
