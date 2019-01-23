#ifndef __COMPUTER_H__
#define __COMPUTER_H__

#include <iostream>
using std::cout;
using std::endl;

class Computer
{
public:
	Computer(const char *brand, float price);
	Computer(const Computer & rhs);

	void print();

	~Computer();

	void setBrand(const char * brand);
	void setPrice(float price);


private:
	char * _brand;
	float _price;
};

#endif



