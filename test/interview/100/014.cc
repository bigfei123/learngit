 ///
 /// @file    014.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-04-15 16:05:55
 ///
 
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::cin;
 
unsigned fun(unsigned val)
{
	unsigned tens = 1, tmp = val;
	while(tmp /= 10) {
		tens *= 10;
	}
	return val % tens;
}

int main(void)
{
	int value;
	cout << "pls input a value: " ;
	cin >> value;
	cout << fun(value) << endl;
}
