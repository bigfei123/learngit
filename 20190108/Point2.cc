 ///
 /// @file    Point2.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-09 08:05:52
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
class Point2
{
public:
	Point2(int ix=0, int iy=0)
	: _ix(ix)  //引用成员的初始化只能放在初始化表达式中
	, _iy(iy)
	, _ref(_ix)
	{
		cout << "Point2(int=0 , int =0)" << endl;
	}

	void setX(int ix)
	{
		_ix = ix;
	}

	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << "," << _ref
			 << ")" << endl;
	}

private:
	int _ix;
	int _iy;
	int & _ref;   //引用成员占据一个指针的大小
};


int main(void)
{
	cout << "sizeof(Point) = " << sizeof(Point2) << endl;
	Point2 pt(1,2);
	pt.print();
	pt.setX(10);
	pt.print();
	return 0;
}
