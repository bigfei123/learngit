 ///
 /// @file    functionTemplate.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-19 19:41:38
 ///
#include <cstring> 
#include <iostream>
using std::cout;
using std::endl;
using std::string;

//			模板参数推导，在实参传递时
//函数模板（function template）==>模板函数
//							 实例化

template <class T>   //模板参数列表
T add(T x, T y)
{
	cout << "T add(T x, T y)" << endl;
	return x + y;
}

template <class T>
T add(T x, T y, T z)
{
	return x + y + z;
}

//函数模板可以与函数模板进行重载
//
//函数模板可以与普通函数进行重载
//
//普通函数优先于函数模板的执行
int add(int x, int y)
{
	cout << "int add(int,int)" << endl;
	return x + y;
}

//模板特化（template specializtion）
//特化版本的实现可以有多个
template <>
const char *add<const char *>(const char * pc1, const char * pc2)
{
	size_t len = strlen(pc1) + strlen(pc2) + 1;
	char * ptem = new char[len];
	strcpy(ptem, pc1);
	strcat(ptem, pc2);
	return ptem;
}
int main(void)
{
	int ia = 3, ib = 5, ic = 4;
	double da = 1.1, db = 2.2;
	char ca = 'a', cb = 1;

	string s1 = "hello", s2 = "world";

	const char * p1 = "hello";
	const char * p2 = "world";

	cout << "add(ia, ib) = " << add(ia, ib) << endl  //隐式实例化
		 << "add(da, db) = " << add<double>(da, db) << endl //显式实例化
		 << "add(ca, cb) = " << add(ca, cb) << endl
		 << "add(s1, s2) = " << add(s1, s2) << endl;
//	cout << "add(ia, db) = " << add(ia, db) << endl; //如果只有函数模板，这种方式错误
//	除非有template<class T ,class L>
	cout << "add(ia, ib, ic) = " << add(ia, ib, ic) << endl;

	//特例
	cout << "add(p1, p2) = " << add(p1, p2) << endl;
	return 0;
}
