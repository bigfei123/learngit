 ///
 /// @file    initialList.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-07 21:01:12
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Test
{
public:
	Test(int value)
		: _iy(value)//初始化表达式中数据成员初始化的顺序预载初始化表达式中的顺序无关
		, _ix(_iy)  //只与数据成员在被声明时的顺序有关
	{
		cout << "Test(int)"<< endl;
	}

	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" <<endl;
	}

private:
	int _iy;
	int _ix;
};

int main(void)
{
	Test test(1);
	test.print();
	return 0;
}
