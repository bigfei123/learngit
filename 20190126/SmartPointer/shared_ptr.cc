 ///
 /// @file    shared_ptr.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-01 17:47:50
 ///
 
#include <iostream>
#include <memory>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::shared_ptr;
 
class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{	cout << "Point(int,int)" << endl;}

	void display() const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	~Point()
	{  cout << "~Point()" << endl;	}

private:
	int _ix;
	int _iy;
};

int main()
{
	shared_ptr<int> up(new int(10));
	cout << "*up = " << *up << endl;
	cout << "up's get() = " << up.get() << endl;
	cout << "up's use_count = " << up.use_count() << endl;

	cout << ">>>up2" << endl;
	shared_ptr<int> up2(up); //共享所有权的指针
							 //进行复制或者赋值时，将引用计数+1
							 //当up2被销毁时，引用计数-1
	cout << "*up = " << *up << endl;
	cout << "up's get() = " << up.get() << endl;
	cout << "up's use_count = " << up.use_count() << endl;
	cout << "*up2 = " << *up2 << endl;
	cout << "up2's get() = " << up2.get() << endl;
	cout << "up2's use_count = " << up2.use_count() << endl;

	cout << ">>>up3" << endl;
	shared_ptr<int> up3(new int(1));
	up3 = up;
	cout << "*up = " << *up << endl;
	cout << "up's get() = " << up.get() << endl;
	cout << "up's use_count = " << up.use_count() << endl;
	cout << "*up3 = " << *up3 << endl;
	cout << "up3's get() = " << up3.get() << endl;
	cout << "up3's use_count = " << up3.use_count() << endl;
	
	cout << ">>>up4" << endl;
	shared_ptr<int> up4(std::move(up));//通过移动语义转移资源的所有权
									   //具有移动语义	
	cout << "*up4= " << *up4<< endl;
	cout << "up4's get() = " << up4.get() << endl;
	cout << "up4's use_count = " << up4.use_count() << endl;
	cout << "*up3 = " << *up3 << endl;
	cout << "up3's get() = " << up3.get() << endl;
	cout << "up3's use_count = " << up3.use_count() << endl;

	shared_ptr<Point> sp(new Point(3, 4));
	sp->display();
	vector<shared_ptr<Point>> points;
	points.push_back(shared_ptr<Point>(new Point(1, 2)));
	points.push_back(sp);
	
	return 0;
}
