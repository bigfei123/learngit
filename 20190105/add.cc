#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

//用c的方式调用：不进行名字改编
//
//用c++的方式调用：进行名字改编

int add(int x, int y)
{
	return x+y;
}

int add(int x, int y, int z)
{
	return x+y+z;
}

double add(double x, double y)
{
	return x+y;
}

double add(double x, int y)
{
	return x+y;
}

double add(int x, double y)
{
	return x+y;
}

int main(int argc, char **argv)
{
	int a=3, b=4, c=5;
	printf("add(a,b)=%d\n",add(a,b));
	cout<<"add(a,b,c)="<<add(a,b,c)<<endl;
	
	int *pInt= static_cast<int*>(malloc(sizeof(int)));
	*pInt=10;

	free(pInt);
	return 0;
}
	









