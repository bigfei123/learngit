 ///
 /// @file    const.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-02 15:40:21
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//宏定义发生的时机时预处理，只会简单的进行字符串替换，没有类型检查，在运行时出现了bug
#define max 1024
#define multi(x,y) ((x)*(y))

int const kmax = 1024;
const int kmin = 1;

int multiply(int x)
{
	return x * max;
}

int add(int x, int y)
{
	return x + y + kmax + kmin;
}

void test0()
{
	int const number = 0;
	//1>常量必须要进行初始化
	//2>常量不能被修改
}

void test1()
{
	int value = 100;
	int * p1 = &value;
	
	cout << "*p1 = " << *p1 << endl;//解引用
	*p1 = 101;//修改指针所知变量的值
	cout << "*p1 = " << *p1 << endl;//解引用
	p1 = NULL;//修改指针本身的值
	&p1;//取地址
	cout << endl;
	int value2 = 1000;
	const int * p2 = &value;//当const在*的左边时，叫常量指针
	cout << "*p2 = " << *p2 << endl;
	//*p2 = 111;//error 不能修改指针所指变量的值
	p2 = &value2;//可以修改指针的指向(可以修改指针本身的值)
	cout << "*p2 = " << *p2 << endl;

	cout << endl;
	int const * p3 = &value;//常量指针
	cout << "*p3 = " << *p3 << endl;
	//*p3 = 111;//error 不能修改指针所指变量的值
	p3 = &value2;//可以修改指针的指向(可以修改指针本身的值)
	cout << "*p3 = " << *p3 << endl;

	cout << endl;
	int * const p4 = &value;//当const在*的右边时，叫指针常量
	cout << "*p4 = " << *p4 << endl;
	*p4 = 111;//ok 可以修改指针所指变量的值
	//p4 = &value2;//error 不可以修改指针的指向
	cout << "*p4 = " << *p4 << endl;

	const int * const p5 = &value;//两者都不能进行修改(指向常量的指针常量)
	//*p5 = 1; error
	//p5 = &value2; error
}

 
int main(void)
{
	multiply(10);
	cout << "multi(1+2, 3+4) = " << multi(1+2, 3+4) << endl;
	test1();
	return 0;
}
