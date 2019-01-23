 ///
 /// @file    String.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-16 19:36:10
 ///

#include "String.h"
#include <iostream>
#include <string>
#include <cstring>
using std::cout;
using std::endl;
using std::string;

//无参构造函数
String::String()
:_pstr(nullptr)
{
	cout << "String() " << endl;
}

//有参构造函数
String::String(const char *pstr)
:_pstr(new char[strlen(pstr)+1]())
{
	strcpy(_pstr, pstr);
	cout << _pstr << endl;
	cout << "String(const char *)" << endl;
}

//复制构造函数
String::String(const String & rhs)
:_pstr(new char[strlen(rhs._pstr)+1]())
{
	strcpy(_pstr, rhs._pstr);
	cout << "String(const String &)" << endl;
}

//赋值表达式
String & String::operator =(const String &rhs)
{
	if(this != &rhs) {
		delete [] _pstr; 	
		this->_pstr = new char[strlen(rhs._pstr)+1]();
		strcpy(_pstr, rhs._pstr);
		cout << "String & operator=(const String &)" << endl;
	}
	return *this;
}
//赋值表达式
String & String::operator=(const char *pstr)
{
	String temp = pstr;
	*this= temp; //调用上述函数，减少冗余代码
	return *this;	
	cout << "String & operator=(const char*) " << endl;
}
//  +=运算符重载
String & String::operator+=(const String &rhs)
{
	cout << "String & operator +=(const String &)" << endl;
	char *temp = new char[(size()+ rhs.size()+1)]();
	strcpy(temp, _pstr);
	strcat(_pstr,rhs._pstr);
	return *this; 
}
// +=运算符重载
String & String::operator+=(const char *pstr)
{
	cout << "String & operator +=(const char *)" << endl;
	String temp = pstr;
	*this += temp;
	return *this; 

}

char & String::operator [] (std::size_t index)
{
	if(index < size())	{
		return _pstr[index];
	}
	else {
		static char nullstr = '\0';
		return nullstr;	
	}
}

const char & String::operator[](std::size_t index) const
{
	cout << "const char & operator[](size_t) const " <<endl;
	if(index < size()) {
		return _pstr[index];
	}
	else {
		static char nullstr = '\0';
		return nullstr;
	}
}

bool operator == (const String &lhs, const String &rhs)
{
	cout << "bool operator ==(const String &, const String &)" <<endl;
	for(size_t idx; idx != lhs.size(); ++idx) {
		if(lhs[idx]==rhs[idx])
			return true;
		return false;
	}
}

bool operator != (const String &lhs, const String &rhs)
{
	cout << "bool operator != (const String &, const String &) " <<endl;
	for(size_t idx; idx != lhs.size(); ++idx) {
		if(lhs[idx]!=rhs[idx])
			return true;
		return false;
	}

}

bool operator <= (const String &lhs, const String &rhs)
{
	cout << "bool operator <=(const String &, const String &) " <<endl;
	for(size_t idx; idx != lhs.size(); ++idx) {
		if(lhs[idx]<=rhs[idx])
			return true;
		return false;
	}

}

bool operator >= (const String &lhs, const String &rhs)
{
	cout << "bool operator >=(const String &, const String &) " <<endl;
	for(size_t idx; idx != lhs.size(); ++idx) {
		if(lhs[idx]>=rhs[idx])
			return true;
		return false;
	}

}

bool operator > (const String &lhs, const String &rhs)
{
	cout << "bool operator >(const String &, const String &) " <<endl;
	for(size_t idx; idx != lhs.size(); ++idx) {
		if(lhs[idx]>rhs[idx])
			return true;
		return false;
	}

}

bool operator < (const String &lhs, const String &rhs)
{
	cout << "bool operator <(const String &, const String &) " <<endl;
	for(size_t idx; idx != lhs.size(); ++idx) {
		if(lhs[idx]<rhs[idx])
			return true;
		return false;
	}

}
std::ostream & operator << (std::ostream &os,const String &rhs)
{
	cout << "ostream" << endl;
	os << rhs._pstr <<endl;
	return os;
}

std::istream & operator >> (std::istream &is,String &rhs)
{
	cout << "istream " <<endl;
	is >> rhs._pstr;
	return is;
}
//析构函数 
String::~String()
{
	delete [] _pstr;
	cout << "~String() " <<endl;
}

const char *String:: c_str() const 
{	return _pstr;	}

size_t String::size() const
{	return strlen(_pstr);	}
