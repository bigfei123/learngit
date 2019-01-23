 ///
 /// @file    middlebracket.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-16 09:11:50
 ///

#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

//int array[10] = {1, 2, 3};
 
class CharArray
{
public:
	CharArray(size_t sz = 10)
	: _sz(sz)
	, _data(new char[_sz]())
	{
		cout << "CharArray(size_t)" <<endl;
	}

	//下表访问运算符，有两个参数
	//第一个操作数是对象本身、第二个操作数可以是任意类型
	//
	//string/vector 它们都能像使用数组一样去访问元素，就是因为他们重载了下标访问运算符
	
	//返引用而不是返对象的原因在于：返对象会进行复制
	//这时就不是操作原数
	char & operator[](size_t idx) 
	{
		if(idx < size()) {
			return _data[idx];
		}
		else {
			static char nullchar = '\0'; 
			//用static的原因：返回值为char类型的引用，不能返回局部变量
			//由于返回类型为char &，不能直接return '\0'
			return nullchar;
		}
	}

	~CharArray()
	{
		cout << "~CharArray() " << endl;
		delete [] _data;
		_data = nullptr;
	}

	size_t size() const
	{	return _sz;}
private:
	size_t _sz;
	char * _data;
};



int main(void)
{
	const char * str = "hello,world";
	CharArray ca(strlen(str)+1);

	for(size_t idx =0; idx != ca.size(); ++idx) {
		ca[idx] = str[idx];

	}

	for(size_t idx = 0; idx != ca.size(); ++idx) {
		cout << ca[idx] << '\n';
	}
	return 0;
}

