 ///
 /// @file    016.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-04-15 16:48:18
 ///
 
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
 
float fun(double val)
{
	int i = 2;
	while(i) {
		val *= 10;
		i--;
	}
	int IntNum = val;
	float SmallNum = val-IntNum;
	if(SmallNum > 0.5) {
		IntNum ++;	
	}
	float ret = IntNum;
	int j = 2;
	while(j) {
		ret /= 10;	
		j--;
	}
	return ret ;
}

int main(void)
{
	float val;
	cout << "pls input a val: " ;
	cin >> val;
	cout << fun(val) << endl;
	return 0;
}
