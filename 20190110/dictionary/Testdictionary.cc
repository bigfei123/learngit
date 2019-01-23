 ///
 /// @file    TestDic.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-12 16:15:37
 ///
#include "dictionary.h" 
#include <iostream>
#include <time.h>
using std::cout;
using std::endl;
 
int main(void)
{
	Dictionary dic(13000);
	time_t beg = ::time(NULL);
	dic.read("The_Holy_Bible.txt");
	time_t end = ::time(NULL);
	cout << ">> time: " << (end -beg) << "s" <<endl;
	dic.store("dictionary.txt");
	return 0;
}
