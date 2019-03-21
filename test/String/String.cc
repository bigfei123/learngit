 ///
 /// @file    String.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-04 20:37:32
 ///
 
#include "String.h"
#include <iostream>
#include <cstring>
using std::cout;
using std::endl;
using std::ostream;

String::String()
: _pstr(nullptr)
{
	cout << "String()" << endl;
}

String::~String()
{
	delete [] _pstr;
	cout << "~String()" << endl;
}

String::String(const char *pstr)
: _pstr(new char[strlen(pstr)+1]())
{
	strcpy(_pstr, pstr);
	cout << "String(const char *)" << endl;
}

String::String(const String & rhs)
: _pstr(new char[strlen(rhs._pstr)+1]())
{
	strcpy(_pstr, rhs._pstr);
	cout << "String(const String &)" << endl;
}

String & String::operator=(const String & rhs)
{
	//1.自复制(对象)
	if(this != &rhs) {
		//2.删除原来操作数空间，并开辟新空间
		delete [] _pstr;
		_pstr = new char[strlen(rhs._pstr+1)]();
		strcpy(_pstr, rhs._pstr);
		cout << "String & operator=(const String &)" << endl;
	}
	//3.返回this指针
	return *this;
}

String & String::operator=(const char * pstr)
{
	String temp = pstr;//调用复制构造函数
	*this = temp;//调用上式赋值运算符函数
	return *this;
	cout << "String & operator=(const char*)" << endl;
}

String & String::operator+=(const String & rhs)
{
	String tmp;
	tmp._pstr = new char[size() + 1]();
	strcpy(tmp._pstr, _pstr);
	delete [] _pstr;
	_pstr = new char[size() + rhs.size() + 1]();
	strcpy(_pstr, tmp._pstr);
	strcat(_pstr, rhs._pstr);
	return *this;
}

String & String::operator+=(const char *pstr)
{
	String tmp = pstr;
	*this += tmp;
	return *this;
	cout << "String & operator+=(const char *)"  << endl;
}

char & String::operator[](size_t idx)
{
	if(idx < size()) {
		return _pstr[idx];
	}else {
		static char nullstr = '\0';
		return nullstr;
	}
	cout << "char & operator[](size_t)" << endl;
}

const char & String::operator[](size_t idx) const
{
	if(idx < size()) {
		return _pstr[idx];
	}else {
		static char nullstr = '\0';
		return nullstr;
	}
	cout << "const char & operator[](size_t) const" << endl;
}

size_t String::size() const
{
	return strlen(_pstr);
}

const char * String::c_str() const
{
	return _pstr;
}

bool operator == (const String & rhs, const String & lhs)
{
	if(rhs.size() == lhs.size()) {
		for(size_t idx = 0; idx != rhs.size(); ++idx) {
			if(rhs._pstr[idx] == lhs._pstr[idx])	
				return true;
			return false;
		}
	} else
		return false;
}

bool operator != (const String & rhs, const String & lhs)
{
	if(rhs.size() == lhs.size()) {
		for(size_t idx = 0; idx != rhs.size(); ++idx) {
			if(rhs._pstr[idx] != lhs._pstr[idx])
				return true;
			return false;
		}
	} else 
		return true;
}

bool operator < (const String & rhs, const String & lhs)
{
	if(rhs.size() == lhs.size()) {
		for(size_t idx = 0; idx != rhs.size(); ++idx) {
			if(rhs._pstr[idx] < lhs._pstr[idx])
				return true;
			return false;
		}
	} else if(rhs.size() > lhs.size()) {
		return false;
	}else
		return true;
}

ostream & operator << (ostream & os, const String & rhs)
{
	os << rhs._pstr << endl;
	return os;
}

//std::istream & operator >> (std::istream & is, String & rhs)
//{
//	is >> rhs._pstr;
//	return is;
//}

String operator + (const String & rhs, const String & lhs)
{
	char * tmp = new char[rhs.size() + lhs.size() + 1]();
	strcpy(tmp, rhs.c_str());
	strcat(tmp, lhs.c_str());
	return tmp;
	cout << "String operator + (const String &, const String &)" << endl;
}

String operator + (const String & rhs, const char *pstr)
{
	char * tmp = new char[rhs.size() + strlen(pstr) + 1]();
	strcpy(tmp, rhs.c_str());
	strcpy(tmp, pstr);
	return tmp;
	cout << "String operator + (const String & rhs, const char *pstr)" << endl;
}


