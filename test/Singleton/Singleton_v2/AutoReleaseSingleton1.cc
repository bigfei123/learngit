 ///
 /// @file    AutoReleaseSingleton1.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-06 14:41:27
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//方法1：嵌套类实现自动回收
//缺点：在多线程环境下，并不是线程安全的

class Singleton
{
public:
	void print() const
	{
		cout << "this'address = " << this << endl;
	}

	static Singleton * getInstance()
	{
		if(nullptr == _pInstance)
			_pInstance = new Singleton();
		return _pInstance;
	}

	//static void destory()
	//{
	//	if(_pInstance)
	//		delete _pInstance;
	//	cout << "destory()" << endl;
	//}
	
private:
	//专为Singleton服务
	class AutoRelease
	{
	public:
		AutoRelease ()	{ cout << "AutoRelease()" << endl; }
		~AutoRelease()
		{
			if(_pInstance)
				delete _pInstance;
			//1.先调用析构函数
			//2.再调用operator delete表达式
			cout << "~AutoRelease" << endl;
		}
	};

private:
	Singleton()
	{	cout << "Singleton()" << endl;	}
	~Singleton()
	{	cout << "~Singleton()" << endl;  }

private:
	static Singleton * _pInstance;
	static AutoRelease _auto; //非静态的数据成员是Singleton对象的一部分,因此设置为静态
};

Singleton * Singleton::_pInstance = nullptr;
Singleton::AutoRelease Singleton::_auto;
 
int main(void)
{
	Singleton * ps1 = Singleton::getInstance();
	ps1->print();
	//cout << "ps1'address = " << ps1 << endl;
	//ps1->destory();
 
	Singleton * ps2 = Singleton::getInstance();
	ps2->print();
	//cout << "ps2'address = " << ps2 << endl;
	//ps2->destory();
}
