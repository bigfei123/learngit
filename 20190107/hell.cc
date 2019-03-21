 ///
 /// @file    hell.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-07 20:20:25
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

int a;			//全局变量自动进行初始化
char *p1;

int main(void)
{
	int b; //b也没有进行初始化	 
	char s[]="12345";//栈区
	char *p2;// 野指针
	char *p3="12345"; //文字常量区
	static int c=0;

	p1=new char[10]();
	p2=new char[5]();

	printf("&s[0] =%p\n",&s[0]);//栈区
	printf("&a=%p\n",&a);//全局区
	printf("&p1=%p\n",&p1);//全局区
	printf("p1=%p\n",p1);//堆区
	printf("a=%d\n",a);
	cout << endl;

	printf("&b=%p\n",&b);//栈区
	printf("&p2=%p\n",&p2);//栈区
	printf("p2=%p\n",p2);//堆区
	printf("s=%p\n",s);//栈区
	cout << endl;
	printf("&p3=%p\n",&p3);//栈区
	printf("p3=%p\n",p3);//文字常量区
	printf("c=%d\n",c);
	printf("&c=%p\n",&c);//栈区
	strcpy(p1,"12345");

	printf("&12345=%p\n",&"12345");//文字常量区
	printf("&main=%p\n",&main);//程序代码区
	return 0;
}

