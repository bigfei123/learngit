///
/// @file    figure.cc
/// @author  bigfei775655478@qq.com)
/// @date    2019-02-08 12:40:02
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


class Rectangle
: public Figure
{
public:
	Rectangle(double length, double width)
	: _length(length)
	, _width(width)
	{}

	void display() const override
	{	cout << "rectangle";}
	
	double area() override
	{
		return _length * _width;
	}
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
	{	cout << "circle";}

	double area() override
	{
		return PI * _radius * _radius;
	}
private:
	double _radius;
	static const double PI;
};

const double Circle::PI = 3.14159;

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
	{	cout << "triangle";}

	double area() override
	{
		double p = (_a + _b + _c) / 2;
		return sqrt(p *(p - _a) * (p -_b) * (p- _c));
	}
private:
	double _a;
	double _b;
	double _c;
};


void display(Figure * fig)
{
	fig->display();
	cout << "'s area is " << fig->area() << endl;
}

//简单工厂模式/静态工厂模式
//面向对象设计原则：
//1.违反了开放闭合原则
//2.单一职责原则

class FigureFactory
{
public:
	static Figure * createRectangle()
	{
		//load xml
		//parse xml
		//get parameter
		return new Rectangle(10, 11);
	}

	static Figure * createCircle()
	{
		//load xml
		//parse xml
		//get parameter
		return new Circle(11);
	}

	static Figure * createTriangle()
	{
		//load xml
		//parse xml
		//get parameter
		return new Triangle(3, 4, 5);
	}
};

int main(void)
{
	Figure * rectangle = FigureFactory::createRectangle();
	Figure * circle= FigureFactory::createCircle();
	Figure * triangle= FigureFactory::createTriangle();

	display(rectangle);
	display(circle);
	display(triangle);

}
