 ///
 /// @file    AutoReleaseSingleton2.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-06 15:16:15
 ///
 
//方法2： atexit + 饱汉模式

#include <iostream>
using std::cout;
using std::endl;
 
class Singleton
{
public:
	static Singleton * getInstance()
	{
		if(nullptr == _pInstance) {
			_pInstance = new Singleton();
			atexit(destory);
		}
		return _pInstance;
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
};

//Singleton *Singleton::_pInstance = nullptr;//懒汉模式
Singleton * Singleton::_pInstance = getInstance();//饱汉模式

int main()
{
	Singleton * ps1 = Singleton::getInstance();
	ps1->print();

	Singleton * ps2 = Singleton::getInstance();
	ps2->print();
	return 0;
}
