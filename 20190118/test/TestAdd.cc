 ///
 /// @file    TestAdd.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-19 21:59:57
 ///
//对于模板而言，在结构上来说，是可以将其分成声明与实现的；但是
//在#include时，必须要看到模板全部实现，才能够进行正确的推导
#include "add.h"
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	int ia = 3, ib =4;
	cout << "add(ia, ib) = " << add(ia, ib) << endl;
	return 0;
}
