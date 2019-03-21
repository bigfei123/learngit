 ///
 /// @file    namespace1.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-02 16:03:45
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
namespace  wd
{
	int number = 10;
	void display()
	{
		cout << "wd::display()" << endl;
	}
	
}//end of namespace wd

int main(void)
{
	cout << "number  = "  << wd::number << endl;//作用域限定符
	wd::display();
	return 0;
}
