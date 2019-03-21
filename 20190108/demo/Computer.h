 ///
 /// @file    Computer.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-09 08:30:02
 ///
#ifndef __COMPUTER_H__
#define __COMPUTER_H__

#include <iostream>
using std::cout;
using std::endl;

class Computer
{
public:
	//Computer() =default;
	
	Computer(const char * brand, float price);

	Computer(const Computer & rhs);

	Computer & operator= (const Computer & rhs);

	//两个print能够进行重载
	//
	//如果两个都不会对数据成员进行操作,那优先定义const版本成员函数
	//
//	void print();
	
	void print() const;

	static void printTotalPrice();

	~Computer();

	void setBrand(const char * brand);
	void setPrice(float price);
private:
	char *_brand;  
	float _price;
	static float _totalPrice;   // 位于全局静态区，被该类的所有对象共享
};
//float Comuter::_price = 0; //非静态的不行
  

#endif

