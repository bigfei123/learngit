 ///
 /// @file    test.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-25 18:38:56
 ///
#include "TestQuery.h" 
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	TestQuery tq;
	tq.ReadFile("china_daily.txt");
	cout << "pls input a query word:" << endl;
	string word;
	while(std::cin >> word)
		tq.Query(word);
	return 0;
}
