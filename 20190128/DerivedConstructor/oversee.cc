 ///
 /// @file    oversee.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-30 16:25:36
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
class Base
{
public:
	Base() : _base(0) {	cout << "Base()" << endl;	}

	explicit
	Base(double base)
	: _base(base)
	, _value(_base)
	{	cout << "Base(double)" << endl;	}

	void display(int ix) const 
	{
		cout << "Base::display(int) ix = " << ix << endl;
		cout << "Base:: _base = " << _base << endl;
	}

	~Base()
	{
		cout << "~Base()" << endl; 
	}

private:	
	double _base;
protected:
	double _value;
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
	, _value(_derived)
	{
		cout << "Derived(double,double)" << endl;
	}

	void display() const 
	{
		cout << "Derived::_derived = " << _derived << endl 
			 << "Base::_value = " << Base::_value << endl
			 << "Derived::_value = " << _value << endl; 
		//隐藏派生类隐藏基类同名数据成员
	}

	~Derived()
	{
		cout << "~Derived()" << endl;
	}

private:
	double _derived;
	double _value;
};

int main(void)
{
	Derived d(22.22, 33.33);
	d.display();
	//d.display(1); //隐藏:派生类隐藏基类的同名函数(改造基类成员)
	d.Base::display(1);

	//Derived d2;
	//d2.display();
	return 0;
}
