 ///
 /// @file    struct.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-07 20:37:13
 ///
 
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

struct Computer
{
	//对于struct而言，默认访问权限是public
	void setBrand(const char *brand)
	{
		strcpy(_brand,brand);
	}

	void setPrice(float price)
	{
		_price = price;
	}

	void print()
	{
		cout << "brand:" << _brand << endl
			 << "price:" << _price << endl;
	}
	char _brand[20];
	float _price;
};


int main(void)
{
	Computer computer;
	computer.setBrand("Lenovo");
	computer.setPrice(5555);
	computer.print();

	computer._price=8888;
	computer.print();
}

	 
