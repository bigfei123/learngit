 ///
 /// @file    TestComputer.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-08 20:08:49
 ///
#include "Computer.h" 
#include <iostream>
using std::cout;
using std::endl;

Computer gComputer("Mi",6666);

void test0(void)
{
	gComputer.print();
	cout << endl;
	
	Computer computer("Lenovo Thinkpad",8888);
	computer.print();
	cout << endl;

	computer.setBrand("Lenovo");
	computer.setPrice(5555);
	computer.print();
	//computer.~Computer();   //不要主动调用析构函数
	cout << endl;

	//指向对象的指针pc
	Computer * pc =new Computer("Macbook pro",11111);
	pc->print();
	delete pc; //记得delete
}

void test1(void)
{
	Computer com1("Thinkpad",6666);
	cout << ">> com1:" << endl;
	cout << "&com1 = " << &com1 << endl;
	com1.print();
	cout << endl;

	Computer com2 = com1;
	cout << ">> com2:" << endl;
	cout << "&com2 = " << &com2 << endl;
	com2.print();
	cout << endl;

	cout << ">>修改com1的brand" << endl;
	com1.setBrand("xiaomi");
	cout << ">>com1:"<< endl;
	com1.print();
	cout << endl;

	cout << ">>com2:" << endl;
	com2.print();
}

int main(void)
{

	//test0();
	test1();
	return 0;
} 
