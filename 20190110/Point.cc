 ///
 /// @file    Point.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-11 08:40:28
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class Point
{
public:
	//	explicit //   implicit, 想要禁止隐式转换，那就在相应的构造函数之前加上explicit
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int =0 , int =0)" << endl;
	}
	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

private:
	int _ix;
	int _iy;
};

int main(void)
{
	Point pt(1,2);
	pt.print();

	Point pt1 = 5;    //int --> Point 产生临时对象Point(5,0)
	pt1.print();
	return 0;
}
 
