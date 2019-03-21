 ///
 /// @file    DerivedConstructor4.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-30 16:19:45
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

	Derived(double base, double base2, double derived)
	: Base(base)
	, _derived(derived)
	, _base2(base2)
	{
		cout << "Derived(double,double)" << endl;
	}

	void print() const 
	{
		cout << "Derived::_derived = " << _derived << endl 
			 << "Derived::_base2 = " ;
		_base2.display();
	}

	~Derived()
	{
		cout << "~Derived()" << endl;
	}

private:
	double _derived;
	Base _base2;
};
int main(void)
{
	Derived d(22.22, 33.33, 11.11);
	d.display();
	d.print();

	Derived d2;
	d2.display();
	d2.print();
	return 0;
}
