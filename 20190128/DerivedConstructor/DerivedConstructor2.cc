 ///
 /// @file    DerivedConstructor2.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-30 16:05:12
 ///
	
#include <iostream>
using std::cout;
using std::endl;
 
class Base
{
public:
	Base() : _base(0) {	cout << "Base()" << endl;	}

	explicit
	Base(double base): _base(base){	cout << "Base(double)" << endl;	}

private:	
	double _base;
};

class Derived
: public Base
{
public:
	Derived()
	: Base()
	{
		cout << "Derived()" << endl;
	} 

#if 0
	Derived(double derived)
	: Base()
	, _derived(derived)
	{
		cout << "Derived(double)" << endl;
	}
#endif

private:
	double _derived;
};

int main()
{
	Derived d1(); //声明一个函数
	Derived d;
	//当派生类没有显式定义构造函数时，系统会自动生成一个无参构造函数
	//该无参构造函数创建派生类对象时，一定会调用基类无参构造函数
	//所有基类必须提供一个无参构造函数
	return 0;
}


