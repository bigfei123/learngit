 ///
 /// @file    virtualFunction5.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-30 20:32:55
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
class Base
{
public:
	Base()
	{	cout << "Base()" << endl;	}
	
	virtual void func1() 
	{	cout << "Base::func1()" << endl;}
	virtual void func2() 
	{	cout << "Base::func2()" << endl;}

	~Base()
	{	cout << "~Base()" << endl;	}
};

class Middle
: public Base
{
public:
	Middle()
	: Base()
	{
		cout << "Middle()" << endl;
		func1(); //静态联编
	}
	virtual void func1() 
	{	cout << "Middle::func1()" << endl;}
	virtual void func2() 
	{	cout << "Middle::func2()" << endl;}

	~Middle()
	{
		cout << "~Middle()" << endl;
		func2(); //静态联编
	}
};

class Derived
: public Middle
{
public:
	Derived()
	: Middle()
	{	cout << "Derived()" << endl;	}

	virtual void func1() 
	{	cout << "Derived::func1()" << endl;}
	virtual void func2() 
	{	cout << "Derived::func2()" << endl;}

	~Derived()
	{	cout << "~Derived()" << endl;	}

};
int main()
{
	//假设:func1应表现出多态特性,输出Derived的func1
	//结果:调用Middle的func1
	//原因:执行Derived构造函数的过程中调用Middle的构造函数,
	//     而此时的Derived对象还没有创建完成,所以Middle无法调用
	//     Derived的func1,Middle中的func1体现的是静态联编
	Derived derived;
	return 0;
}
