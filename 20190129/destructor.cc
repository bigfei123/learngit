 ///
 /// @file    destructor.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-31 12:41:42
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
class Base
{
public:
	Base()
	: _pdata(new int(0))
	{	 cout << "Base()" << endl;	}

	virtual void display() const
	{	cout << "Base::display() *_pdata = " << *_pdata << endl;}

	virtual ~Base()
	{
		cout << "~Base()" << endl;
		delete _pdata;
	}

private:
	int * _pdata;
};

class Derived
: public Base
{
public:
	Derived(int data)
	: Base()
	, _pdata2(new int(data))
	{	cout << "Derived(int)" << endl;}

	virtual void display() const
	{	cout << "Base::display() *_pdata2 = " << *_pdata2 << endl;}

	//只要将基类的析构函数设置为虚函数之后，派生类析构函数自动成为虚函数
	~Derived()
	{
		cout << "~Derived()" << endl;
		delete _pdata2;
	}

private:
	int *_pdata2;
};


int main(void)
{
	Base *pdata = new Derived(100);
	pdata->display();

	delete pdata;
	return 0;
}
