 ///
 /// @file    String.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-17 20:48:52
 ///
#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class String
{ 
public:
	String()
	: _pstr(new char[5]() + 4)
	{
		cout << "String()" << endl;
		initRefcnt();
	}

	String(const char * pstr)
	: _pstr(new char [strlen(pstr) + 5]() + 4)
	{
		strcpy(_pstr, pstr);
		initRefcnt();
		cout << "String(const char *)" << endl;
	}

	String(const String & rhs)
	: _pstr(rhs._pstr)
	{
		increaseRefcnt();
		cout << "String(const String &)" << endl;
	}

	String & operator=(const String & rhs)
	{
		cout << "String & operator =(const String &)" << endl;
		if(this != &rhs) {
			release();

			_pstr = rhs._pstr;
			increaseRefcnt();
		}
		return *this;
	}

	void release()
	{
		decreaseRefcnt();
		if(refcount() == 0) {
			delete [] (_pstr - 4);
			cout << ">> delete heap data!!! " << endl;
		}
	}

	~String()
	{
		release();
		cout << "~String() " << endl;
	}

	int refcount() const
	{	return *(int*)(_pstr - 4); }

	const char * c_str() const
	{	return _pstr;	}

	size_t size() const
	{	return strlen(_pstr);	}
private:
	class CharProxy
	{
	public:
		CharProxy(String & self, size_t idx)
		: _self(self)
		, _idx(idx)
		{}

		char & operator=(const char & ch);
		friend std::ostream & operator <<(std::ostream & os, const CharProxy & rhs);

	private:
		String & _self;//为了找到字符串本身
		size_t _idx;
	};

	//设计模式之代理模式
public:
	CharProxy operator[](size_t idx)
	{	return CharProxy(*this, idx);	}

	//下标运算符无法区别接下来的操作是读操作函数写操作
	//char & operator[](size_t idx)
//	CharProxy operator[](size_t idx)
//	{
//	}

//	const char & operator [](size_t idx) const
private:
	void initRefcnt()
	{
		*(int*)(_pstr - 4) = 1;
	}

	void increaseRefcnt()
	{
		++*(int *)(_pstr - 4);
	}

	void decreaseRefcnt()
	{
		--*(int *)(_pstr - 4);
	}

	friend std::ostream & operator<<(std::ostream & os, const String & rhs);
	friend std::ostream & operator<<(std::ostream & os, const CharProxy & rhs);

private:
	char * _pstr; //指向字符串内容本身
};

std::ostream & operator<<(std::ostream & os, const String & rhs)
{
	os << rhs._pstr;
	return os;
}

//写操作
char & String::CharProxy::operator=(const char & ch)
{
	// _self  _idx;
	if(_idx < _self.size()) {
		if(_self.refcount() > 1)	{ //共享字符串
			char * ptmp = new char[_self.size() + 5]() + 4;
			strcpy(ptmp, _self._pstr);

			_self.decreaseRefcnt();
			_self._pstr = ptmp;
			_self.initRefcnt();
		} 
		return _self._pstr[_idx];
	}else {
		static char nullchar = '\0';
		return nullchar;
	}

}

std::ostream & operator<<(std::ostream & os , const String::CharProxy & rhs)
{
	os << rhs._self._pstr[rhs._idx];
	return os;
}

int main(void)
{
	String s1("hello,world");
	String s2 = s1;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s1' refcnt = " << s1.refcount() << endl;
	cout << "s2' refcnt = " << s2.refcount() << endl;
	printf("s1'address = %p\n", s1.c_str());
	printf("s2'address = %p\n", s2.c_str());

	String s3("hubei wuhan");
	cout << ">>执行s3 = s1之后： " << endl;
	s3 =s1;  // 调用operator=()
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s1'refcount() =" << s1.refcount() << endl;
	cout << "s2'refcount() =" << s2.refcount() << endl;
	cout << "s3'refcount() =" << s3.refcount() << endl;
	printf("s1'address = %p\n",s1.c_str());
	printf("s2'address = %p\n",s2.c_str());
	printf("s3'address = %p\n",s3.c_str());

	cout << endl << "对s3[0]执行写操作:" << endl;
	s3[0] = 'H'; //要去修改字符串内容，此时采取进行深拷贝
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s1'refcount = " << s1.refcount() << endl;
	cout << "s2'refcount = " << s2.refcount() << endl;
	cout << "s3'refcount = " << s3.refcount() << endl;
	printf("s1'address = %p\n",s1.c_str());
	printf("s2'address = %p\n",s2.c_str());
	printf("s3'address = %p\n",s3.c_str());
	cout << endl << "对s1[0]执行读操作:" << endl;
	cout<< "s1[0] =" << s1[0] << endl;//要去修改字符串内容，此时采取进行深拷贝
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s1'refcount = " << s1.refcount() << endl;
	cout << "s2'refcount = " << s2.refcount() << endl;
	cout << "s3'refcount = " << s3.refcount() << endl;
	printf("s1'address = %p\n",s1.c_str());
	printf("s2'address = %p\n",s2.c_str());
	printf("s3'address = %p\n",s3.c_str());
	return 0;
}
