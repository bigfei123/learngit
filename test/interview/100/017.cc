 ///
 /// @file    017.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-04-15 17:22:23
 ///
 
#include <cstring>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
 
char pstr[10];
char * fun(const char *s)
{
	int lens = strlen(s);
	memset(pstr, 0, lens);
	for(int i = lens-1, j = 0; i >= 0; --i, ++j) {
		pstr[j] = s[i];
	}

	return pstr;
}

int main(void)
{
	const char * str = "abcdefg";
	char * pstr = fun(str);
	for(size_t i = 0; i < strlen(str); ++i) {
		cout << pstr[i] << "";
	}
	cout << endl;
}
