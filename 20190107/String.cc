 ///
 /// @file    String.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-08 23:50:53
 ///
#include <cstring> 
#include <iostream>
using std::cout;
using std::endl;


class String
{
public:

	//调用无参构造函数
	String()
	: _pstr(nullptr)
	{
		cout << "String()" << endl;
	}
	
	//调用有参构造函数
	String(const char *pstr)
	:_pstr(new char[strlen(pstr)+1]())
	{
		strcpy(_pstr, pstr);
		cout << "String(const char *)" << endl;
	}
	//调用复制构造函数
	String(const String &rhs)
	: _pstr(rhs._pstr)
	{
		cout << "String(const String &)" << endl;
	}
	//调用赋值表达式
	String & operator=(const String & rhs)
	{
		_pstr=rhs._pstr;
		cout << " String & operator=(const String &) " << endl;
		return *this;
	}

	~String()
	{
		cout << "~String()" << endl;
	}

	void print()
	{
		cout << " _pstr:" << _pstr << endl;
	}
private:
	char *_pstr;
};



int main(void)
{
	//String str1;
	//str1.print();

	String str2="Hello world" ;
	String str3=("wangdao ");

	str2.print();
	str3.print();
	cout << endl;

	String str4=str3;
	str4.print();
	cout << endl;

	str4= str2;
	str4.print();
	cout << endl;

	return 0;
 
}
