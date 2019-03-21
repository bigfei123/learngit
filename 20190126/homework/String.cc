 ///
 /// @file    String.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-01 20:06:32
 ///
 
#include <iostream>
#include <string>
#include <cstring>
using std::cout;
using std::endl;
using std::string;
 
class String
{
public:
	String()
	{	cout << "String() " << endl;	}

	String(const char *pstr)
	: _pstr(new char[strlen(pstr) + 1]())
	{
		strcpy(_pstr, pstr);
		cout << "String(const char *)" << endl;
	}

	String(const String & rhs)
	: _pstr(new char[strlen(rhs._pstr) + 1]())
	{
		strcpy(_pstr, rhs._pstr);
		cout << "String(const String &)" << endl;
	}

	String & operator=(const String & rhs)
	{
		cout << "String & operator=(const String &)" << endl;
		if(this != &rhs){
			delete [] _pstr;
			_pstr = new char[strlen(rhs._pstr) + 1]();
			strcpy(_pstr, rhs._pstr);
		}
		return *this;
	}

	String(String && rhs)
	{
		cout << "String(const String &&)" << endl;
		_pstr = rhs._pstr;
		rhs._pstr = nullptr;
	}

	String & operator=(String && rhs)
	{
		cout << "String & operator=(String &&)" << endl;
		if(this != &rhs){
			delete [] _pstr;
			_pstr = rhs._pstr;
			rhs._pstr = nullptr;
		}
		return *this;
	}

	~String()
	{	
		delete [] _pstr;
		cout << "~String()" << endl;
	}

private:
	char * _pstr;
};

int main()
{
	String s1("hello,world");
	String s2(s1);
	String s3("hubei, wuhan");
	//s1 = s3;
	//s1 = std::move(s3);
	String s4(std::move(s2));
}
