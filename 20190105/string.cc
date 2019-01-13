#include <stdio.h>
#include <string.h>

#include <iostream>
#include <string>

using std::cout;
using std::endl;

void test0()
{
	//求字符串长度
	char str1[]= " hello "; //字符串以‘\0'结尾
	char str2[]= " world "; //严格来说是一个字符数组  栈区
	str2[0]='W';
	
	int len1=sizeof(str1);
	int len2=sizeof(str2);
	printf("str1's len =%d,str2's len =%d\n",len1,len2);
	
	//字符串拼接
	int len=len1+len2-1;
	char *pstr1=(char *)malloc(len);
	memset(pstr1,0,len);
	strcpy(pstr1,str1);
	strcat(pstr1,str2);
	printf("pstr1=%s\n",pstr1);
	free(pstr1);
	
	//C风格的字符串
	const char *pstr2= "hello,world"; //位于文字常量区
	cout << "pstr2=" << pstr2 << endl;

	printf("pstr2's address =%p\n",pstr2);
	printf("hello,world's address =%p\n", &"hello,world");;
	printf("str1's address= %p\n",str1);
	printf("str2's address= %p\n",str2);
}

void test1()
{
	//c++风格的字符串
	std::string s1="hello";
	std::string s2="world";

	std::string s3=s1+s2;
	cout << "s1= " << s1 << endl
		 << "s2= " << s2 << endl
		 << "s3= " << s3 << endl;

	//把c++风格字符串转换成c风格字符串 [c_str()]
	const char * pstr=s3.c_str();
	cout << "pstr= " << pstr <<endl;
	//获取字符串的长度
	size_t len1 =s1.size();
	size_t len2 =s1.length();
	cout << "s1's size = " << len1 <<endl
		 << "s2's size = " << len2 << endl;
	
	//遍历std::string的元素
	for(size_t idx =0; idx != s3.size(); ++idx)
	{
		cout << s3[idx] << endl;
	}

	std::string s4= s3+ "shenzhen";
	cout << "s4= " << s4 << endl;

	std::string s5= s4+'A';
	cout <<"s5= " << s5 << endl;
	//追加字符串
	s5.append(s1);
	cout << "s5= " << s5 << endl;

	//字符串的查找
	size_t pos = s5.find("shenzhen");

	//截取字串
	std::string s6=s5.substr(pos);
	cout << "s6= " << s6 << endl;
}


int main()
{
	test0();
	test1();
	return 0;
}
