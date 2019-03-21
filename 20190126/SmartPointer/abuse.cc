///
/// @file    abuse.cc
/// @author  bigfei775655478@qq.com)
/// @date    2019-02-01 19:51:45
///

#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;
using std::shared_ptr;

class Point
: public std::enable_shared_from_this<Point>
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{	cout << "Point(int=0,int =0)" << endl;	}

	void display() const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	~Point() {	cout << "~Point()" << endl;	}


	//Point * addPoint(Point * pt)
	//shared_ptr<Point> addPoint(Point * pt)
	shared_ptr<Point> addPoint(Point * pt)
	{ // 在类内部获取本对象的shared_ptr智能指针
		_ix += pt->_ix;
		_iy += pt->_iy;

		return shared_ptr<Point>(this);//this是原生裸指针
		//return shared_from_this();//this是原生裸指针
	}
private:
	int _ix;
	int _iy;
};

void test0()
{
	//将一个原生的裸指针交给不同的智能指针进行托管
	Point * pt = new Point(1, 2);

	unique_ptr<Point> up1(pt);
	unique_ptr<Point> up2(pt);
}

void test1()
{
	unique_ptr<Point> up1(new Point(1, 2));
	unique_ptr<Point> up2(new Point(3, 4));

	up2.reset(up1.get());
}

void test2()
{
	shared_ptr<Point> up1(new Point(1, 2));
	cout << "*up1 = ";
	up1->display();
	shared_ptr<Point> up2(new Point(3, 4));
	cout << "*up2 = ";
	up2->display();

	shared_ptr<Point> up3(up1->addPoint(up2.get()));
	cout << "*up3 = ";
	up3->display();
}

int main(void)
{
	//test0();
	//test1();
	test2();
	return 0;
}
