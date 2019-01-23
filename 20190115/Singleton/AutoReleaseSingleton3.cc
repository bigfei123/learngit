 ///
 /// @file    AutoReleaseSingleton3.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-17 19:32:10
 ///
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;

//单例对象自动释放：
//方法2： atexit + pthread_once 
// > 平台相关性
class Singleton
{
public:
	//在多线程环境下，线程安全的
	static Singleton * getInstance()
	{
		pthread_once(&_once, init);
		return _pInstance;	
	}

	static void init()
	{
		_pInstance = new Singleton();
		::atexit(destroy);
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
	static pthread_once_t _once;

};

Singleton * Singleton::_pInstance = nullptr; //懒汉模式
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;
//Singleton * Singleton::_pInstance = getInstance(); //饱汉模式
int main(void)
{ 
	Singleton * p1 = Singleton::getInstance();
	p1 ->print();
	return 0;
}
