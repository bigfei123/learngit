 ///
 /// @file    templateParameter.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-19 20:10:21
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//模板参数可以有两种形式：
//1. 类型参数
//2. 非类型参数，常量表达式 整形bool/char/short/int/long
//	 更具有一般性
//
//都可以设置默认值
//
//#define kMin 10
//const short kMin = 10;

template <class T = int ,short kMin = 10>T multiply(T x, T y)
{
	return x * y * kMin;
}

int main(void)
{
	short sa = 2, sb = 3;
	cout << "multiply(sa, sb) = " << multiply<short, 5>(sa, sb) << endl;
	return 0;
}
