 ///
 /// @file    multiDerivedVirtual.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-31 15:08:11
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
class A
{
public:
	virtual void a() {	cout << "A::a()" << endl;	}
	virtual void b() {	cout << "A::b()" << endl;	}
	virtual void c() {	cout << "A::c()" << endl;	}
};

class B
{
public:
	virtual void a() {	cout << "B::a()" << endl;	}
	virtual void b() {	cout << "B::b()" << endl;	}
	void c() {	cout << "B::c()" << endl;	}
	void d() {	cout << "B::d()" << endl;	}
};

class C
: public A
, public B
{
public:
	virtual void a() {	cout <<"C::a()" << endl;	}
	void c() { cout << "C::c()" << endl;	} //覆盖A的c(),因为在A中c()是virtual
	void d() { cout << "C::d()" << endl;	}
};

int main(void)
{
	A a;
	B b;
	C c;
	
	A *pA = &c;
	cout << "pA = " << pA << endl;
	pA->a();   //C::a()
	pA->b();   //A::b()
	pA->c();   //C::c()
	cout << endl;

	B *pB = &c;
	cout << "pB = " << pB << endl;
	pB->a();   //C::a()
	pB->b();   //B::b()
	pB->c();   //B::c()
	pB->d();   //B::d()
	cout << endl;
	
	C *pC = &c;
	cout << "pC = " << pC << endl;
	pC->a();   //C::a()
	//pC->b();   //error二义性
	pC->A::b();//加上类作用域
	pC->B::b();
	pC->c();   //C::c()
	pC->d();   //C::d()
	cout << endl;
}
