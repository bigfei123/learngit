 ///
 /// @file    TextQuery.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-01 23:19:35
 ///
 
#include "TextQuery.h"
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;
 
void runQueries(std::ifstream & ifs)
{
	TestQuery tq(ifs);
	while(1){
		cout << "enter word to look for, or q to quit: " ;
		string s;
		if(!(cin >> s)||s == "q") break;
		print(cout, tq.query(s)) << endl;
	}
}

int main(void)
{
	ifstream file("china_daily.txt");
	runQueries(file);
}
