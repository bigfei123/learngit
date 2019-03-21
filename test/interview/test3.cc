 ///
 /// @file    test3.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-06 20:50:52
 ///
 
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
 
int main(void)
{
	cout << (872581)%36 ;
#if 0
	cout << "pls input :";
	int number = 0;
	int t = 0;
	cin >> number;
	while(number) {
		t = number % 36;	
		cout << (char)(t + 97) << " " ;
	}
#endif
}
