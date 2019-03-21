 ///
 /// @file    typecast.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-30 16:51:47
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
class Base
{
public:
	Base() : _base(0) {	cout << "Base()" << endl;	}

	explicit
	Base(double base): _base(base)
	{	cout << "Base(double)" << endl;	}

	void display() const 
	{	cout << "Base:: _base = " << _base << endl;	}

	~Base()
	{	cout << "~Base()" << endl;  }

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
	{	cout << "Derived()" << endl; }

	Derived(double base, double derived)
	: Base(base)
	, _derived(derived)
	{	cout << "Derived(double,double)" << endl; }

	void print() const 
	{	cout << "Derived::_derived = " << _derived << endl; }

	~Derived()
	{	cout << "~Derived()" << endl; }

private:
	double _derived;
};
int main(void)
{
	cout << "sizeof(Base) = " << sizeof(Base) << endl;
	cout << "sizeof(Derived) = " << sizeof(Derived) << endl;
	Base base(10);
	base.display();
	
	Derived d(11.11, 22.22);
	d.display();
	d.print();

	base = d; //可以把一个派生类对象赋值给基类对象
	base.operator=(d); //等价写法
	//调用Base & operator=(const Base &); // const Base & rhs = d;
	
	//d = base; //error 不可以把一个基类对象赋值给派生类对象
	//d.operator=(base);
	//调用Derived & operator=(const Derived &);// const Derived & rhs = base;
	
	base.display();

	Base *pbase = &base;
	Derived *p2 = (Derived *)pbase;//(此种向下转型是不安全的)
	pbase = &d; //将一个基类指针指向派生类对象(向上转型,是安全的)

	//不能将一个派生类指针指向基类对象,见笔记<继承>
	//Derived & pderived = &base;//error
	//pderived->print();
	
	cout << " >>> " << endl;
	//可将基类引用绑定到派生类上,反之不成立
	Base & ref = d;
	ref.display();

	return 0;
}
