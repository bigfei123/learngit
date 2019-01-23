///
/// @file    Point2.cc
/// @author  bigfei775655478@qq.com)
/// @date    2019-01-17 11:20:03
///

#include <iostream>
using std::cout;
using std::endl;

class Point
{

public:
	Point()
	: _ix(0)  
	, _iy(0)
	{	
		cout << "Point()" << endl;
	}
	
	Point(int ix, int iy = 0)
	: _ix(ix)
			, _iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}
	
	~Point()
	{
		cout << "~Point()" << endl;
	}

	//类型转换函数:
	//> 是一个成员函数
	//> 没有返回值形式, 但在函数体内必须以传值方式返回一个目标类型的变量(对象)
	//> 没有参数
	//> 一般情况下，不推荐使用. 违反常规思维
	//explicit
	operator int()
	{
		cout << "operator int()" << endl;
		return _ix * _iy;
	}

//operator double()
//{
//	cout << "operator double()" << endl;
//	return _ix + _iy;
//}

//friend std::ostream & operator<<(std::ostream & os, const Point & rhs);
private:
	int _ix;
	int _iy;
};

//std::ostream & operator<<(std::ostream & os, const Point & rhs)
//{
//	os << "(" << rhs._ix
//	   << "," << rhs._iy
//	   << ")";
//	return os;
//}

int main(void)
{
	Point pt(1, 2);
	cout << "pt = " << pt << endl;//隐式转换
	//此时输出的是2,如果重载了输出流运算符，输出的是pt = (1, 2)
	return 0;
}

