 ///
 /// @file    test2.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-06 19:42:30
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	cout << "line = " << __LINE__ << endl;
	cout << "file = " << __FILE__ << endl;
	cout << "date = " << __DATE__ << endl;
	cout << "time = " << __TIME__ << endl;
	cout << "stdc = " << __STDC__ << endl;
	cout << "cplusplus = " << __cplusplus << endl;
	
	return 0;
}
