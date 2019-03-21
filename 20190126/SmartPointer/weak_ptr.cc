 ///
 /// @file    weak_ptr.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-01 19:22:45
 ///
 
#include <iostream>
#include <memory>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::weak_ptr;
using std::shared_ptr;
 
class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{	cout << "Point(int,int)" << endl;}

	void display() const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	~Point()
	{  cout << "~Point()" << endl;	}

private:
	int _ix;
	int _iy;
};

int main()
{
	weak_ptr<Point> wp; 
	{
		shared_ptr<Point> sp(new Point(1, 2));
		wp = sp;
		cout << "wp's use_count = " << wp.use_count() << endl;
		cout << "sp's use_count = " << sp.use_count() << endl;

		//weak_ptr不能直接访问资源
		shared_ptr<Point> sp2 = wp.lock(); //对weak_ptr进行提升
		cout << "wp's expired is " << wp.expired() << endl;

		if(sp2){
			cout << "提升成功" << endl;
			cout << "*sp2 = ";
			sp2->display();
		}else{
			cout << "提升失败，被托管的对象已被销毁" << endl;
		}
	}

	//由于在语句块外,wp托管的对象已经被销毁
	cout << "wp's expired is " << wp.expired() << endl;

	cout << "已经退出语句块" << endl;
	shared_ptr<Point> sp2 = wp.lock(); //对weak_ptr进行提升
	//此时sp2为默认的shared_ptr<Point>,无托管对象
	//如果提升成功sp2有托管对象,否则无托管对象
	if(sp2){
		cout << "提升成功" << endl;
		cout << "*sp2 = ";
		sp2->display();
	}else{
		cout << "提升失败，被托管的对象已被销毁" << endl;
	}
	
	return 0;
}
