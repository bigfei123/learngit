 ///
 /// @file    multiDervied1.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-30 15:37:54
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
class A
{
public:
	A() {	cout << "A()" << endl;	}
	void display() const
	{	cout << "A::display() " << endl;}
};

class B
{
public:
	B()	{	cout << "B()" << endl;	}
	void show() const
	{
		cout << "B::show() "<< endl;	
	}
};

class C
{
public:
	C() {	cout << "C()" << endl;	}
	void print() const
	{	cout << "C::print()" << endl;	}
};

class D
: public A
, public B
, public C
{
public:
	D() {	cout << "D()" << endl; }
};

int main()
{
	D d;
	d.show();
	d.display();
	d.print();
	return 0;
}
