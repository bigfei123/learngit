 ///
 /// @file    DerivedCopyControl1.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-30 17:48:51
 ///

#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
 
class Base
{
public:
	Base()
	: _pdata(nullptr)
	{	cout << "Base()" << endl;	}

	Base(const char * pdata)
	: _pdata(new char[strlen(pdata) + 1]())
	{
		cout << "Base(const char *)" << endl;
		strcpy(_pdata, pdata);
	}

	Base(const Base & rhs)
	: _pdata(new char[strlen(rhs._pdata) + 1]())
	{
		cout << "Base(const Base &) " << endl;
		strcpy(_pdata, rhs._pdata);
	}

	Base & operator=(const Base & rhs)
	{
		cout << "Base & operator=(const Base & rhs)" << endl;
		if(this != &rhs)
		{
			delete [] _pdata;
			_pdata = new char[strlen(rhs._pdata) + 1]();
			strcpy(_pdata, rhs._pdata);
		}
		return *this;
	}

	~Base()
	{
		cout << "~Base()" << endl;
		if(_pdata)
			delete [] _pdata;
	}

	friend std::ostream & operator<<(std::ostream & os, const Base & rhs);
private:
	char *_pdata;
};

std::ostream & operator<<(std::ostream & os, const Base & rhs)
{
	os << rhs._pdata;
	return os;
}

//派生类没有显式定义复制控制函数(复制构造函数、赋值表达式),但基类有显式定义,
//则执行派生类对象间的复制控制操作时，会自动调用基类的复制控制函数
class Derived
: public Base
{
public:
	Derived(const char * pdata)
	: Base(pdata)
	{	cout << "Derived()" << endl;	}

	~Derived()
	{	cout << "~Derived()" << endl;	}

	friend std::ostream & operator<<(std::ostream & os, const Derived & rhs);
};

std::ostream & operator<<(std::ostream & os, const Derived & rhs)
{
	const Base & base = rhs;
	os << base;
	return os;
}

int main()
{
	Derived d1("hello");
	cout << "d1 = " << d1 << endl;
	
	Derived d2(d1);
	cout << "d2 = " << d2 << endl;

	Derived d3("world");
	d1 = d3;
	cout << "d3 = " << d3 << endl;
	cout << "d1 = " << d1 << endl;
	return 0;	
}
