 ///
 /// @file    namespace1.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-02 16:03:45
 ///
 
#include <iostream>
//using std::cout;
using std::endl;
 
namespace  wd
{
	int number = 10;
	void display()
	{
		std::cout << "wd::display()" << endl;
	}
	
}//end of namespace wd

//如果使用作用域限定符，即使自定义的实体与std空间的实体重名了，也没有关系
int cout(int x, int y)
{
	std::cout << "x = " << x << ", y = " << y << endl;
	std::cout << "cout()" << std::endl;
	return 0;
}

int main(void)
{
	std::cout << "number  = "  << wd::number << endl;//作用域限定符
	wd::display();
	return 0;
}
