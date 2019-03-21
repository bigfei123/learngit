 ///
 /// @file    point.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-08 21:30:00
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point;

class Complex
{
	friend Point;
public:
	Complex(double dreal = 0, double dimag = 0)
	: _dreal(dreal)
	, _dimag(dimag)
	{
		cout << "Complex(double, double)" << endl;
	}
	
	void print() const
	{
		if(_dreal == 0 && _dimag == 0) {
			cout << 0 << endl;
			return ;
		}else if(_dreal == 0) 
		{
			cout << _dimag << "i" << endl;
		}else{ //_dreal != 0
			cout << _dreal;
			if(_dimag > 0)
				cout << " + " << _dimag << "i" << endl;
			else if(_dimag < 0)
				cout << " -" << (-1) * _dimag << "i" << endl;
			else
				cout << endl;
			}
	}
	//复合赋值运算符推荐以成员函数形式重载
	Complex & operator+=(const Complex & rhs)
	{
		cout << "Complex & operator+=(const Complex &)" << endl;
		_dreal += rhs._dreal;
		_dimag += rhs._dimag;
		return *this;
	}
	friend Complex operator+(const Complex & lhs, const Complex & rhs);

	friend std::ostream & operator<<(std::ostream & os,const Complex& rhs);
	friend std::istream & operator>>(std::istream & is,Complex& rhs);

private:
	double _dreal;
	double _dimag;

};
//推荐以友元函数形式进行重载，最简洁的方式
//而且与内置类型的数据在操作形式上保持一致
Complex operator+(const Complex & lhs, const Complex & rhs)
{
	cout << "Complex operator+(const Complex&, const Complex &);" << endl;
	return Complex(lhs._dreal + rhs._dreal,lhs._dimag + rhs._dimag);
	
}

std::ostream & operator<<(std::ostream & os, const Complex &rhs)
{
	if(rhs._dreal == 0 && rhs._dimag ==0) {
		os << 0;
	} else if(rhs._dreal == 0){
		os << rhs._dimag << "i";
	}else {
		os << rhs._dreal;
		if(rhs._dimag > 0)
			os << " + " << rhs._dimag << "i";
		else if(rhs._dimag < 0)
			os << " - " << (-1) * rhs._dimag << "i";
	}
	return os;
}


class Point
{
public:
	Point()
	: _ix(0)
	, _iy(0)
	{
		cout << "Point()" << endl;
	}

	Point(int ix, int iy=0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int ,int)" << endl;
	}

	Point(const Complex & rhs)
	: _ix(rhs._dreal)
	, _iy(rhs._dimag)
	{
		cout << "Point(const Complex &) " << endl;
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}


	//类型转换函数；
	//> 是一个成员函数
	//> 没有返回值形式，但在函数体内必须以传值的方式返回一个目标类型的变量
	//> 没有参数
	//> 一般情况下，不推荐使用，违反常规思维
	operator int()
	{	
		return _ix * _iy;	
		cout << " operator int() " <<endl;
	}

	operator double()
	{	
		return _ix + _iy;	
		cout << " operator double() " <<endl;
	}

	operator Complex()
	{	
		return Complex(_ix, _iy);	
		cout << " operator Complex() " << endl;
	}
	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);

private:
	int _ix;
	int _iy;
};

std::ostream & operator<<(std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")" ;
	return os;
}

void test0()
{
	Point pt (1, 2);
	cout << "pt = " << pt <<endl;

	Point pt2 = 1; //隐式转换,通过构造函数完成  由其他类型向自定义类型转换
	cout << "pt2 = " << pt2 << endl;

	Complex c1(-1, 2);
	pt2 = c1;  //通过构造函数完成
	cout << "pt2 = " << pt2 << endl;
	
	//有自定义类型向其他类型进行转换
	cout << endl << " >>类型转换函数" <<endl;
	int x = pt;
	cout << "x = " << x << endl;
	double y = pt;
	cout << "y = " << y << endl;
	Complex c2 = pt;
	cout << "c2 = " << c2 << endl;
}

int main(void)
{
	test0();
	return 0;
}
