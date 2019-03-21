 ///
 /// @file    DerivedConstructor3.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-30 16:13:12
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

	void display() const 
	{
		cout << "Base:: _base = " << _base << endl;
	}

	~Base()
	{
		cout << "~Base()" << endl; 
	}

private:	
	double _base;
};

class Derived
: public Base
{
public:
	Derived()
	: Base()
	, _derived(0)
	{
		cout << "Derived()" << endl;
	} 

	Derived(double base, double derived)
	: Base(base)
	, _derived(derived)
	{
		cout << "Derived(double,double)" << endl;
	}

	void print() const 
	{
		cout << "Derived::_derived = " << _derived << endl; 
	}

	~Derived()
	{
		cout << "~Derived()" << endl;
	}

private:
	double _derived;
};

int main(void)
{
	Derived d(22.22, 11.11);
	d.display();
	d.print();

	Derived d2;
	d2.display();
	d2.print();
	return 0;
}
