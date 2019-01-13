 ///
 /// @file    Point.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-09 07:45:07
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
class Point
{
public:
	Point(int ix=0, int iy=0)
	: _ix(ix)    //const成员的初始化只能放在初始化表达式中
	, _iy(iy)
	{
		cout << "Point(int =0,int=0)" << endl;
	}

//	void setX(int ix)
//	: _ix(ix)
//	{
//		cout << "setX finish" << endl;
//	}

	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

private:
	const int _ix;
	const int _iy;
};



int main(void)
{
	Point pt(1,2);
	pt.print();
//	pt.setX(10);
	return 0;
}


 
