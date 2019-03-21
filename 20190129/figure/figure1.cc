 ///
 /// @file    figure1.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-31 13:09:20
 ///
 
#include <math.h>
#include <iostream>
using std::cout;
using std::endl;
 
//面向对象设计原则：
//	对扩展开放，对修改关闭
//
//	动态多态的实现：继承 + 虚函数 

class Figure
{
public:
	virtual void display() const = 0;
	virtual double area() = 0;

};

void display(Figure & fig)
{
	fig.display();
	cout << "'s area is " << fig.area() << endl;
}

class Rectangle
: public Figure
{
public:
	Rectangle(double length, double width)
	: _length(length)
	, _width(width)
	{}

	void display() const override
	{	cout << "rectangle";	}

	double area() override
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

	void display() const override
	{	cout << "circle" ;	}

	double area() override
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

	void display() const override
	{	cout << "tritangle" ;	}

	double area() override
	{	
		double p = (_a + _b + _c)/2;
		return sqrt(p * (p - _a) * (p - _b) * (p - _c));
	}
private:
	double _a;
	double _b;
	double _c;
};

int main()
{
	Rectangle rectangle(10, 11);
	Circle circle(5);
	Triangle triangle(3, 4, 5);

	display(rectangle);
	display(circle);
	display(triangle);
}
