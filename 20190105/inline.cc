#include <iostream>
using std::cout;
using std::endl;

//没有函数的开销，提高程序的执行效率
//同时又可以进行编译，安全性比带参数的宏定义高的多
#define multiply(x, y) ((x)*(y))

//函数调用是有开销的

//inline函数的效果与带参数的宏定义时一样的
//同时又可以进行编译，安全性比带参数的宏定义高的多

inline
int divide(int x, int y)
{
	return x/y;
}

int main(void)
{
	int a=3, b=4;
	cout << multiply(a, b)<< endl;
	cout << divide(a, b) << endl;
}
