#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

//int add(int x, int y)
//{
//	return x+ y;
//}

int add(int x=0, int y=0, int z=0)
{
	return x+y+z;
}

int main(int argc ,char ** argv)
{
	int a=3, b=4 ,c=5;
	cout << "add()=" << add() << endl;
	cout << "add(a)=" << add(a) << endl;
	//printf("add(a, b)=%d\n",add(a, b));//缺省参数 
	cout << "add(a, b)=" << add(a, b) << endl;
	cout << "add(a, b, c) =" << add(a, b, c) <<	endl;


	int *pInt= static_cast<int*>(malloc(sizeof(int)));
	*pInt =10;

	free(pInt);

	return 0;
}
