 ///
 /// @file    Test.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-11 12:20:07
 ///

#include "DList.h"
#include <iostream>

using std::cout;
using std::endl;

int test()
{
	DList ls;
	ls.Push_back(0);
	ls.Push_back(1);
	ls.Push_back(2);
	ls.Push_back(3);
	ls.Push_front(4);
	
	ls.display();
	cout << endl;

	ls.Pop_back();
	ls.Pop_back();
	ls.Pop_front();
	
	ls.display();
	cout << endl;
	return 0;
}


int main(void)
{
	test();
	return 0;
 
}
