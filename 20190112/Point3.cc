 ///
 /// @file    Point3.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-13 11:46:29
 ///
#include <math.h> 
#include <iostream>
using std::cout;
using std::endl;
class Point;//类的前向声明
//友元关系是单项的，不具备传递性，不能被继承
class Line
{
public:
	float distance(const Point & lhs, const Point & rhs);
	//该函数声明不需要知道Point的实现
	void setPoint(Point & pt, int ix, int iy);

#if 0
	void setZ(int iz)
	{
		_iz = iz;
	}

#endif

private:
	int _iz;
};

class Point
{
	//友元之友元类,该类中的所有成员都可以调用
	friend Line;
	//friend class Line;
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

//	void setLine(Line & line, int iz)
//	{
//		line._iz = iz;
//	}

	~Point()
	{	cout << "~Point()" << endl; }

private:
	int _ix;
	int _iy;
};

float Line::distance(const Point & lhs, const Point & rhs)
{
	return hypot(lhs._ix - rhs._ix, lhs._iy - rhs._iy);
}

void Line::setPoint(Point & pt, int ix, int iy)
{
	pt._ix = ix;
	pt._iy = iy;
}

int main(void)
{
	Point pt1(1, 2);
	Point pt2(3, 4);


	pt1.print();
	cout << " --> " ;
	pt2.print();
	cout << "的距离：" << Line().distance(pt1, pt2) << endl;
	Line().setPoint(pt1, 10 ,11);
	cout << "pt1 = ";
	pt1.print();
	return 0;
}
