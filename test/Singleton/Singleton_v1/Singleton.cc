 ///
 /// @file    Singleton.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-03 16:09:48
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
class Singleton
{
public:
	static Singleton * getInstance()
	{
		if(nullptr == _pInstance)
			_pInstance = new Singleton();
		return _pInstance;
	}

	static void destory()
	{
		if(_pInstance)
			delete _pInstance;
	}

private:
	Singleton() {	cout << "Singleton()" << endl;	} 
	~Singleton() {	cout << "~Singleton()" << endl;	} 
private:
	static Singleton * _pInstance ;
};

Singleton * Singleton:: _pInstance = nullptr;

int main(void)
{
	Singleton * ps1 = Singleton::getInstance();

	Singleton * ps2 = Singleton::getInstance();

	cout << "ps1 = " << ps1 << endl
		 << "ps2 = " << ps2 << endl;
	Singleton::destory();
}
