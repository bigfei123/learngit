 ///
 /// @file    pureVirtualFunction.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-31 12:29:04
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
class A //抽象类
{
public:
	virtual void display() = 0;//声明了纯虚函数的类为抽象类
							   //抽象类不能创建对象
	virtual void print() = 0;
};

class B //抽象类
: public A
{
	//对于抽象类的派生类而言，只要有一个纯虚函数没有实现
	//该派生类也会成为抽象类
	void display()
	{	cout << "B::display()" << endl;	}
};

class C   //非抽象类
: public B
{
	void print()
	{	cout << "C::print()" << endl;	}
};

int main()
{
	//A a; error
	//B b; error
	C c;

	A *pa = &c;
	pa->display();
	pa->print();
	
	return 0;

}
