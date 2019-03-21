 ///
 /// @file    Singleton.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-07 15:10:17
 ///

//利用饿汉模式 + atexit() 实现可变模板参数的实例(Point类、Computer类)
 
#ifndef __SINGLETON_H__
#define __SINGLETON_H__
#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;

template <class T>
class Singleton
{
public:
	template <class... Args>
	static T * getInstance(Args...args)
	{
		if(nullptr == _pInstance) {
			_pInstance = new T(args...);
			::atexit(destory);
		}
		return _pInstance;
	}

	static void destory()
	{
		if(_pInstance)
			delete _pInstance;
	}

private:
	Singleton()	{ cout << "Singleton()" << endl; }
	~Singleton() { cout << "~Singleton() " << endl; }

private:
	static T * _pInstance;
};

template <class T>
T * Singleton<T>::_pInstance = nullptr;


#endif
