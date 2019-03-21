 ///
 /// @file    circle_reference.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-01 18:30:08
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;

class Child;
class Parent
{
public:
	Parent()
	{	cout << "Parent()" << endl;	}
	~Parent()
	{	cout << "~Parent()" << endl;}

	shared_ptr<Child> pChild;
};

class Child
{
public:
	Child()
	{	cout << "Child()" << endl;	}
	~Child()
	{	cout << "~Child()" << endl;	}

	shared_ptr<Parent> pParent;
};
 
int main(void)
{
	//shared_ptr的循环引用会导致内存泄漏
	shared_ptr<Parent> parentPtr(new Parent());
	shared_ptr<Child> childPtr(new Child());
	cout << "parentPtr's use_count = " << parentPtr.use_count() << endl;
	cout << "childPtr's use_count = " << childPtr.use_count() << endl;
	
	parentPtr->pChild = childPtr;
	childPtr->pParent = parentPtr;
	cout << "parentPtr's use_count = " << parentPtr.use_count() << endl;
	cout << "childPtr's use_count = " << childPtr.use_count() << endl;
}
