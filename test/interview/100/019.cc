 ///
 /// @file    019.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-04-17 16:05:36
 ///
 
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::cin;
 
string fun(string & str, char c)
{
	for(size_t idx = 0; idx != str.size(); ++idx) {
		if(str[idx] == c) {
			for(size_t i = idx; i != str.size(); ++i) {
				str[i] = str[i+1];
			}
		}
	}
	return str;
}

int main(void)
{
	string str;
	char c;
	cout << "pls input string" << endl;
	cin >> str;
	cout << "pls input char" << endl;
	cin >> c;	
	cout << fun(str, c) << endl;
	return 0;
}
