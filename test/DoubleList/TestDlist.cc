 ///
 /// @file    TestDlist.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-04 12:21:11
 ///
 
#include "Dlist.h"
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	Dlist ls;
	ls.Push_back(0);
	ls.Push_back(1);
	ls.Push_front(2);
	ls.Push_front(3);
	ls.Push_front(4);
	ls.display();
	cout << endl;
	ls.Pop_back();
	ls.Pop_front();
	ls.display();

	ls.insert(ls.getPtr(), 5);
	ls.display();

	ls.erase(ls.getPtr());
	ls.display();
	return 0;
}
