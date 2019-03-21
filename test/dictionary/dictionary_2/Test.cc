 ///
 /// @file    Test.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-04 16:28:04
 ///
 
#include "dictionary.h"
#include <time.h>
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	Dictionary dic;
	time_t beg = ::time(NULL);
	dic.read("The_Holy_Bible.txt");
	time_t end = ::time(NULL);
	cout << ">> time: " << (end - beg) << "s" << endl;
	dic.store("dictionary.txt");
	return 0;
}
