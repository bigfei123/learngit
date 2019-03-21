 ///
 /// @file    String.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-04 20:29:30
 ///
 
#ifndef __STRING_H__
#define __STRING_H__

#include <iostream>

class String
{
public:
	String();
	~String();
	String(const char *);
	String(const String &);
	String & operator = (const String &);
	String & operator = (const char *);

	String & operator += (const String &);
	String & operator += (const char *);

	char & operator[](size_t idx);
	const char & operator[](size_t idx) const;

	std::size_t size() const;
	const char * c_str() const;

	friend bool operator == (const String &, const String &);
	friend bool operator != (const String &, const String &);
	
	friend bool operator < (const String &, const String &);
	friend bool operator > (const String &, const String &);
	friend bool operator >= (const String &, const String &);
	friend bool operator >= (const String &, const String &);

	friend std::ostream & operator << (std::ostream & os, const String & rhs);
	friend std::istream & operator << (std::istream & os, String & rhs);

private:
	char * _pstr;
};

String operator + (const String &, const String &);
String operator + (const String &, const char *);
String operator + (const char *, const String &);


#endif
