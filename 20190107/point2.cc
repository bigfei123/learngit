 ///
 /// @file    point2.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-08 21:52:48
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point(int ix=0,int iy=0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int=0,int=0)" << endl;
	}

	//编译器提供的构造函数，可以省略
	Point(const Point & rhs)
	: _ix(rhs._ix)
	, _iy(rhs._iy)
	{
		cout << "Point(const Point &)" << endl;
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
	Point pt1(1,2);
	cout << "pt1=";
	pt1.print();

	Point pt2 = pt1;   // 执行复制构造函数
	cout << "pt2 = ";
	pt2.print();
	return 0;
}



int main(void)
{
	cout << ">> before test0..." << endl;
	test0();
	cout << ">> after test0..."  << endl;
	return 0;
}

 
