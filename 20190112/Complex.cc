 ///
 /// @file    Complex.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-13 12:09:53
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Complex
{
public:
	Complex(double dreal = 0, double dimag = 0)
	: _dreal(dreal)
	, _dimag(dimag)
	{
		cout << "Complex(double, double)" << endl;
	}
	
	void print() const
	{
		cout << _dreal << " + " << _dimag << "i" << endl;
	}
	double getReal() const { return _dreal; }
	double getImage() const { return _dimag; }

private:
	double _dreal;
	double _dimag;

};
//内置类型的运算符不能重载
//int operator+(int x, int y)
//{
//	return x-y;
//}

//普通函数形式进行重载
Complex operator+(const Complex & lhs, const Complex & rhs)
{
	cout << "Complex operator+(const Complex&, const Complex &);" << endl;
	return Complex(lhs.getReal() + rhs.getReal(),
				   lhs.getImage() + rhs.getImage());

}

int main(void)
{
	Complex c1(1, 2);
	cout << "c1 = ";
	c1.print();
	Complex c2(3, 4);
	cout << "c2 = ";
	c2.print();

	Complex c3 = c1 + c2;
	cout << "c3 = ";
	c3.print();

	return 0;
}
 
