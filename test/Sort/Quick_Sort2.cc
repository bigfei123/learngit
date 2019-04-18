 ///
 /// @file    Quick_Sort2.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-04-18 14:55:37
 ///
 
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::cerr;

void swap(int &a, int &b)
{
	int tmp = 0;
	tmp = a;
	a = b;
	b = tmp;
}
 
//函数Partition除了可以用在快速排序算法中，
//还可以用来实现在长度为n的数组中查找第K大的数字
int Partition(vector<int> & vec, int length, int start, int end)
{
	if(length <= 0 || start < 0 || end >= length)
		cerr << "Invalid Parameters" << endl;
	srand((unsigned)time(nullptr));
	int index = (rand() % (end - start)) + start;

	int small = start - 1;
	for(index = start; index < end; ++index) {
		if(vec[index] < vec[end]) {
			++small;
			if(small != index)
				swap(vec[index], vec[small]);
		}
	}
	++small;
	swap(vec[small], vec[end]);
	return small;
}

void Quick_Sort(vector<int> & vec, int length, int start, int end)
{
	if(start == end)
		return ;
	int index = Partition(vec, length, start, end);
	if(index > start)
		Quick_Sort(vec, length, start, index - 1);
	if(index < end)
		Quick_Sort(vec, length, index + 1, end);
}

int main(void)
{
	vector<int> vec = {2, 7, 6, 9, 5, 4, 1, 8, 0};

	Quick_Sort(vec, vec.size(), 0, vec.size()-1);

	for(auto & val : vec)
	{
		cout << val << " ";
	}
	cout << endl;
	return 0; 
}
 
