 ///
 /// @file    TestLine.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-05 16:00:16
 ///
 
#include "Line.h"
#include <iostream>
using std::cout;
using std::endl;
 
void test()
{
	Line line(1, 2, 3, 4);
	line.printLine();
}

int main(void)
{
	test();
	return 0;
}
