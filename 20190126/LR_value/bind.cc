 ///
 /// @file    bind.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-01 13:51:44
 ///
 
#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using std::bind;
 
int add(int x, int y)
{
	cout << "int add(int,int)" << endl;
	return x + y;
}

class Example
{
public:
	int add(int x, int y)
	{
		cout << "Example::add(int, int)" << endl;
		return x + y;
	}
	int data = 333;
};

int test0()
{
	//int();   函数类型=》函数标签
	auto f1 = std::bind(add, 1, 2);
	cout << "f1() = " << f1() << endl;

	Example e1;
	auto f2 = std::bind(&Example::add, &e1, 1, 2);
	cout << "f2() = " << f2() << endl;

	//占位符
	using namespace std::placeholders;
	//auto f3 = std::bind(add, 1, std::placeholders::_1);
	auto f3 = std::bind(add, 1, _1);
	cout << "f3(2) = " << f3(2) << endl;

	return 0;
}

//typedef 返回类型(*新类型)(参数表)
//typedef的功能是定义新的类型.
//定义一钟Function的类型,它返回类型为int,参数为无参的函数指针
typedef int(*Function)();

int func()
{	return 5;	}

int func2()
{	return 10;	}

int test1()
{
	Function f1 = &func;
	//给f1注册回调函数,C语言用函数指针的方式实现多态
	cout << "f1() = " << f1() << endl; //执行回调函数

	f1 = func2;
	cout << "f1() = " << f1() << endl; //执行回调函数
	return 0;
}

void func3(int x1, int x2, int x3, const int & x4, int x5)
{
	cout << "(" << x1
		 << "," << x2
		 << "," << x3
		 << "," << x4
		 << "," << x5
		 << ")" << endl;
}

void test2()
{
	using namespace std::placeholders;
	int number = 100;
	//bind绑定参数时采用的是值传递
	//占位符本身所在的位置就是形参的位置
	//占位符的数字代表实参传递时实参的位置
	auto f = bind(func3, 10, _2, _1, std::cref(number), number);

	number = 1000;
	f(11, 12, 111, 222, 333);//没有作用的实参是无效参数
}

int test3()
{
	//std::function可以看成是函数的容器,取代继承+多态的实现
	//std::function<返回值类型(参数类型)> 函数名
	std::function<int()> f1 = std::bind(add, 1, 2); //普通函数
	cout << "f1() = " << f1() << endl;

	Example e1;
	f1 = std::bind(&Example::add, &e1, 1, 2); //成员函数,需要绑定对象
	cout << "f1() = " << f1() << endl;

	f1 = std::bind(&Example::data, &e1); //数据成员,需要绑定对象
	cout << "f1() = " << f1() << endl;

	using namespace std::placeholders;
	std::function<int(int)> f3 = std::bind(add, 1, _1);
	cout << "f3(2) = " << f3(2) << endl;
	return 0;
}

int main()
{
	//test0();
	//test1();
	//test2();
	test3();
}
