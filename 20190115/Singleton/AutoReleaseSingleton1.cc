 ///
 /// @file    Singleton.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-17 15:26:52
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//需要创建一个对象，需要一个类
//当对象被销毁时，析构函数会被自动调用
//
//单例对象自动释放：
//方法1：嵌套类 + 静态对象
//
class Singleton
{

public:
	static Singleton * getInstance()
	{
		if(nullptr == _pInstance)
			_pInstance = new Singleton();

		return _pInstance;
	}

	void print() const
	{	cout << "Singleton::print() " << endl;	}

	//static void destroy()
	//{
	//	if(_pInstance)
	//		delete _pInstance;
	//	cout << "destroy()" << endl;
	//}
private:
	//转为Singleton而生的
	class AutoRelease
	{
	public:
		AutoRelease () {cout << "AutoRelease() " << endl; }
		~AutoRelease()
		{
			cout << "~AutoRelease()" << endl;
			if(_pInstance)
				delete _pInstance;//1.先调用析构函数  2.operator delete
		}
	};

private:
	Singleton()	{ cout << "Singleton() " << endl;	}
	~Singleton(){ cout << "~Singleton() "<< endl;	}

private:
	static Singleton * _pInstance ;
	static AutoRelease _auto; //非静态的数据成员是Singleton对象的一部分
}; // end of Singleton

Singleton * Singleton::_pInstance = nullptr;//注意多线程安全问题
Singleton::AutoRelease Singleton::_auto;

int main(void)
{
	Singleton *ps1=Singleton::getInstance();
	ps1->print();

	//Singleton::destroy();
	//Singleton::AutoRlease ar; //error
	return 0;
}
