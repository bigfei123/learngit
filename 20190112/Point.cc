 ///
 /// @file    Point.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-13 10:24:25
 ///
 
#include <math.h>
#include <iostream>
using std::cout;
using std::endl;
 
class Point
{
	//友元不受访问权限的限制,声明在public,private之下都可以
	//友元之普通函数
	friend float distance(const Point & lhs, const Point & rhs);
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int, int)" << endl;
	}

	void print() const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")"; 
	}

private:
	int _ix;
	int _iy;
};

float distance(const Point & lhs, const Point & rhs)
{
	//return sqrt(pow((lhs._ix-rhs._ix),2)+pow(lhs._iy-rhs._iy));
	return hypot(lhs._ix - rhs._ix, lhs._iy - rhs._iy);
}
int main(void)
{
	Point pt1(1, 2);
	Point pt2(3, 4);

	pt1.print();
	cout << " --> ";
	pt2.print();
	cout << "的距离：" << distance(pt1, pt2) << endl;
	return 0;
 
}
