 ///
 /// @file    unordered_associative.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-23 21:47:23
 ///
#include <math.h>
#include <unordered_set>
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::unordered_set;
using std::unordered_multiset;

template<class Container>
void display(const Container & c)
{
	for(auto & elem : c)
		cout << elem << " ";
	cout << endl;
}


void test0()
{
	unordered_set<int> numbers{
		6, 7, 2, 3, 6, 8, 1, 4, 5, 1, 5 ,9, 3
	};
	display(numbers);
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

//重载keyEqual 类似与set容器中的compare成员,因为无序容器不需要排序
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
		cout << "*hash<Point>::operator()(const Point &)" << endl;
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
 
//unordered_set
void test1() {
	vector<Point> vec = {
		Point(1, 2),
		Point(3, 4),
		Point(-1, 2),
		Point(1, 2),
		Point(5, 6)
	};
	unordered_set<Point> points(vec.begin(), vec.end());
	auto ret = points.insert(Point(11, 12));
	if(ret.second) {
		cout << "元素添加成功" << *ret.first << endl;
	}else
		cout << "元素已经存在" << *ret.first << endl;

	display(points);
}
	
//unordered_multiset插入操作
void test2() {
	vector<Point> vec = {
		Point(1, 2),
		Point(3, 4),
		Point(-1, 2),
		Point(1, 2),
		Point(5, 6)
	};
	unordered_multiset<Point, PointHasher> points(vec.begin(), vec.end());
	points.insert(Point(11, 12));
	display(points);
}

int main(void)
{
	//test0();
	//test1();
	test2();
	return 0; 
}
