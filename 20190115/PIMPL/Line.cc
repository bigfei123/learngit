 ///
 /// @file    Line.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-17 12:01:46
 ///
#include "Line.h" 
#include <iostream>
using std::cout;
using std::endl;


class Line::LineImpl
{
public:
	LineImpl(int x1, int y1, int x2, int y2)
	: _pt1(x1, y1)
	, _pt2(x2, y2)
	{
		cout << "LineImpl(int ,int int int )" << endl;
	}

	~LineImpl()
	{	cout << "~LineImpl()" << endl;	}

	void printLine() const
	{
		_pt1.printPoint();
		cout << "--->" ;
		_pt2.printPoint();
		cout << endl;
	}
private:
	//嵌套类、类中类、内部类
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
			cout << "Point(int, int ) " <<endl;
		}

		void printPoint() const
		{
			cout << "(" << _ix
				 << "," << _iy
				 << ")" ;
		}

	private:
		int _ix;
		int _iy;
	};
private:
	Point _pt1;
	Point _pt2;
};

Line::Line(int x1, int y1, int x2, int y2)
: _pimpl(new LineImpl(x1, y1, x2, y2))
{
	cout << "Line(int,int,int,int)" << endl;
}

Line::~Line()
{
	delete _pimpl;
	cout << "~Line()" << endl;
}

void Line::printLine() const
{
	_pimpl -> printLine();
}
