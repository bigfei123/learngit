///
/// @file    test.cc
/// @author  bigfei775655478@qq.com)
/// @date    2019-03-06 19:10:56
///

/*
 *请定义一个宏，比较两个数a、b的大小，不能使用大于、小于、if语句。
 */
#include <iostream>
using std::cout;
using std::endl;

#define max(a,b) (((a)-(b))&(0x1 << 31) >> 31) 

int main(void)
{
	int a = 5;
	int b = 4;
	cout << " max(a,b) = " << max(a,b) << endl;
	return 0;
}
