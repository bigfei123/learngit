 ///
 /// @file    namespace3.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-02 16:15:06
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
int number = 1 ;

namespace wd
{
int number = 10;

void display(int number)
{
	cout << "全局number = " << ::number << endl;
	cout << "wd::number = " << wd::number << endl;
	cout << "形参number = " << number << endl;
}

namespace df
{
int number = 1000;
void display()
{
	cout << "wd::df::number = " << wd::df::number << endl;
}

}//end of namespace df

}//end of namespace wd


int main(void)
{
	wd::display(100);
	wd::df::display();
	return 0; 
}
