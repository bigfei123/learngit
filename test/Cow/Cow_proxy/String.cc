 ///
 /// @file    String.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-05 19:40:26
 ///
 
#include "String.h"
#include <cstring>
#include <iostream>
using std::cout;
using std::endl;

String::String()
: _pstr(new char[5]() + 4)
{
	cout << "String()" << endl;
	initRefcnt();
}

String::String(const char *pstr)
: _pstr(new char[strlen(pstr) + 5]() + 4)
{
	strcpy(_pstr, pstr);
	initRefcnt();
	cout << "String(const char *)" << endl;
}

String::String(const String & rhs)
: _pstr(rhs._pstr)
{
	increaseRefcnt();
	cout << "String(const String &)" << endl;
}

String & String::operator=(const String & rhs)
{
	if(this != &rhs) {//自复制
		release();//释放左操作数空间
		_pstr = rhs._pstr;//进行浅拷贝
		increaseRefcnt();
	}
	cout << "String & operator=(const String &)" << endl;
	return *this;
}

void String::release() 
{
	decreaseRefcnt();
	if(refcount() == 0) {
		delete [] (_pstr - 4);
		cout << ">> delete heap data!! " << endl;
	}
}

String::~String()
{
	release();
	cout << "~String()" << endl;
}

int String::refcount() const
{
	return *(int*)(_pstr - 4);
}

const char *String::c_str() const
{
	return _pstr;
}

size_t String::size() const
{
	return strlen(_pstr);
}

//char & String::operator[](size_t idx)
//{
//	if(idx < size()) {
//		if(refcount() > 1) {//共享字符串
//			char * ptmp = new char[size() + 5]() + 4;//进行深拷贝
//			strcpy(ptmp, _pstr);
//			decreaseRefcnt();
//			_pstr = ptmp;
//			initRefcnt();
//		}
//		return _pstr[idx];
//	}else {
//		static char nullchar = '\0';
//		return nullchar;
//	}
//}

void String::initRefcnt()
{
	*(int*)(_pstr - 4) = 1;
}

void String::increaseRefcnt()
{
	++ *(int*)(_pstr - 4);
}

void String::decreaseRefcnt()
{
	--*(int *)(_pstr - 4);
}

std::ostream & operator<<(std::ostream & os, const String & rhs)
{
	os << rhs._pstr;
	return os;
}

String::CharProxy::CharProxy(String & self, size_t idx)
: _self(self)
, _idx(idx)
{}

String::CharProxy::~CharProxy()
{
	cout << "~CharProxy" << endl;
}

char & String::CharProxy::operator=(const char & ch)
{
	if(_idx < _self.size()) {
		if(_self.refcount() > 1) {
			char * ptmp = new char[_self.size() + 5]() + 4;
			strcpy(ptmp, _self._pstr);

			_self.decreaseRefcnt();
			_self._pstr = ptmp;
			_self.initRefcnt();
		}
		//String temp(&ch);
		//*this = temp;
		return _self._pstr[_idx];
	}else {
		static char nullchar = '\0';
		return nullchar;
	}
}

std::ostream & operator<<(std::ostream & os, const String::CharProxy & rhs)
{
	os << rhs._self._pstr[rhs._idx];
	return os;
}
