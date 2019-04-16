 ///
 /// @file    String.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-16 16:49:45
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class String
{
public:
	String();
	~String();
	String(const char *);
	String(const String &);
	String & operator = (const String &);
	String &operator = (const char *);

	String &operator+=(const String &);
	String &operator+=(const char*);

	char &operator[](std::size_t index);
	const char &operator[](std::size_t index) const;

	std::size_t size() const;
	const char * c_str() const;

	friend bool operator == (const String &, const String &);
	friend bool operator != (const String &, const String &);

	friend bool operator < (const String &, const String &);
	friend bool operator > (const String &, const String &);
	friend bool operator <= (const String &, const String &);
	friend bool operator >= (const String &, const String &);

	friend std::ostream &operator << (std::ostream &os,const String &s);
	friend std::istream &operator >> (std::istream &is,String &s);

private: char *_pstr;
};

String operator + (const String &, const String &);
String operator + (const String &, const char *);
String operator + (const char *, const String &);
