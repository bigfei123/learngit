 ///
 /// @file    priority_queue.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-24 16:04:48
 ///
#include <math.h> 
#include <queue>
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::priority_queue;

void test0()
{
	//优先级队列的底层实现采用的是堆排序
	//默认情况下是一个大顶堆，当有新来的元素添加到队列中时，
	//堆顶元素要与新来元素作比较，如果条件成立，将当前的堆顶元素放到堆底
	//然后将新添加的元素放到堆顶，然后再进行堆的调整
	vector<int> numbers = {3, 6, 7, 1, 2, 4, 8, 7, 5};
	priority_queue<int> pque;
	for(size_t idx = 0; idx != numbers.size(); ++idx) {
		pque.push(numbers[idx]);
		cout << "当前优先级队列中，优先级别最高的元素是：" << pque.top() << endl;
	}
	while(!pque.empty()) {
		cout << pque.top() << " ";
		pque.pop();
	}
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
	//cout << "operator>(const Point & lhs, const Point & rhs)" << endl;
	if(lhs.getDistance() > rhs.getDistance())
		return true;
	else if(lhs.getDistance() == rhs.getDistance()) 
		return lhs._ix > rhs._ix;
	else
		return false;
}

//设置成小顶堆
void test1()
{
	vector<int> numbers = {3, 6, 7, 1, 2, 3, 9, 8, 5};
	priority_queue<int, vector<int>, std::greater<int>> pque;
	for(size_t idx = 0; idx != numbers.size(); ++idx) {
		pque.push(numbers[idx]);
		cout << "当前优先级队列中，优先级别最高的元素是：" << pque.top() << endl;
	}
	while(!pque.empty()) {
		cout << pque.top() << " ";
		pque.pop();
	}
	cout << endl;
}

void test2()
{
	vector<Point> numbers = {
		Point(1, 2),
		Point(3, 4),
		Point(-1, 2),
		Point(1, 2),
		Point(5, 6)
	};
	priority_queue<Point, vector<Point>, std::greater<Point>> pque;
	for(size_t idx = 0; idx != numbers.size(); ++idx) {
		pque.push(numbers[idx]);
		cout << "当前优先级队列中，优先级别最高的元素是：" << pque.top() << endl;
	}
	while(!pque.empty()) {
		cout << pque.top() << endl;
		pque.pop();
	}
	cout << endl;
}

int main()
{
	//test0();
	//test1();
	test2();
	return 0;
}
