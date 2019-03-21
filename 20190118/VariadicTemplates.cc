 ///
 /// @file    VariadicTemplates.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-19 20:19:00
 ///
#include <string> 
#include <iostream>
using std::cout;
using std::endl;
using std::string;

template <typename... Args>  //Args模板参数包
void print(Args... args) //args函数参数包
{
	cout << "sizeof...(Args) = " << sizeof...(Args) << endl;
	cout << "sizeof...(args) = " << sizeof...(args) << endl;
}

void test0()
{
	string s1 = "world";
	print();
	print(true);
	print(1, 2.2);
	print('a', true, s1);
	print(3, 4.4, 'c', "hello");
}

void display()
{
	cout << endl;
}

template <class T, class... Args>
void display(T t, Args... args) //函数参数包声明时，在其左边
{
	cout << t << " " ;
	display(args...); //当...在函数参数包右边时，表示展开参数包
}

int test1()
{
	string s1 = "world";
	display();
	display(1);
	display(1, 2.2);
	display('a', true, s1);
	display(3, 4.4, 'c' , "hello");
	return 0;
}


template <class T>
T sum(T t)
{
	return t;
}

template <class T, class... Args>
T sum(T t, Args... args)
{
	return t + sum(args...);
}

void test2()
{
	cout << "sum(1, 2, 3 ,4 ,5 ,6 ,7) = " 
		 << sum(1, 2, 3, 4, 5 ,6, 7) << endl;
}

int main()
{
	//test0();
	//test1();
	test2();
	return 0;
}
