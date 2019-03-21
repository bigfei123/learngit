 ///
 /// @file    multiDervied3.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-30 15:47:35
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
class A
{
public:
	A() : _ia(0) {}
	
	void setA(double ia)
	{ _ia = ia; }

	void print() const
	{	cout << "A::_ia = " << _ia << endl; }
private:
	double _ia;
};

class B
: virtual public A
{};

class C
: virtual public A
{};

class D
: public B
, public C
{};

int main()
{
	cout << "sizeof(A) = " << sizeof(A) << endl;
	cout << "sizeof(B) = " << sizeof(B) << endl;
	cout << "sizeof(C) = " << sizeof(C) << endl;
	cout << "sizeof(D) = " << sizeof(D) << endl;
	D d;
	d.setA(100); 
	d.print();
	d.B::setA(10); //多重继承之存储二义性
	d.B::print();
	d.C::setA(1);
	d.C::print();
	cout << endl;

	d.print();
	return 0;
}
