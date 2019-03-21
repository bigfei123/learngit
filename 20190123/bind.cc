 ///
 /// @file    bind.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-29 12:07:07
 ///
#include <functional> 
#include <iostream>
using std::cout;
using std::endl;
using std::bind;
//std::bind
//template< class F, class...Args >
//bind(F&& f, Args&&... args);
int add(int x, int y)
{
	cout << "int add(int,int)" << endl;
	return x + y;
}

class Example
{
public:
	int add(int x, int y)//3个参数:this、x、y
	{
		cout << "Example::add(int,int)" << endl;
		return x + y;
	}
	int data = 333;
};

int test0()
{
	//int();     函数类型 => 函数标签
	auto f1 = std::bind(add, 1, 2);
	//普通函数名就是地址
	cout << "f1() = " << f1() << endl;

	Example e1;
	//int()
	auto f2 = std::bind(&Example::add, &e1, 1, 2);
	//对成员函数的绑定需要&
	cout << "f2() = " << f2() << endl;

	//占位符
	using namespace std::placeholders;
	//auto f3 = std::bind(add, 1, std::placeholders::_1);
	auto f3 = std::bind(add, 1, _1);
	cout << "f3(2) = " << f3(2) << endl;
	return 0;
}

typedef int(*Function)();

int func()
{	return 5;	}

int func2() 
{	return 10;	}

int test1()
{
	Function f1 = func; //给f1注册回调函数,C语言用函数指针的方式实现多态
	cout << "f1()= " << f1() << endl; //执行回调函数

	f1 = func2;
	cout << "f1()= " << f1() << endl;
	return 0;
}

void func3(int x1, int x2, int x3, const int & x4, int x5)
{
	cout << "(" << x1
		 << "," << x2
		 << "," << x3
		 << "," << x4
		 << ")" << endl;
}

void test2()
{
	using namespace std::placeholders;
	int number = 100;
	//bind绑定参数时采用的是值传递
	//占位符本身所在的位置就是形参的位置
	//占位符的数字代表实参传递时实参的位置
	auto f = bind(func3,10, _1, _2, std::cref(number), number);//cref()引用包装器
	
	number = 1000;
	f(11, 12, 13, 14);//没有起到作用的实参相当于无效参数
}

//std::function
//template< class R, class... Args >
//class function<R(Args...)>
//可以看成是函数容器，统筹普通函数、成员函数、有参普通函数
//取代继承+多态的实现
void test3()
{
	
	//int();     函数类型 => 函数标签
	std::function<int()> f1 = std::bind(add, 1, 2);//普通函数
	//普通函数名就是地址
	cout << "f1() = " << f1() << endl;

	Example e1;
	//int()
	f1 = std::bind(&Example::add, &e1, 1, 2);//成员函数
	//对成员函数的绑定需要&
	cout << "f1() = " << f1() << endl;

	f1 = std::bind(&Example::data, &e1); //数据成员
	cout << "f1() = " << f1() << endl;

	//占位符
	using namespace std::placeholders;
	//auto f3 = std::bind(add, 1, std::placeholders::_1);
	std::function<int(int)> f3 = std::bind(add, 1, _1); //有参普通函数
	cout << "f3(5) = " << f3(5) << endl;
}

int main(void)
{
	//test0(); 
	//test1();
	//test2();
	test3();
}
