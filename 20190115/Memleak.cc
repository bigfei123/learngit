 ///
 /// @file    Memleak.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-17 14:57:27
 ///
#include <stdlib.h> 
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	int * pret = new int(11);

	cout << "*pret = " << *pret << endl;
	delete pret;
	return 0;
 
}
