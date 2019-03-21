 ///
 /// @file    test.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-24 19:36:14
 ///
#include "dictionary.h" 
#include <iostream>
#include <time.h>
using std::cout;
using std::endl;
 
int main(void)
{
	Dictionary dic;
	time_t beg = ::time(NULL);
	dic.Read("The_Holy_Bible.txt");
	time_t end = ::time(NULL);
	cout << ">>time:" << (end - beg) << "s" << endl;
	dic.Store("The_Dictionary.txt");
	return 0;
}
