 /// @file    io1.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-10 21:12:47
 ///
#include <string>
#include <limits>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::cin;
void printCinStatus()
{
	cout << "cin's badbit = " << cin.bad() << endl
		 << "cin's failbit= " << cin.fail() << endl
		 << "cin's eofbit = " << cin.eof() << endl
		 << "cin's goodbit= " << cin.good() << endl;
}

void test0()
{
	//流对象内部都有缓冲区
	cout << "sizeof(cin) = " << sizeof(cin) << endl;
	cout << "sizeof(cout) = " << sizeof(cout) <<endl;
	int number =10;
	printCinStatus();

	//逗号表达式,逗号后的值为表达式的值，若输入Ctrl+D,则cin.eof为1，while(0)结束循环
	while(cin >> number , !cin.eof()) // 如果输入的数据不是数字，流的状态goodbit位由1变为0
	{								  // failbit位由0变为1，此时陷入死循环
		cout << "number =" << number << endl;
//		cin.clear();  //重置流的状态
		//表示从输入流 cin 中提取字符，提取的字符不是数字，不被使用
//		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//清空缓冲区
		printCinStatus();
	}
}	
void test1()
{
	int number= 10;
	cin >> number;
	cout << "number = " << endl;
	printCinStatus();

	//cin.clear(); //重置流的状态
	cout << "重置流的状态" << endl;
	printCinStatus();
	//cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');//清空缓冲区
	string s1;
	cin >> s1;
	printCinStatus();
	cout << "s1= " << s1 << endl;
}
int main(void)
{
	test0();
//	test1();
	return 0;
 
}
