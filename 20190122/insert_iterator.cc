 ///
 /// @file    insert_iterator.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-24 18:46:03
 ///
#include <iterator>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::copy;
using std::set;
using std::back_insert_iterator;
using std::front_insert_iterator;
using std::insert_iterator;
using std::ostream_iterator;
 
int main(void)
{
	vector<int> numbers1{1, 2, 3};
	list<int> numbers2{11, 12, 13};

	//back_insert_iterator要调用的是push_back方法
	//后插迭代器的初始化，首先需要指明容器类型，
	//然后还要赋一个具体的容器，使他们绑定在一起
	back_insert_iterator<vector<int>> iter(numbers1);
	copy(numbers2.begin(), numbers2.end(), iter );
	//copy(numbers2.begin(), numbers2.end(),back_insert_iterator<vector<int>>(numbers1));
	
	//输出numbers1内容
	copy(numbers1.begin(), numbers1.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	//front_insert_iterator要调用的是push_front方法
	copy(numbers1.begin(), numbers1.end(), front_insert_iterator<list<int>>(numbers2));
	copy(numbers2.begin(), numbers2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	vector<int> numbers3{22, 33, 44, 55};
	auto sit = numbers3.begin();
	++sit;

	//insert_iterator要调用的是insert方法
	copy(numbers1.begin(), numbers1.end(), insert_iterator<vector<int>>(numbers3, sit));
	//插入到set中后元素会自动升序排列
	copy(numbers3.begin(), numbers3.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
 
}

