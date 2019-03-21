 ///
 /// @file    String.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-05 16:21:54
 ///
 
#ifndef __STRING_H__
#define __STRING_H__

#include <iostream>

class String
{
public:
	String();
	String(const char *pstr);
	~String();

	String(const String & pstr);
	String & operator = (const String & pstr);
	char & operator[](size_t idx);

	void release();
	int refcount() const;
	const char * c_str() const;
	size_t size() const;
private:
	//class CharProxy
	//{
	//public:
	//	CharProxy(String & self, size_t idx);
	//	~CharProxy();

	//	char & operator = (const char & ch);
	//	friend std::ostream & operator << (std::ostream & os, const CharProxy & rhs);

	//private:
	//	String & _self;
	//	size_t _idx;
	//};

private:
	void initRefcnt();
	void increaseRefcnt();
	void decreaseRefcnt();
	friend std::ostream & operator << (std::ostream &os, const String & rhs);
	//friend std::ostream & operator << (std::ostream &os, const CharProxy & rhs);

private:
	char * _pstr;
};


#endif
