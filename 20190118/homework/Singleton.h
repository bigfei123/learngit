 ///
 /// @file    Singleton.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-20 23:01:38
 ///

#ifndef SINGLE_H__
#define SINGLE_H__
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;

//单例对象自动释放：atexit + pthread_once
//单例对象自动释放：atexit + 饿汉模式
template <class T>
class Singleton
{
public:
	template<class... Args>
	static T * getInstance(Args...args){
		if(nullptr == _pInstance){
		_pInstance = new T(args...);
		::atexit(destroy);
		}
		return _pInstance;
	}

	static void destroy(){
		if(_pInstance)
			delete _pInstance;
	}
		

private:
	Singleton()
	{	cout << "Singleton() " << endl; }
	~Singleton()
	{	cout << "~Singleton()" << endl; }
private:
	static T * _pInstance;
	//static pthread_once_t _once;
};

template <class T>
T * Singleton<T>::_pInstance = nullptr; //饿汉模式
//template <class T>
//pthread_once_t Singleton<T>::_once = PTHREAD_ONCE_INIT; 
#endif
