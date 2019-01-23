 ///
 /// @file    arrow.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-16 11:58:54
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Data
{
public:
	Data(int data = 10)
	: _data(data)
	{	cout << "Data(int)" << endl;}

	int getData() const
	{	return _data; }


	~Data()
	{	cout << "~Data()" << endl;}
private:
	int _data;
};

class SmartPointer
{
public:
	explicit
	SmartPointer(Data *data)
	: _data(data)
	{	cout << "SmartPointer(data*)" << endl;  }
	//返回指向Data的指针,重载了指针访问运算符
	Data * operator->()
	{	return _data;	}
	//重载了解引用访问运算符
	Data & operator*()
	{	return *_data;	}

	~SmartPointer()
	{
		delete _data;
		cout << "~SmartPointer()" << endl;
	}
private:
	Data * _data;

};

class ThirdLayer
{
public:
	ThirdLayer(SmartPointer *pointer)
	: _pointer(pointer)
	{	cout << "ThirdLayer(SmartPointer*)" << endl; }
	//返回的是一个重载了箭头运算符的对象
	SmartPointer & operator->()//
	{	return *_pointer; }

	~ThirdLayer()
	{
		delete _pointer;
		cout  << "~ThirdLayer()" << endl;
	}

private:
	SmartPointer * _pointer;

};

int main(void)
{
	SmartPointer pointer(new Data(3));
	cout << pointer->getData() << endl;//简写
	cout << (pointer.operator->())->getData() << endl;

	cout << (*pointer).getData() << endl;
	ThirdLayer tl(new SmartPointer(new Data())); 
	cout << tl->getData() << endl;//简写
	cout << ((tl.operator->()).operator->())->getData() << endl;
	//tl.operater->()得到的是SmartPointer的对象，进一步调用operater->()是
	//Data的指针，最后通过该指针调用getData()方法。
	return 0;
}
