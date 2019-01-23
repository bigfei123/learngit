 ///
 /// @file    String1.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-21 22:32:25
 ///
#include "String.h" 
#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

String::String(const char * pstr)
:_pstr(new char[strlen(pstr) + 5]() + 4)
{
	strcpy(_pstr, pstr);
	cout << "String(const char *)" << endl;
}

String::String(const string & rhs)
: _pstr(rhs._pstr)
{

}

