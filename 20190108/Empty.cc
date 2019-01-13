 ///
 /// @file    Empty.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-09 07:39:17
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Empty
{

};




int main(void)
{
	cout << "sizeof(Empty)= " << sizeof(Empty) << endl;
	Empty e1;   // 空类提供了默认构造函数
	Empty e2;
	cout << "sizeof(e1)=" << sizeof(e1) << endl;

	Empty e3(e1);  //空类提供了赋值构造函数
	Empty e4=e2;

	e1=e2;  // 空类提供了赋值运算符函数
	//空类创建的对象能够被正常晓晖，空类也提供了析构函数
	
	return 0;
}
 
