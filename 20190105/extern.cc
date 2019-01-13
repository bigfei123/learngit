#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

//用c++的方式调用：进行名字改编
//用nm a.out查看名字改编
#ifdef __cplusplus//如果采用了c++，如下代码使用c编译器
extern "C"		  //如果没有采用c++，如下代码使用顺序按c编译器
{
#endif

//用c的方式调用：不进行名字改编
int add(int x, int y)//此段代码用c编译，add不进行名字改编
{
	return x + y;
}

#ifdef __cplusplus
}
#endif

int add(int x, int y, int z)//如下代码用c++编译，add进行名字改编为addiii
{
	return x + y + z;
}

double add(double x, int y)//名字改编为adddi
{
	 return x+ y;
}

double add(int x, double y)//名字改编为addid
{
	return x + y;
}

double add(double x, double y)//名字改编为adddd
{
	return x + y;
}

int main(int argc, char ** argv)
{
	int a=3, b=4, c=5;
	printf("add(a, b)=%d\n",add(a, b));
	cout<< "add(a, b, c)= "<< add(a, b, c) <<endl;

	int *pInt=static_cast<int*>(malloc(sizeof(int)));
	*pInt=10;

	free(pInt);
	return 0;
}

