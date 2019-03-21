 ///
 /// @file    istream_iterator.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-24 16:55:07
 ///
 
#include <iterator>
#include <vector>
#include <algorithm>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::copy;
using std::istream_iterator;
using std::ostream_iterator;
 
int main(void)
{
	vector<int> numbers;
	istream_iterator<int> isi(std::cin);
	//numbers此时待用户输入数据之前vector是没有开辟空间的,此时的获取vec的迭代器是无效的
	//运行会出现断错误,安插迭代器可以在不分配内存的情况下直接插入。
	//istream_iterator<int>()定义的是匿名的istream对象，表示参数InputIt last，表示isi的最后一位元素的下一位置
	istream_iterator<int> eof;
	//copy(isi, istream_iterator<int>(), numbers.begin()); //调用push_back
	copy(isi, /*istream_iterator<int>()*/eof, std::back_inserter(numbers));//调用push_back
	copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
 
}




