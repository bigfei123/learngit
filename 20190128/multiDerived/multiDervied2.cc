 ///
 /// @file    multiDervied2.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-30 15:45:18
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
class A
{
public:
	A() {	cout << "A()" << endl;	}
	void show() const
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
	void show() const
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
	//d.show();//多重继承的问题一：成员名访问冲突
	d.A::show();  //通过类名来直接访问某一个类的同名函数
	d.B::show();
	d.C::show();
	return 0;
}
