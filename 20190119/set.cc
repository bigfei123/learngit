 ///
 /// @file    set.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-21 18:24:51
 ///
#include <math.h>
#include <string> 
#include <iostream>
#include <set>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::set;
using std::vector;

template <class Container>
void display(const Container & c)
{
	for(auto & elem: c)
	{
		cout << elem << " ";
	}
	cout << endl;
}

void test0()
{
	std::pair<int, string> value(1111, "万达" );
	cout << value.first << "--->" << value.second << endl;
}

void test1()
{
	//set默认情况下会按升序的方式进行排序，
	//不会存放关键字相同的元素
	//int array[10] = {3, 2, 5 ,1, 5, 7, 4, 9};
	//set<int> number(array, array + 10);
	set<int> numbers{3, 2, 5, 1, 5, 7, 4, 9};
	display(numbers);

	//set并不支持下标访问运算符
	//cout << number[0] << endl;
	set<int>::iterator sit = numbers.begin();
	++sit;
	cout << "*sit = " << *sit << endl;

	//查找元素， 其时间复杂度是O(lonN) ==>二分查找 ==》底层实现是红黑树
	//count(): 在容器中查找指定元素，有返回1，没有返回0
	size_t cnt = numbers.count(1);
	cout << "cnt = " << cnt << endl;
	cnt = numbers.count(9);
	cout << "cnt = " << cnt << endl;
	//find(): 在容器中查找指定元素，并返回当前迭代器的值。
	//set<int>::iterator it = numbers.find(8);
	set<int>::iterator it = numbers.find(9);
	if(it == numbers.end())
		cout << "该值不在numbers之中" << endl;
	else
		cout << "已找到， *it = " << *it << endl;
	//添加元素
	//std::pair<iterator,bool> insert( const value_type& value );
	std::pair<set<int>::iterator, bool> ret = numbers.insert(9);
	if(ret.second) {
		cout << "添加元素成功!" << *ret.first << endl;
	}else
		cout << "添加元素失败！该元素已存在" << endl;

	vector<int> vec{1, 2, 3, 10, 11, 12};

	numbers.insert(vec.begin(), vec.end());
	display(numbers);
	
	//删除元素
	cout << endl << "删除元素:" << endl;
	auto it2 = numbers.begin();
	++ it2;
	numbers.erase(it2);
	display(numbers);

	//修改元素
	// *it = 100; //error 不能修改，因为底层是现实红黑树
	// 如果能够修改，会破坏红黑树的结构
}
	
//set默认升序输出，test2执行降序输出
void test2()
{
	int array[10] = { 3, 2, 6, 7, 2, 3, 8, 4, 1, 1};
	set<int, std::greater<int>> numbers(array, array + 10);
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

	friend class PointComparator;
	friend bool operator<(const Point & lhs, const Point & rhs);
	friend bool operator>(const Point & lhs, const Point & rhs);
	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);

private:
	int _ix;
	int _iy;
};

std:: ostream & operator<<(std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}

//bool operator<(const Point & lhs, const Point & rhs)
//{
//	if(lhs.getDistance() < rhs.getDistance())
//		return true;
//	else if(lhs.getDistance() == rhs.getDistance()){
//		return lhs._ix > rhs._ix;
//	}else
//		return false;
//}

bool operator>(const Point & lhs, const Point & rhs)
{
	if(lhs.getDistance() > rhs.getDistance())
		return true;
	else if(lhs.getDistance() == rhs.getDistance()){
		return lhs._ix < rhs._ix;
	}else
		return false;
}
////自定义比较器,函数对象
struct PointComparator
{
	bool operator()(const Point & lhs, const Point & rhs)
	{
		cout << "bool operator()(const Point &,const Point &)" << endl;
		if(lhs.getDistance() < rhs.getDistance())
			return true;
		else if(lhs.getDistance() == rhs.getDistance()) {
			return lhs._ix < rhs._ix;
		}else
			return false;
	}
};

void test3()
{
	//set<类型参数、比较参数(结构体)、配置器>
	//重载了<运算符,比较Point到原点距离，重载了<<运算符，依次输出各点
	//set<Point, std::greater<Point>> numbers{
	set<Point, PointComparator> numbers{
		Point(1, 2),
		Point(0, 2),
		Point(-1, -2),
		Point(3, 2),
		Point(4, -2),
		Point(1, 2),
	};
	display(numbers);
}
int main()
{
	//test0();
	//test1();
	//test2();
	test3();
}
