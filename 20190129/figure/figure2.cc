 ///
 /// @file    figure2.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-31 13:27:42
 ///
 
#include <math.h>
#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using std::function;
using std::bind;

//用基于对象的方式实现多态；
//	std::function + std::bind 结合实现多态
//
//在使用上更加灵活多变，限制更少

//具体类
class Figure
{
public:
	using DisplayCallback = function<void()>;
	using AreaCallback = function<double()>;
	
	void setDisplayCallback(DisplayCallback && cb)
	//std::move 将左值引用转化为右值引用
	{	_displayCallback = std::move(cb);	}

	void setAreaCallback(AreaCallback && cb)
	{	_areaCallback = std::move(cb);	}

	void handleDisplayCallback() const
	{
		if(_displayCallback)
			_displayCallback();
	}

	double handleAreaCallback() const
	{
		if(_areaCallback)
			return _areaCallback();
		else
			return 0;
	}

	DisplayCallback _displayCallback;
	AreaCallback _areaCallback;
};

class Rectangle
: public Figure
{
public:
	Rectangle(double length, double width)
	: _length(length)
	, _width(width)
	{}

	void display() const 
	{	cout << "rectangle";	}

	double area() 
	{	return _length * _width;	}
private:
	double _length;
	double _width;
};

class Circle
: public Figure
{
public: 
	Circle(double radius)
	: _radius(radius)
	{}

	void display() const 
	{	cout << "circle" ;	}

	double area() 
	{	return PI * _radius * _radius; }
private:
	const double PI = 3.14;
	double _radius;
};

class Triangle
: public Figure
{
public:
	Triangle(double a, double b, double c)
	: _a(a)
	, _b(b)
	, _c(c)
	{}

	void display() const 
	{	cout << "tritangle" ;	}

	double area() 
	{	
		double p = (_a + _b + _c)/2;
		return sqrt(p * (p - _a) * (p - _b) * (p - _c));
	}
private:
	double _a;
	double _b;
	double _c;
};

void display(const Figure & fig)
{
	fig.handleDisplayCallback();
	cout << "'s area is " << fig.handleAreaCallback() << endl;
}

int main(void)
{
	Rectangle rectangle(10, 11);
	Circle circle(5);
	Triangle triangle(3, 4, 5);

	Figure figure;
	figure.setDisplayCallback(std::bind(&Rectangle::display, &rectangle));
	figure.setAreaCallback(std::bind(&Rectangle::area, &rectangle));
	display(figure);
	
	figure.setDisplayCallback(std::bind(&Circle::display, &circle));
	figure.setAreaCallback(std::bind(&Circle::area, &circle));
	display(figure);
 
	figure.setDisplayCallback(std::bind(&Triangle::display, &triangle));
	figure.setAreaCallback(std::bind(&Triangle::area, &triangle));
	display(figure);

	return 0;
}
