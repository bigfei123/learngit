 ///
 /// @file    Line.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-09 08:15:38
 ///
#include <math.h> 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point(int ix=0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int=0,int=0)" << endl;
	}

	void setX(int ix)
	{
		_ix = ix;
	}

	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")"; 
	}

private:
	int _ix;
	int _iy;
};

class Line
{
public:
	Line(int x1, int y1, int x2, int y2)
	: _pt1(x1, y1) //如果自定义类类型创建的对象作为另一个自定义类类型的的子对象，需要显式在
				   //初始化列表之中进行初始化，除非想调用子对象相应类型的默认构造函数
	, _pt2(x2, y2)
	{
		cout << "Line(int,int,int ,int )" << endl;
	}

	void printLine()
	{
		_pt1.print();
		cout << "-->";
		_pt2.print();
		cout << endl;
	}
private:
	Point _pt1; //子对象的创建调用了默认构造函数
	Point _pt2;
};


int main(void)
{
	Line line(1, 2, 3, 4);
	line.printLine();
	return 0;
}

