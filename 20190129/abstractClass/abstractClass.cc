 ///
 /// @file    abstractClass.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-31 12:36:57
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
class Base
{
	//定义了protected型构造函数的类也成为抽象类
protected:
	Base()
	{	cout << "Base()" << endl;	}
};

class Derived
: public Base
{
public:
	Derived()
	: Base()
	{	cout << "Derived()" << endl;	}

	void display() const
	{	cout << "Derived::display()" << endl;	}
};

int main()
{
	//Base base; error
	
	Derived d;
	d.display();

	return 0;
}

