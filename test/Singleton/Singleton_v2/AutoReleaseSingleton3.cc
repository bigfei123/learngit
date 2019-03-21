 ///
 /// @file    AutoReleaseSingleton3.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-06 16:01:24
 ///
 
#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;
 
//方法3： atexit + pthread_once
//在多线程环境下是线程安全的

class Singleton
{
public:
	static Singleton * getInstance()
	{
		pthread_once(&_once, init);
		return _pInstance;
	}

	static void init()
	{
		_pInstance = new Singleton();
		::atexit(destory);
	}

	static void destory()
	{
		if(_pInstance)
			delete _pInstance;
	}

	void print() const
	{	cout << "address = " << this << endl; }


private:
	Singleton()
	{	cout << "Singleton()" << endl;	}

	~Singleton()
	{	cout << "~Singelton()"<< endl;	}

private:
	static Singleton * _pInstance;
	static pthread_once_t _once;
};

Singleton * Singleton::_pInstance = nullptr;//懒汉模式
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;

int main(void)
{
	Singleton * ps1 = Singleton::getInstance();
	ps1->print();

	Singleton * ps2 = Singleton::getInstance();
	ps2->print();
	return 0;
}
