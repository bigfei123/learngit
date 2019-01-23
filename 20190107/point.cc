 ///
 /// @file    point.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-08 21:30:00
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	//当类中没有显示定义构造函数时，编译器会自动蹄冻一个无参构造函数
	//
	//构造函数的作用就是用来初始化数据成员的
	//
	//构造函数支持函数重载
	//
	Point()
	: _ix(0)
	, _iy(0)
	{
		cout << "Point()" << endl;
	}

	//显式定义的构造函数之后，系统就不会在自动提供默认构造函数；
	//此时如果还希望能够调用默认构造函数，就必须显式提供一个
	//
	Point(int ix, int iy)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int ,int)" << endl;
	}

	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}

private:
	int _ix;
	int _iy;
};



int test0()
{
	int a(20);
	cout << "a=" << a << endl;
	Point pt1; //调用默认构造函数 栈区
	pt1.print();

	//用户显式调用析构函数的时候，只是单纯执行析构函数内的语句
	//不会释放内存，也不会撤销对象
	pt1.~Point();
	cout << endl;

	Point pt2(1,2); //栈区，当对象被销毁时，会自动调用析构函数
	pt2.print();
	return 0;
}

int main(void)

{
 
	cout << ">> before test0... " << endl;
	test0();
	cout << ">> after test0..." << endl;
	return 0;

}
