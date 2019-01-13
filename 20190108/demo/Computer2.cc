 ///
 /// @file    Computer2.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-10 08:03:19
 ///
#include "Computer.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;


float Computer::_totalPrice= 0.0;
//自定义构造函数
Computer::Computer(const char * brand ,float price)
: _brand(new char[strlen(brand)+1]())
, _price(price)
{
	_totalPrice += _price;
	strcpy(_brand, brand);
	cout << "Computer(const char *, float)" << endl;
}
//深拷贝
Computer::Computer(const Computer & rhs)
: _brand(new char[strlen(rhs._brand)+1]())
, _price(rhs._price)
{
	strcpy(_brand,rhs._brand);
	cout << "Computer(const Computer & rhs)" << endl;
}
//赋值表达式
Computer & Computer::operator=(const Computer & rhs)
{
	if(this != &rhs)
	{
		//1.自复制
		delete[] _brand;  //2. 释放左操作数指针的堆空间

		_brand=new char[strlen(rhs._brand)+1]();
		strcpy(_brand,rhs._brand);

		_price=rhs._price;
	}
	return *this;
}

Computer :: ~ Computer()
{
	//系统提供的析构函数不够用了
	delete [] _brand;
	cout << "~Computer()" << endl;
	_totalPrice -=_price;
}

//在类之外定义成员函数
void Computer::setBrand(const char * brand)
{
	size_t len= strlen(_brand);
	if(len > strlen(brand))
		strcpy(_brand, brand);
	else
	{
		delete [] _brand;
		_brand = new char[strlen(brand)+1]();
		strcpy(_brand, brand);
	}
}

//静态成员函数没有隐含的this指针
//静态成员函数内部不能访问非静态成员数据和非静态成员函数
void Computer::printTotalPrice()
{
	cout << " total price:" << _totalPrice << endl;
}

#if 0
void Computer::print()
{
	cout << "void Computer::price()" << endl;
	printf(" _brand:%p\n", _brand);
	cout << "brand: " << _brand << endl
		 << "price: " << _price << endl;
}

#endif


#if 1
void Computer::print() const
{
	cout << "void Computer::print() const " << endl;
	printf(" _brand :%p\n" ,_brand);
	cout << "brand :" << _brand << endl
		 << "price :" << _price << endl;
}
#endif


