 ///
 /// @file    sizeof.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-31 12:13:15
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
class Example
{
public:
	Example(int & ref)
	: _ref(ref)
	{}
	virtual void display() const
	{	cout << "Example::display()" << endl;	}

private:
	double _dd;		  //8
	int & _ref;	 	  //8
	short _sc[4];	  //10
	int _ia;	 	  //4
	char _cb;	 	  //1
	static float _fe; //4  全局静态区
};

int main()
{
	cout << "sizeof(Example) = " << sizeof(Example) << endl;
	return 0;
}
