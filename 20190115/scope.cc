 ///
 /// @file    scope.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-17 11:40:27
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int x = 1;

namespace DF
{

int x = 10;

class Example
{
public:
	Example(int data)
	:x(data)
	{}

	void print(int x) const
	{
		cout << "形参x = " << x << endl;
		cout << "数据成员x = " << Example::x << endl;
		cout << "数据成员x = " << this->x  << endl;
		cout << "命名空间DF中的x = " << DF::x << endl;
		cout << "全局变量x = " << ::x << endl;
	}
private:
	int x;
};
}//end of namespace DF
int main(void)
{
	DF::Example exp(5);
	exp.print(6);
	return 0;
 
}
