 ///
 /// @file    multimap.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-23 20:16:13
 ///
#include <math.h> 
#include <map>
#include <string>
#include <iostream>
using std::cout;
using std::multimap;
using std::string;
using std::endl;

template <class Container>
void display(const Container & c)
{
	for(auto & elem : c)
		cout << elem.first  << "---->" << elem.second << endl;
}

void test0()
{
	//multimap能存放关键字相同的元素，默认情况下按升序方式进行排列
	multimap<int, string> cities{
		std::pair<int, string>(1, "北京"),
		std::pair<int, string>(2, "上海"),
		std::pair<int, string>(3, "武汉"),
		std::pair<int, string>(2, "深圳"),
		std::pair<int, string>(4, "广州")
	};
	display(cities);

	//访问multimap中的元素，不可以使用下标访问运算符
	//cout << "cites[1] = " << cities[1] << endl; O(logN)
	//cities[0] = "长沙" ; //error
}

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{}

	double getDistance() const
	{
		return sqrt(_ix * _ix + _iy * _iy);
	}

	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);
	friend bool operator<(const Point & lhs, const Point & rhs);
	friend bool operator>(const Point & lhs, const Point & rhs);

	friend class PointComparator;


private:
	int _ix;
	int _iy;
};

std::ostream & operator<<(std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")" ;
	return os;
}

bool operator<(const Point & lhs, const Point & rhs)
{
	cout << "operator<(const Point & lhs, const Point & rhs)" << endl;
	if(lhs.getDistance() < rhs.getDistance())
		return true;
	else if(lhs.getDistance() == rhs.getDistance()) 
		return lhs._ix < rhs._ix;
	else
		return false;
}

bool operator>(const Point & lhs, const Point & rhs)
{
	cout << "operator>(const Point & lhs, const Point & rhs)" << endl;
	if(lhs.getDistance() > rhs.getDistance())
		return true;
	else if(lhs.getDistance() == rhs.getDistance()) 
		return lhs._ix > rhs._ix;
	else
		return false;
}



void test1()
{
//map不能存放关键字相同的元素，默认情况下按升序方式进行排列
multimap<string, Point> points{
	std::pair<string, Point>("1:", Point(1, 2)),
	std::pair<string, Point>("2:", Point(-1, -2)),
	std::pair<string, Point>("3:", Point(1, 2)),
	std::pair<string, Point>("4:", Point(3, 2)),
	std::pair<string, Point>("2:", Point(2, 3)),
	};
	display(points);

	//访问multimap中的元素，不支持下标访问运算符
	//下标访问运算符功能：
	//1. 可以查找相应关键字对应的值；如果pair存在，则直接输出对应的值；
	//	 如果不存在，则创建一个相应关键字的pair，对应的value会调用相应
	//	 类型的默认构造函数创建对象
	//
	//2. 可以修改相应关键字对应的value
	//cout << "cites[1] = " << points["1:"] << endl;
	//cout << "cites[0] = " << points["0:"] << endl;
	//points["5:"] = Point(9, 9);
	//display(points);
	auto ret = points.count("5:");
	if(ret)
		cout << "查找成功！" << endl;
	else
		cout << "查找成功！" << endl;
	auto it = points.find("3:");
	if(it != points.end())
		cout << "查找成功！" << it->second << endl << endl;
	else
		cout << "查找失败！" << endl;
	
	//std::pair<multimap<string, Point>::iterator, bool> ret2 = 
	//points.insert(std::make_pair("6:", Point(6, 6)));
	auto ret2 = points.insert(std::make_pair("6:", Point(8, 8)));
	cout << ret2->first << "---> " << ret2->second << endl;
	display(points);
	//if(ret2.second){
	//	cout << "添加元素成功。" << ret2.first->first<< "---->" << ret2.first->second << endl;
	//}
	//else
	//	cout << "已存在相同关键字的元素。" << ret2.first->first<< "---->" << ret2.first->second << endl;
}


int main(void)
{
	test0();
	//test1();
 
}
