 ///
 /// @file    String.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-05 16:21:54
 ///
 
#ifndef __STRING_H__
#define __STRING_H__

#include <iostream>

//	设计模式之代理模式
// >由于重载的下标运算符无法区分是读操作还是写操作 
// >故读操作也会执行深拷贝，故写时复制的功能失效
// >解决：将写操作代理给proxy完成
class String
{
public:
	String();
	String(const char *pstr);
	~String();

	String(const String & pstr);
	String & operator = (const String & pstr);
	//char & operator[](size_t idx);

	void release();
	int refcount() const;
	const char * c_str() const;
	size_t size() const;
private:
	class CharProxy
	{
	public:
		CharProxy(String & self, size_t idx);
		~CharProxy();

		char & operator = (const char & ch);
		friend std::ostream & operator << (std::ostream & os, const CharProxy & rhs);

	private:
		String & _self;
		size_t _idx;
	};

public:
	CharProxy operator[](size_t idx)
	{	return CharProxy(*this, idx);	}

private:
	void initRefcnt();
	void increaseRefcnt();
	void decreaseRefcnt();
	friend std::ostream & operator << (std::ostream &os, const String & rhs);
	friend std::ostream & operator << (std::ostream &os, const CharProxy & rhs);

private:
	char * _pstr;
};


#endif
