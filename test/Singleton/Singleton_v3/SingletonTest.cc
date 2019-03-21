 ///
 /// @file    SingletonTest.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-07 15:19:32
 ///
 
#include "Singleton.h"
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
 
class Point
{
public:
	Point();

	~Point()
	{	cout << "~Point()" << endl; }

	Point(int ix, int iy)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int, int)" << endl;
	}

	friend std::ostream & operator<<(std::ostream & os, Point & rhs);


private:
	int _ix;
	int _iy;
};

class Computer
{
public:
	Computer();

	~Computer()
	{	cout << "~Computer()" << endl;  }

	Computer(string brand, float price)
	: _brand(brand)
	, _price(price)
	{
		cout << "Computer(string, float)" << endl;
	}

	friend std::ostream & operator<<(std::ostream & os, Computer & rhs);

private:
	string _brand;
	float _price;
};

std::ostream & operator<<(std::ostream & os, Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")" ;
	return os;
}

std::ostream & operator<<(std::ostream & os, Computer & rhs)
{
	os << "brand: " << rhs._brand << endl
	   << "price: " << rhs._price << endl;
	return os;
}

int main(void)
{
	Point * p1 = Singleton<Point>::getInstance(1, 2);
	Point * p2 = Singleton<Point>::getInstance(3, 4);

	Computer * p3 = Singleton<Computer>::getInstance("xiaomi", 6000);
	Computer * p4 = Singleton<Computer>::getInstance("nubia", 4000);

	cout << *p1 << endl;
	cout << *p2 << endl;
	cout << *p3 << endl;
	cout << *p4 << endl;
 
}
