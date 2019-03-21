 ///
 /// @file    virtualFunction4.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-30 20:19:02
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
class Base
{
public:
	Base()
	{	cout << "Base()" << endl;}

	virtual void display() const
	{	cout << "Base::display()" << endl;}

	void baseFunc1()
	{	this->display();	} //在成员函数中调用虚函数，表现多态的特性

	void baseFunc2()
	{	Base::display();	}
};

class Derived
:public Base
{
public:
	Derived()
	: Base()
	{	cout << "Derived()" << endl;	}

	virtual void display() const override
	{	cout << "Derived::display()" << endl;	}
};

int main()
{
	cout << "sizeof(Base) = " << sizeof(Base) << endl;
	cout << "sizeof(Derived) = " << sizeof(Derived) << endl;
	Base base;
	Derived derived;

	Base *pbase = &base;
	pbase->baseFunc1();
	pbase->baseFunc2();

	pbase = &derived;
	pbase->baseFunc1();
	pbase->baseFunc2();
	return 0;
}


