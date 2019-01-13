 ///
 /// @file    TestComputer.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-09 09:37:32
 ///
#include "Computer.h" 
#include <iostream>
using std::cout;
using std::endl;

int test0(void)
{
	Computer computer("Lenovo Thinkpad",8888);
	computer.print();
	cout << endl;
	
	Computer *pc =new Computer("Macbook pro",11111);
	pc->print();

	delete pc;

	return 0;
}

void test1()
{
	Computer com1("Thinkpad",6666);
	cout << ">> com:" << endl;
	com1.print();

	Computer com2 = com1;
	cout <<" >> 修改com1的brand " << endl;
	com1.setBrand("xiaomi");
	cout <<">> com1:" << endl;
	com1.print();

	cout << endl << ">> com2:" << endl;
	com2.print();
}

void test2(void)
{
	Computer com1("Thinkpad", 6666);
	cout << ">>com1: " << endl;
	com1.print();

	Computer com2("xiaomi",8888);
	cout << ">> com2:" << endl;
	com2.print();

	com2=com1;
	cout << endl << ">>> 执行com2 =com1赋值运算符函数之后: " <<endl;
	cout << endl << ">> com2:" << endl;
	com2.print();

	cout << endl << " >> 修改com1的brand" << endl;
	com1.setBrand("xiaomi");
	cout << ">> com1:" << endl;
	com1.print();

	cout << endl << ">>com2:" << endl;
	com2.print();

	com2=com2;
}

void test3()
{
	cout << "sizeof(Computer) = " << sizeof(Computer) << endl;

	cout << "购买电脑之前：";
	Computer::printTotalPrice();
	cout << endl;

	Computer com1("Thinkpad",6666);
	cout << "购买第一台电脑：" ;
	com1.print();
	com1.printTotalPrice();
	Computer::printTotalPrice();   //静态成员函数可以直接通过类名调用，不需要创建对象
	cout << endl;	
	Computer com2("Matebook" ,7777);
	cout << "购买第二台电脑：";
	com2.print();
	Computer::printTotalPrice();

}

	void func(const Computer & rhs)
	{
		rhs.print();
	}

	void test4()
	{
		Computer com1("Thinkpad" , 6666);
		com1.print();  //非const对象 可以调用const成员函数

		const Computer com2("Matebook",7777);
		com2.print();    //const 对象只能调用const成员函数，不能调用非const成员函数
	}





int main(void)
{
//	test1(); 
	test2();
//	test3();
//	test4();
	return 0;
}

 
