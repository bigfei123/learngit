 ///
 /// @file    for_each.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-27 09:45:15
 ///
 
#include <algorithm>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::for_each;


void display(int & number)
{
	cout << number << " ";
	number++;
}
 
int test0(void)
{
	vector<int> numbers{1, 2, 3, 4, 5};
	//for_each(numbers.begin(), numbers.end(), display);
	//cout << endl;
	
	//lambda表达式 =》匿名函数
	//[capture list] (params list) {function body}
	for_each(numbers.begin(), numbers.end(), [](int & number){
		++number;							//引用捕获,可以修改该外部变量的值
		cout << number << " ";				//值捕获,无法修改
	});										//隐式捕获，通过[=]、[&],前者是值捕获，后者是引用捕获
	cout << endl;
	for(auto & elem : numbers)
		cout << elem << " ";
	cout << endl;
	return 0;
}

void test1()
{
	vector<int> numbers{1, 2, 3, 1, 6, 7, 2, 2, 4, 5};
	std::sort(numbers.begin(), numbers.end());

	for_each(numbers.begin(), numbers.end(), [](int & number){
			++number;
			cout << number << " ";
	});
	cout << endl;

	//时间复杂度是O(N)
	//count(first, last, const int & value) 返回与count相等的值的个数
	int ret = std::count(numbers.begin(), numbers.end(), 2);
	cout << "ret = " << ret << endl;

	//时间复杂度为O(logN), 对于有序的元素采用二分查找更快
	//查到返回1，否则返回0
	bool found = std::binary_search(numbers.begin(), numbers.end(), 9);
	cout << "found = " << found << endl;

	//时间复杂度为O(N)
	//返回第一次查找到的元素迭代器
	auto it = std::find(numbers.begin(), numbers.end(), 3);
	cout << "*it = " << *it << endl;

	for(auto & elem : numbers)
		cout << elem << " ";
	cout << endl;
}

int main()
{
	//test0();
	test1();
}
