 ///
 /// @file    RAII.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-01 16:39:10
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
template <class T>
class RAII
{
public:
	explicit
	RAII(T * data)
	: _data(data)
	{	cout << "RAII(T *data)" << endl;	}

	T * operator->()
	{	return _data;	}

	T & operator*()
	{	return *_data;	}

	void reset(T * data)
	{
		if(_data)
			delete _data;
		_data = data;
	}

	~RAII()
	{
		if(_data)
			delete _data;
	}
private:
	T *_data;
};

class Point
{
public:
	Point(int ix = 0,int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{	cout << "Point(int, int)}" << endl;	}

	~Point()
	{
		cout << "~Point()" << endl;	
	}

	void display() const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

private:
	int _ix;
	int _iy;
};

int main()
{
	RAII<Point> pPoint(new Point(1, 2));
	//箭头运算符返回的是指向Point类型的指针
	pPoint->display();
	//解引用运算符返回的是绑定Point类型的引用
	(*pPoint).display();

	return 0;
}

