 ///
 /// @file    point3.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-08 21:59:23
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class Point 
{
public:
	Point(int ix ,int iy)
	: _ix(ix)
	, _iy(iy)
	{

		cout << "Point(int=0,int=0)" << endl;
	}

	Point(const Point &rhs)
	: _ix (rhs._ix)
	, _iy (rhs._iy)
	{
		cout << "Point(const Point &)" <<endl;
	}
	//赋值运算符函数的原型
	//如果返回值为对象，在执行return语句时，会调用构造函数
	//增加程序的开销，所以返回值为引用

	Point& operator=(const Point &rhs)
	{
		_ix= rhs._ix;
		_iy= rhs._iy;
		return *this;
	}


	//this是成员函数的第一个隐含的参数
	void print(/*  Point *const this */)
	{
		cout << "(" <<this ->_ix
			 << "," <<this ->_iy
			 << ")" << endl;


	~Point()
	{
		cout << "~Point()" << endl;
	}

private:
	int _ix;
	int _iy;
};

int test0(void)
{
	Point pt1(1,2);
	cout << "pt1= ";
	pt1.print();

	Point pt2=pt1;
	Point pt3(pt1);
	cout << "pt2=";
	pt2.print();
	
	return 0;
}

//第二种复制构造函数的形式
void func(Point pt)
{
	pt.print();
}



void test1()
{
	Point point(1,2);
	func(point);
}




int func0()
{
	int a=10;
	&a;
	return a;   // 执行return语句是有复制的
}



//第三种复制构造函数的形式
int func1()
{
  Point point(1,2);
  point.print();
  return point;	//Point(const Point&);
}

void test2()
{
	func1();
	//该语句执行结束之后，所使用到的对象都会销毁 没有变成一个持久化对象
	//&func1(); //error 临时对象 右值（不能取地址）
	//Point pt =func1(); //Point(Point &rhs)  b编译器有优化操作
	//Point &rhs=func1();
	//
	const Point &rhs =func1(); //ok

}


void test3()
{
	int a=3, b=4;

	Point pt1(1,2);
	cout << "pt1=";
	pt1.print();

	Point pt2(11, 22);
	 cout << "pt2=" ;
	 pt2.print();

	Point pt3(3, 4);
	pt3.print();    //编译器完成==》pt3.print(&pt3);

	cout << ">>执行pt1=pt2；之后" << endl;

	pt1=pt2;

	pt1.operator=(pt2);
	cout << "pt1= ";
	pt1.print();
}


int main(void)
{
	cout << ">> before testx.." << endl;
	//test0();
	test1();
	//test2();
	//test3();
	cout << ">> after testx.." << endl;
	return 0;
}
