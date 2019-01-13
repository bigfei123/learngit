 ///
 /// @file    singleton.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-10 09:02:49
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//单例模式：要求通过该类只能创建出一个对象
//1.该对象不能是栈对象,只能是堆对象
//2.将构造函数私有化
//3.在类中定义一个静态的指针对象（私有），并在类外初始化为空
//4.定义一个返回值为类指针的静态成员函数
//
//
//1.只要出现的全局变量都可以用单例模式替代
//2.对于全局唯一的资源，都可以使用单例模式
//		> 对于配置文件的读取
//		> 对于词典类
//		> 对于日志系统的写日志的对象
//		

class Singleton
{
	public:
		static Singleton * getInstance()
		{
			if(nullptr == _pInstance) {
				_pInstance = new Singleton();
			}

			return _pInstance;
		}

		static void destroy()
		{
			if(_pInstance)   //如果对象存在则撤销对象
				delete _pInstance;
		}

	private:
		Singleton() {cout << "Singleton()" << endl; }
		~Singleton(){cout << "~Singleton()" << endl; }
	private:
		static Singleton * _pInstance;
};

Singleton * Singleton:: _pInstance = nullptr;
//Singleton s3; // error
//Singleton s4;

int main(void)
{
//	Singleton s1; //error 该语句不能让他编译通过
//	Singleton s2;
//  Singleton *ps1 = new Singleton();  //在类之外不能正常调用
	Singleton * ps1 = Singleton::getInstance();//通过类名调用静态成员函数
	Singleton * ps2 = Singleton::getInstance();
	cout << "ps1 = " << ps1 << endl
		 << "ps2 = " << ps2 << endl;
	//delete ps1;//error
	//
	Singleton::destroy();
	return 0;

}
