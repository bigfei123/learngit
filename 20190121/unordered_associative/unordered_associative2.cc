 ///
 /// @file    unordered_associative2.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-24 15:43:48
 ///
 
#include <math.h>
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::unordered_map;
using std::make_pair;

template<class Container>
void display(const Container & c)
{
	for(auto & elem : c)
		cout << elem.first << "--->"<< elem.second << endl;
	cout << endl;
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

	
	int getX() const { return _ix; }
	int getY() const { return _iy; }

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

//    重载keyEqual 类似与set容器中的compare成员,因为无序容器不需要排序
//当不同关键字，通过hash函数，可能会得到相同的关键字值，每当我们在unordered_set
//里面做数据插入、删除时，由于unordered_set关键字唯一性，所以我们得确保唯一性
bool operator==(const Point & lhs, const Point & rhs)
{
	return (lhs.getX() == rhs.getX()) && (lhs.getY() == rhs.getY());
}

namespace std
{
//在std的命名空间里写出一个针对自定义类型Point类型的特化版本的hash函数
template <>
struct hash<Point>
{
	size_t operator()(const Point & pt) const
	{
		cout << "hash<Point>::operator()(const Point &)" << endl;
		return (pt.getX() << 2) | (pt.getY() << 2);
	}
};

}//end of namespace std

//通过定义函数对象，实现相应的hash函数，这也就意味我们可以
//通过自定义相应的函数对象，来实现自定义hash函数
struct PointHasher
{
	size_t operator()(const Point & pt) const
	{
		cout << "hash<Point>::operator()(const Point &)" << endl;
		return (pt.getX() << 2) | (pt.getY() << 2);
	}

};
 
void test0()
{
	//无重复乱序输出
	unordered_map<string, string> numbers{
		make_pair("111", "北京"),
		make_pair("222", "上海"),
		make_pair("111", "武汉"),
		make_pair("333", "深圳"),
		make_pair("000", "广州"),
	};
	display(numbers);
}
//unordered_set
void test1() {
	unordered_map<string, Point> points {
		make_pair("111",Point(1, 2)),
		make_pair("222",Point(3, 4)),
		make_pair("333",Point(-1, -2)),
		make_pair("222",Point(5, 5)),
		make_pair("444",Point(2, 3))
	};
	display(points);
	auto ret = points.insert(make_pair("555",Point(11, 12)));
	if(ret.second) {
		cout << "元素添加成功" << ret.first->first << "---->" << ret.first->second << endl;
	}else
		cout << "元素已经存在" << ret.first->first << "---->" << ret.first->second << endl;
	display(points);

	//下标访问运算符效果与map的相同，其时间复杂度为O(1)
	cout << "points[222] = " << points["222"] << endl;
	points["222"] = Point(-1, -10);
	cout << "points[666] = " << points["666"] << endl;
	cout << endl;
	display(points);
}

int main()
{
	test0();
	test1();
}
