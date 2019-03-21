///
/// @file    virtualFunction.cc
/// @author  bigfei775655478@qq.com)
/// @date    2019-01-30 11:38:31
///

#include <iostream>
using std::cout;
using std::endl;

class Base
{
	public:
		Base() : _dbase(0)
	{	cout << "Base()" << endl;	}

		virtual void display() const
		{
			cout << "Base::display()  _dbase = " << _dbase << endl;
		}

	private:
		double _dbase;
};

//虚函数机制（如何实现的）：
//1. 当一个类中定义了虚函数之后，其对象存储布局之中会生成一个虚函数指针，
//   该虚函数指针指向了一张虚函数表, 虚函数表里面存放的是虚函数的入口地址
//


//虚函数机制被激活的条件:
//1. 基类要定义虚函数
//2. 派生类要重定义(覆盖)基类虚函数
//3. 创建派生类对象 
//4. 基类指针指向派生类对象(基类引用绑定到派生类对象)
//5. 通过基类指针(引用)调用虚函数

//为什么构造函数不能设为虚函数？
//答: 根据虚函数被激活的条件，先要创建对象，才会生成虚函数指针, 之后才能使用虚函数

class Derived
: public Base
{
public:
	Derived()
		: _derived(10)
	{	cout << "Derived()" << endl;	}

	//Derived重定义虚函数,需要和基类保持一致
	virtual void display() const
	{
		cout << "Derived::display()  _derived = " << _derived << endl;
	}

	//新的虚函数,包含参数,与基类的方法不同
	virtual void display(int ix) const
	{
		cout << "Derived::display(int)  _derived = " << _derived << endl;
	}
private:
	double _derived;
};

class Derived2
: public Base
{
public:
	Derived2()
	: _derived2(100)
	{	cout << "Derived2()" << endl;	}

	virtual void display() const
	{
		cout << "Derived2::display()  _derived2 = " << _derived2 << endl;
	}
private:
	double _derived2;
};
void display(Base * pbase)
{
	pbase->display();//同一个指令，针对不同的对象，产生不同的行为
}

int main(void)
{
	cout << "sizeof(Base) = " << sizeof(Base) << endl;
	cout << "sizeof(Derived) = " << sizeof(Derived) << endl;
	Base base;
	Derived derived;
	Derived2 derived2;

	display(&base);// 当传递基类对象时，调用基类的display函数
	display(&derived);//当传递的是派生类对象时，调用派生类的display函数
	display(&derived2);

	Derived * pderived = &derived;
	pderived->display(1);

	return 0;
}
