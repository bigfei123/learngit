 ///
 /// @file    Computer2.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-08 19:52:26
 ///
#include "Computer.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

//Computer类的构造函数的实现：
Computer::Computer(const char*brand,float price)
: _brand(new char[strlen(brand)+1]())
, _price(price)
{
	//cout << "sizeof(brand)=" << sizeof(brand) << endl;
	strcpy(_brand, brand);
	cout << "Computer(const char *,float) " << endl;
}

//系统提供的copy constructor不能满足需求
//Computer::Computer(const Computer &rhs)
//: _brand(rhs._brand) //浅拷贝
//,_price(rhs._price)
//{
//   cout << " Computer(const Computer & rhs)" << endl;
//}


//浅拷贝只是简单的进行了字符串
Computer::Computer(const Computer &rhs)
: _brand(new char [strlen(rhs._brand)+1]())
, _price(rhs._price)
{
	strcpy(_brand,rhs._brand);//深拷贝
	cout << "Computer(const Computer & rhs)" << endl;
}

Computer::~Computer()
{
	 // 系统提供的析构函数不够用了
	  delete [] _brand;
	  cout << "~Computer()" << endl;
}
//在类之外定义成员函数
void Computer::setBrand(const char * brand)
{
	//重设Brand的值：
	//1.若新Brand的字符串长度小于旧Brand的字符串长度则直接赋值
	//2.若新Brand的字符串长度大于旧Brand的字符串长度则delete原来
	//的空间，开辟一个更大的空间
	size_t len = strlen(_brand);
	if(len > strlen(brand))
		strcpy(_brand, brand);
	else {
		delete [] _brand;
		_brand = new char [strlen(brand) +1]();
		strcpy(_brand,brand);
	}
}

void Computer::setPrice(float price)
{
	_price = price;
}

void Computer::print()
{
	printf("_brand:%p\n", _brand);
	cout << " brand:"<< _brand<< endl
	     << "price:" << _price << endl;
}


