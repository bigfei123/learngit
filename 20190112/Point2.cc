 ///
 /// @file    Point2.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-13 10:39:16
 ///
#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

//Line类并不知道Point类的实现,需要类的前向声明
class Point;

class Line
{
public:
	float distance(const Point & lhs, const Point & rhs);
};

class Point
{
	//友元不受访问权限的限制,声明在public,private之下都可以
	//友元之成员函数
	friend float Line::distance(const Point & lhs, const Point & rhs);
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

	~Point()
	{	cout << "~Point()" << endl; }

private:
	int _ix;
	int _iy;
};


float Line::distance(const Point & lhs, const Point & rhs)
{
	//return sqrt(pow((lhs._ix-rhs._ix),2)+pow(lhs._iy-rhs._iy));
	return hypot(lhs._ix - rhs._ix, lhs._iy - rhs._iy);
}



int main(void)
{
	Point(); //匿名对象，临时对象|作用是方便调用成员函数
	Point pt0;
	pt0.print();
	cout << endl;

	Point pt1(1, 2);
	Point pt2(3, 4);

	pt1.print();
	cout << "--> " ;
	pt2.print();
	
	//Line ln;
	//cout << "的距离: " << ln.distance(pt1, pt2) << endl;
	//Line()临时对象调用distance()成员函数
	cout << "的距离: " << Line().distance(pt1, pt2) << endl;
	return 0; 
}
