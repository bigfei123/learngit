 ///
 /// @file    singletontest.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-20 23:15:47
 ///
#include "Singleton.h" 
#include <cstring>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

class Point
{
public:
	Point();
	Point(int ix, int iy);
	~Point();
	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);

private:
	int _ix;
	int _iy;
};

class Computer
{
public:
	Computer();
	Computer(string brand, float price);
	~Computer();
	friend std::ostream & operator<<(std::ostream & os, const Computer & rhs);

private:
	string _brand;
	float _price;
};

Point::Point()
{}

Point::Point(int ix, int iy)
: _ix(ix)
, _iy(iy)
{	cout << "Point() " << endl;}

Point::~Point()
{	cout << "~Point() " << endl;	}

std::ostream & operator<<(std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")" ;
	return os;
}

Computer::Computer()
{}

Computer::Computer(string brand, float price)
: _brand(brand)
, _price(price)
{
	cout << "Computer(string , float)" << endl;
}

Computer::~Computer()
{
	cout<< "~Computer()" << endl;
}

std::ostream & operator<<(std::ostream & os, const Computer & rhs)
{
	os << "brand: " << rhs._brand << endl
	   << "price: " << rhs._price << endl;
	return os;
}	

int main()
{
	
	Point * p1 = Singleton<Point>::getInstance(1, 2);
	Point * p2 = Singleton<Point>::getInstance(3, 4);

	Computer * p3 = Singleton<Computer>::getInstance("xiaomi",6666);
	Computer * p4 = Singleton<Computer>::getInstance("huawei",7777);
	Computer * p5 = Singleton<Computer>::getInstance();

	cout << *p1	<< endl;
	cout << *p2 << endl;
	cout << *p3 << endl;
	cout << *p4 << endl;
	cout << *p5 << endl;

}
