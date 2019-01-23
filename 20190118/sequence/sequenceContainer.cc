 ///
 /// @file    sequenceContainer.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-19 22:52:34
 ///
 
#include <iostream>
#include <vector>
#include <deque>
#include <list>

using std::cout;
using std::endl;
using std::vector;
using std::deque;
using std::list;

template <class Container>
void display(const Container & c)
{
	for(auto & elem : c) {  
		cout << elem << " ";
	}
	cout << endl;
}

class Point
{
public:
	Point(int ix, int iy)	
	:_ix(ix)
	,_iy(iy)
	{}

	friend std::ostream & operator<<(std::ostream & os,const Point & rhs);
private:
	int _ix;
	int _iy;
};

std::ostream & operator<<(std::ostream & os,const Point & rhs)
{
	cout << "(" << rhs._ix
		 << "," << rhs._iy
		 << ")" ;
	return os;
}

void test0()
{
	vector<Point> points{
		Point(1, 2),
		Point(3, 4),
		Point(-1, -2),
		Point(-1, -3)
	};

	points.emplace_back(11, 22); //直接传参,在内部构造一个Point对象

	display(points);
}

void test1()
{
	//vector<int> numbers(10, 1);
	int array[10] = {1,2,3 ,4 ,5 ,6 ,7 ,8, 9,10};
	vector<int> numbers(array, array + 10);
	display(numbers);
	cout << "sizeof(vector<int>) = " << sizeof(vector<int>) << endl;
	//vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9};
	// &numbers; 求的是指向第一个元素指针的栈地址
	cout << "&numbers[0]"<< &numbers[0]<< endl;	
	//第一个元素的首地址
	cout << "&*numbers.begin()" << &*numbers.begin()<< endl ; 
	//第一个元素的首地址
	int *pdata = numbers.data();
	cout << "number[0] = " << *pdata << endl;
	cout << "number's size = " << numbers.size() << endl
		 << "number's capacity = " << numbers.capacity() << endl;

	//通过迭代器方式访问
	vector<int>::const_iterator cite;
	for(cite = numbers.begin(); cite != numbers.end(); ++cite) {
		cout << *cite << " ";
	}
	cout << endl;

	//push_back/pop_back
	numbers.push_back(10);
	numbers.push_back(11);
	//numbers.shrink_to_fit();  //回收多余的空间 不回收是18.回收之后为11
	cout << "numbers's size = " << numbers.size() << endl
		 << "numbers's capacity = " << numbers.capacity() << endl;

	//auto类型
	auto it = numbers.begin();
	for(; it != numbers.end(); ++it)
	{
		cout << *it<< " ";
	}
	cout << endl;

	numbers.pop_back();
	numbers.pop_back();
	//C++11
	display(numbers);
	//vector为什么不提供在头部添加元素的操作？
	//push_front/pop_front操作的时间复杂度为O(n)
	//
	//在中间位置添加元素
	cout << endl;
	it = numbers.begin();
	++it; ++it;
	numbers.insert(it, 22);
	display(numbers);
	cout << "number's capacity = " << numbers.capacity() << endl;

	cout << "*it = " << *it << endl;
	vector<int> vec{41, 42, 43 ,44, 45, 46, 47, 48, 49};//导致迭代器失效的问题
	numbers.insert(it, vec.begin(), vec.end());  //会导致numbers进行扩容操作
	cout << "number's capacity = " << numbers.capacity() << endl;
	display(numbers);

	it = numbers.begin(); //此时需要重新定位迭代器的位置
	++it; ++it;
	numbers.insert(it, 3, 33);
	cout << "*it = " << *it << endl;
	display(numbers);

	//清空元素
	numbers.clear();
	numbers.shrink_to_fit();
	display(numbers);
	cout << "numbers's size = " << numbers.size() << endl
		 << "numbers's capacity = " << numbers.capacity() << endl;

}

void test2()
{
	deque<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	cout << "numbers's size = " << numbers.size() << endl;

	deque<int>::const_iterator cit;
	for(cit = numbers.begin(); cit != numbers.end(); ++cit)	{
		cout << *cit << " ";
	}	
	cout << endl;
	numbers.push_back(10);
	numbers.push_back(11);
	display(numbers);
	numbers.pop_back();
	display(numbers);
	numbers.push_front(0);
	display(numbers);
	numbers.pop_front();
	display(numbers);

	//deque支持下标访问
	cout << "number[4] = " << numbers[4] << endl;
	//在中间位置添加元素
	cout << endl;
	auto it = numbers.begin();
	++it; ++it;
	numbers.insert(it, 22);
	display(numbers);
	cout << "*it = " << *it << endl;
	numbers.insert(it, 3, 33);
	display(numbers);
	cout << "*it = " << *it << endl;
	vector<int> vec{41, 42, 43};
	numbers.insert(it, vec.begin(), vec.end());
	display(numbers);
	numbers.clear();
	numbers.shrink_to_fit();
	display(numbers);
	cout << "number.size() =" << numbers.size() << endl;
}

void test3()
{
	list<int> numbers {1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << "numbers's size = " << numbers.size() << endl;

	list<int>::const_iterator cit;
	for(cit = numbers.begin(); cit != numbers.end(); ++cit) {
		cout << *cit << " ";
	}
	cout << endl;
	numbers.push_back(10);
	numbers.push_back(11);
	display(numbers);
	numbers.pop_back();
	display(numbers);

	//list 不支持下标访问运算符
	//cout << "number[4] = " << numbers[4] << endl;
	//
	//在中间位置添加元素
	cout << endl;
	auto it = numbers.begin();
	++it; ++it;
	numbers.insert(it, 22);
	display(numbers);
	cout << "*it = " << *it << endl;
	numbers.insert(it, 3, 33);
	display(numbers);
	cout << "*it = " << *it << endl;
	vector<int> vec{41, 42, 43};
	numbers.insert(it, vec.begin(), vec.end());
	display(numbers);
	numbers.clear();//清空元素的同时，空间也回收了
	//numbers.shrink_to_fit();   list 没有shrink_to_fit()方法
	display(numbers);
	cout << "number.size() =" << numbers.size() << endl;
}

void test4()
{
	vector<int> vec{1, 2, 3, 4, 5};
	display(vec);
	auto it = vec.begin();
	++it;  ++it;
	cout << "vec.capacity()" << vec.capacity() << endl;
	vec.insert(it, 22);
	display(vec);
	it = vec.begin(); //重新设置迭代器位置
	vec.insert(it, 10, 10); //error 迭代器失效
	display(vec);
	cout << "vec.capacity()" << vec.capacity() << endl;

}
int main()
{
	//test0();
	cout << ">>>vector:" << endl;
	//test1();
	cout << ">>>deque:" << endl;
	//test2();
	cout << ">>>list:" << endl;
	//test3();
	test4();
	return 0;
}
