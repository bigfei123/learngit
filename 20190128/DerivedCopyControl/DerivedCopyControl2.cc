 ///
 /// @file    DerivedCopyControl2.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-30 18:12:12
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

//派生类有显式定义复制控制函数(复制构造函数、赋值表达式),但基类也有显式定义,
//则执行派生类对象间的复制控制操作时，不会再自动调用基类的复制控制函数
//必须手动显式调用相应基类的复制控制函数
class Derived
: public Base
{
public:
	Derived(const char * pdata, const char *pdata2)
	: Base(pdata)
	, _pdata2(new char[strlen(pdata2) + 1]())
	{	
		cout << "Derived(const char*, const char *)" << endl;	
		strcpy(_pdata2, pdata2);
	}

	Derived(const Derived & rhs)
	: Base(rhs) //派生类能够适应基类，显式调用
	, _pdata2(new char[strlen(rhs._pdata2) + 1]())
	{
		cout << "Derived(const Derived &)" << endl;
		strcpy(_pdata2, rhs._pdata2);
	}

	Derived & operator=(const Derived & rhs)
	{
		cout << "Derived & operator=(const Derived &)" << endl;
		if(this != &rhs){
			Base::operator=(rhs); //显式调用基类的赋值运算符函数
			delete [] _pdata2;

			_pdata2 = new char[strlen(rhs._pdata2) + 1]();
			strcpy(_pdata2, rhs._pdata2);
		}
		return *this;
	}

	~Derived()
	{	cout << "~Derived()" << endl;	}

	friend std::ostream & operator<<(std::ostream & os, const Derived & rhs);

private:
	char *_pdata2;
};

std::ostream & operator<<(std::ostream & os, const Derived & rhs)
{
	const Base & base = rhs;
	os << base << "," 
	   << rhs._pdata2;
	return os;
}

int main()
{
	Derived d1("hello", "world");
	cout << "d1 = " << d1 << endl;
	
	Derived d2(d1);
	cout << "d2 = " << d2 << endl;

	Derived d3("Hubei","Wuhan");
	d1 = d3;
	cout << "d3 = " << d3 << endl;
	cout << "d1 = " << d1 << endl;
	return 0;	
}
