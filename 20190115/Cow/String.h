 ///
 /// @file    String.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-21 22:15:42
 ///
#include <iostream>
class String
{
public:
	String(const char * pstr);
	~String();

	String(const String & pstr);
	String & operator=(const String & pstr);


	int refcnt() const;
	const	char * c_str() const;
	size_t size() const;

private:
	class CharProxy
	{
	public:
		CharProxy(String & self, size_t idx);
		~CharProxy();

		char & operator=(const char & ch);
		friend std::ostream & operator <<(std::ostream & os, const CharProxy & rhs);

	private:
		String & _self;
		size_t _idx;
	};
public:
	CharProxy operator[](size_t idx);
	
private:
	void initRefcnt();
	void increaseRefcnt();
	void decreaseRefcnt();
	friend std::ostream & operator<<(std::ostream & os, const String & rhs);
	friend std::ostream & operator<<(std::ostream & os, const CharProxy & rhs);
	char * _pstr; //找到字符串本身
};
