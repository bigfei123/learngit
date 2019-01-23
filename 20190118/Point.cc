 ///
 /// @file    Point.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-19 20:16:30
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//全局类/普通类
class Point
{
public:
	Point(double ix = 0, double iy = 0)
	: _ix(ix)
	, _iy(iy)
	{}

	//成员函数模板，模板参数可以设置默认值
	template <class T = int>
	T func()
	{
		return (T)_ix;
	}

	friend std::ostream & operator<<(std::ostream & os,const Point & rhs);

private:
	double _ix;
	double _iy;
};


std::ostream & operator<<(std::ostream & os, const Point & rhs)
{
	cout << "(" <<rhs._ix
		 << "," <<rhs._iy
		 << ")" ;
	return os;
}

int main()
{
	Point pt(1.2, 2.2);
	cout << "pt.func()= " << pt.func<int>() << endl;//显式为int型
	cout << "pt.func()= " << pt.func() << endl; //默认为int型
	return 0;
}
