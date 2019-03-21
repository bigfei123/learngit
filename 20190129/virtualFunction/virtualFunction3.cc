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
	//override关键字提醒我们这是重定义虚函数
	virtual void display() const override
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

	base.display(); //通过对象名进行访问，并不表现多态特性,采用的是静态联编
	derived.display();//隐藏 直接去程序代码区中查找函数

	//display(base);// 当传递基类对象时，调用基类的display函数
	//display(derived);//当传递的是派生类对象时，调用派生类的display函数

	return 0;
}
