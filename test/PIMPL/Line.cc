 ///
 /// @file    Line.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-05 15:42:16
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
		cout << "LineImpl()" << endl;
	}
	~LineImpl()
	{
		cout << "~LineImpl()" << endl;
	}

	void printLine() const
	{
		_pt1.printPoint();
		cout << "---->" ;
		_pt2.printPoint();
		cout << endl;
	}

private:
	class Point
	{
	public:
		Point(int ix, int iy)
		: _ix(ix)
		, _iy(iy)
		{
			cout << "Point(int, int)" << endl;
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
	cout << "Line()" << endl;
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
