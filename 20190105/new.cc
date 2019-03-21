#include <stdlib.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;


//new/delete与malloc/free的差别
//相同点：
//	1。都是同来申请堆空间
//	2。必须成对出现，否则就会有内存泄漏
//不同点：
//	1。new/delete是表达式，malloc/free是库函数
//  2. new表达式在开辟空间的同时可以初始化空间；
//		malloc在开辟堆空间时，只申请空间，不会初始化空间


int * test0(void)
{
	int *pInt =(int *)malloc(sizeof(int));
	memset(pInt,0,sizeof(int));
	*pInt=10;
	cout << "*pInt= " << *pInt <<endl;
	cout << "pInt ="<< pInt<< endl;
	cout << "&pInt="<<(&pInt) <<endl;

	//free([Int); //释放空间

	int *pArray=(int *)malloc(sizeof(int)*10);
	memset(pInt, 0, sizeof(int)* 10);

	free(pArray);
	return pInt;
}

void test1()
{
	int *pInt=new int(10);
	cout <<"*pInt=" << *pInt<< endl;
	cout << "pInt=" << pInt<< endl;
	cout << "&pInt="<<(&pInt) << endl;

	delete pInt;

	int *pArray=new int[10]();//c++开辟数组的方式
	pArray[0]=1;

	delete [] pInt;

}

int main(void)
{
	int * p1= test0();
	cout <<"*p1=" << *p1<< endl;
	cout << "p1=" << p1 << endl;
	cout <<" &p1=" << (&p1)<< endl;

	free(p1);

	test1();
	return 0;
}

