 ///
 /// @file    Complex.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-13 12:09:53
 ///
#include <limits> 
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
	//前置++，后置++的区别？
	//1.前置++的返回值为引用，效率更高
	//	后置++的返回值为对象，效率较低
	Complex & operator++()
	{
		cout << "Complex & operator++()" << endl;
		++_dreal;
		++_dimag;
		return *this;
	}
	Complex operator++(int) //int参数没有实际意义，只有用来与前置++区分开,后置++返回的是零时变量，不能取地址
	{
		cout << "Complex operator++(int)" << endl;
		Complex tmp(*this);
		++_dreal;
		++_dimag;
		return tmp;
	}
	friend Complex operator+(const Complex & lhs, const Complex & rhs);

	friend std::ostream & operator<<(std::ostream & os,const Complex & rhs);
	friend std::istream & operator>>(std::istream & is,Complex & rhs);

	
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

std::ostream & operator<<(std::ostream & os, const Complex & rhs)
{
	if(rhs._dreal == 0 && rhs._dimag == 0) {
		os << 0;
	} else if(rhs._dreal == 0) {
		os << rhs._dimag << "i";
	} else {
		os << rhs._dreal;
		if(rhs._dimag > 0)
			os << " + " << rhs._dimag << "i";
		else if(rhs._dimag < 0)
			os << " - " <<(-1) * rhs._dimag << "i";
	}
	return os;
}

void readDouble(std::istream & is, double & number)
{
	cout << ">> pls input a valid number : " << endl;
	while(is >> number, !is.eof()){
		if(is.bad()) {
			cout << "istream is has broken! " << endl;
			return ;
		} else if(is.fail()) {
			is.clear();
			is.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			cout << ">> pls input a valid number:" << endl;
			continue;
		}
		cout << "number = " << number << endl;
		break;
	}
}

std::istream & operator>>(std::istream & is, Complex & rhs)
{
	//is >> rhs._dreal >> rhs._dimag;   //error 要考虑意外情况
	readDouble(is, rhs._dreal);
	readDouble(is ,rhs._dimag);
	return is;
}


int test0()
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

	cout<< endl << "执行c1+=c2之后："<< endl;
	c1 += c2;

	cout << endl << "执行前置，后置表达式" << endl;
	cout << "++c1 = " ;
	(++c1).print();
	cout << "c1 = " ;
	c1.print();
	cout << endl;

	cout << "c1++ = ";
	(c1++).print();
	cout << "c1 = ";
	c1.print();
	cout << endl;
	return 0;
}

void test1()
{
	Complex c1(-1, -2);
	cout << "c1 = " << c1 << endl; //链式编程
	(operator<<(operator<<(cout , "c1 ="),c1));

	Complex c2(0, -2);
	cout << "c2 = " << c2 << endl; //链式编程

	Complex c3(0, 0);
	cout << "c3 = " << c3 << endl; //链式编程

	Complex c4(1, 2);
	cout << "c4 = " << c4 << endl; //链式编程

	Complex c5(1, 0);
	cout << "c5 = " << c5 << endl; //链式编程

	cout << ">> pls input a complex:" << endl;
	std::cin >>c5;
	cout << "c5= " << c5 <<endl;
}

int main(void)
{
	//test0();
	test1();
	return 0;
}
 
