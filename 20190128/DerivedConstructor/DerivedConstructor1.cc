 ///
 /// @file    DerivedConstructor1.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-30 15:59:59
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
class Base
{
public:
	Base(): _base(0){	cout << "Base()" << endl;	}

private:
	double _base;
};

//当派生类有显式定义构造函数时，基类没有显式定义，则创建派生类对象时，
//一定会自动调用基类构造函数

class Derived
: public Base
{
public:
	Derived(double derived)
	: Base()
	, _derived(derived)
	{
		cout << "Derived(double)" << endl;
	} 

private:
	double _derived;
};

int main()
{
	//首先要调用的是派生类对象的构造函数
	//再调用派生类构造函数的过程之中，调用了基类的构造函数
	//
	//所以说“派生类对象的构造是先调用基类构造函数，再调用派生类构造函数”是错误的
	
	Derived d(11.11);
	return 0;
}
