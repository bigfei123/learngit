///
/// @file    virtualFunction.cc
/// @author  bigfei775655478@qq.com)
/// @date    2019-01-30 11:38:31
///

#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	Base() : _dbase(0)
	{	cout << "Base()" << endl;	}

	virtual void display() const
	{
		cout << "Base::display()  _dbase = " << _dbase << endl;
	}

private:
	double _dbase;
};

class Derived
: public Base
{
public:
	Derived()
	: _derived(10)
	{	cout << "Derived()" << endl;	}

	//Derived重定义虚函数,需要和基类保持一致
	virtual void display() const
	{
		cout << "Derived::display()  _derived = " << _derived << endl;
	}

private:
	double _derived;
};

//引用也可以体现多态机制
void display(Base & base)
{
	base.display();//同一个指令，针对不同的对象，产生不同的行为
}

int main(void)
{
	Base base;
	Derived derived;

	display(base);// 当传递基类对象时，调用基类的display函数
	display(derived);//当传递的是派生类对象时，调用派生类的display函数

	return 0;
}
