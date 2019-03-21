 ///
 /// @file    unique_ptr.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-01 17:47:50
 ///
 
#include <iostream>
#include <memory>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::unique_ptr;
 
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
	unique_ptr<int> up(new int(10));
	cout << "*up = " << *up << endl;
	cout << "up's get() = " << up.get() << endl;

	//unique_ptr<int> up2(up); //独享所有权的指针
	//
	unique_ptr<int> up3(new int(1));
	cout << "*up3= " << *up3<< endl;
	cout << "up3's get() = " << up3.get() << endl;
	//up3 = up; //error
	unique_ptr<int> up4(std::move(up));//通过移动语义转移资源的所有权

	cout << "*up4 = " << *up4 << endl;
	cout << "up4's get() = " << up4.get() << endl;
	
	vector<unique_ptr<int>> numbers;
	numbers.push_back(std::move(up4));

	vector<unique_ptr<Point>> points;
	points.push_back(unique_ptr<Point>(new Point(1, 2)));
	
	return 0;
}	
