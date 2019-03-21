 //
 /// @file    multiset.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-23 13:57:17
 ///
#include <math.h> 
#include <set>
#include <string> 
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::multiset;
using std::ostream;

template <class Container>
void display(const Container  & c)
{
	for(auto & elem : c ) {
		cout << elem << " ";
	}
	cout << endl;
}

void test0()
{
	std::pair<int, string> value(10000,"万科");
	cout << value.first << "---->" << value.second << endl;
}

void test1()
{
	//multiset默认情况下会按升序的方式进行排序
	//能够存放关键字相同的元素
	//int array[10] = {3, 2, 6, 7, 2, 3 ,8, 4, 1, 1};
	//multiset<int> numbers(array, array + 10);
	multiset<int> numbers{3, 2, 5, 3, 6, 2, 3, 7, 4, 1, 1, 1};
	display(numbers);

	//multiset并不支持下标访问运算符
	//cout << numbers[0] << endl;
	multiset<int>::iterator sit = numbers.begin();
	++sit;
	cout << "*sit = " << *sit << endl;

	//查找元素
	size_t cnt = numbers.count(1); //返回 “1" 的个数
	cout << "cnt = " << cnt << endl;
	cnt = numbers.count(9);
	cout << "cnt = " << cnt << endl;

	multiset<int>::iterator it = numbers.find(6);
	if(it == numbers.end())
		cout << "Not found " << endl;
	else
		cout << "*it = " << *it << endl;
	//删除元素
	cout << endl << "delete element : " << endl;
	auto it2 = numbers.begin();
	++it2;
	numbers.erase(it2);
	display(numbers);

	//修改元素
	it2 = numbers.begin();
	//it2 = 100; //error 不能修改，因为底层实现是HB - tree
	
	//查找元素
	cout << endl << "测试范围查找:" << endl;
	it = numbers.lower_bound(3);
	it2 = numbers.upper_bound(3);

	while(it != it2) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	cout << "*it = " << *it << endl; //返回key的下一个下标

	std::pair<multiset<int>::iterator, multiset<int>::iterator>
	ret = numbers.equal_range(3);
	while(ret.first != ret.second) {
		cout << *ret.first<< " ";
		++ ret.first;
	}
	cout << endl;

}

void test2()
{
	//降序输出
	int array[10] = {3, 2, 6, 7, 2, 3, 8, 4, 1, 1};
	multiset<int, std::greater<int>> numbers(array, array + 10);
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

//函数对象
struct PointComparator
{
	bool operator()(const Point & lhs, const Point & rhs)
	{
		if(lhs.getDistance() < rhs.getDistance())
			return true;
		else if(lhs.getDistance() == rhs.getDistance()) 
			return lhs._ix < rhs._ix;
		else
			return false;
	}
};

void test3()
{
	//multiset<Point> points
	//multiset<Point, std::greater<Point>> points
	multiset<Point,PointComparator> points{
		Point(1, 2),
		Point(0, 2),
		Point(-1, -2),
		Point(3, 2),
		Point(4, -2),
		Point(1, 2),
	};
	display(points);
}


int main(void)
{
	//test0();
	//test1();
	//test2();
	test3();
}
