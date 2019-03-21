 ///
 /// @file    Point3D.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-30 08:28:52
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

	int getY() const {	return _iy;	}

protected:
	int _ix; //对其派生类开放
private:
	int _iy;//私有成员只能在本类内部进行访问
};

class Point3D
: public Point //public 继承--->接口继承 
{
public:
	Point3D(int ix = 0, int iy = 0, int iz = 0)
	: Point(ix, iy)
	, _iz(iz)
	{
		cout << "Point3D(int,int,int)" << endl;
	}

	void display() const
	{
		cout << "(" << _ix   //基类protected型的成员在派生类内部可以直接访问
			 //<< "," << _iy 基类私有成员不能在派生类内部直接访问
			 << "," << getY()
			 << "," << _iz
			 << ")" << endl;
	}
private:
	int _iz;
};

int main()
{
	Point3D pt3d(2, 3, 5);
	//pt3d._ix;    ///对于基类非公有的成员，派生类对象都不能直接访问
	pt3d.getY();   //对于派生类对象而言，只能访问基类的public成员
	pt3d.display();
}
