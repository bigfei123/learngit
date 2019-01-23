 ///
 /// @file    AutoReleaseSingleton2.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-17 19:14:17
 ///
 
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

//单例对象自动释放：
//方法2： atexit + 饱汉模式

class Singleton
{
public:
	static Singleton * getInstance()
	{
		if(nullptr == _pInstance){
			_pInstance = new Singleton();
			atexit(destroy);
		}
		return _pInstance;	
	}

	static void destroy()
	{
		if(_pInstance)
			delete _pInstance;
	}

	void print() const
	{	cout << "Singleton::print() " << endl;	}

private:
	Singleton() {	cout << "Singleton() " << endl;	}
	~Singleton(){	cout << "~Singleton()" << endl; }

private:
	static Singleton * _pInstance;

};

//Singleton * Singleton::_pInstance = nullptr; //懒汉模式
Singleton * Singleton::_pInstance = getInstance(); //饱汉模式
int main(void)
{
	Singleton * p1 = Singleton::getInstance();
	p1 ->print();
	return 0;
}
