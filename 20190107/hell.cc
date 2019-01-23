 ///
 /// @file    hell.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-07 20:20:25
 ///
 
#include <iostream>
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

	printf("&s[0] =%p\n",&s[0]);
	printf("&a=%p\n",&a);
	printf("&p1=%p\n",&p1);
	printf("p1=%p\n",p1);
	printf("a=%d\n",p1);
	cout << endl;

	printf("&b=%p\n",&b);
	printf("&p2=%p\n",&p2);
	printf("p2=%p\n",b);
	printf("s=%p\n",s);
	cout << endl;
	printf("&p3=%d\n",c);
	printf("p3=%p\n",p3);
	printf("c=%d\n",c);
	printf("&c=%p\n",&c);
	strcpy(p1,"12345");

	printf("&12345=%p\n",&"12345");
	printf("&main=%p\n",&main);
	return 0;
}

