 ///
 /// @file    Select_Sort.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-18 14:59:14
 ///
 

#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
 
//时间复杂度为O(N^2)
//空间复杂度为O(1)
//每一轮中查找最小的数，并将其与min替换,故选择排序每一轮就能确定一个最终数
void swap(int &a, int &b) {
	int tmp = 0;
	tmp = a;
	a = b;
	b = tmp;
}

void Select_Sort(vector<int> &vec, const int &length)
{
	int minIndex = -1;
	for(int i = 0; i < length; ++i) {
		minIndex = i;
		for(int j = 1; j < length-i; ++j) {
			if(vec[j + i] < vec[minIndex]) {
				minIndex = j + i;
			}
		}
		swap(vec[i], vec[minIndex]);
	}
}

int main()
{
	vector<int> vec = {2, 6, 3, 7, 5, 8, 1};
	int length = vec.size();

	Select_Sort(vec, length);
	for(auto & idx : vec) {
		cout << idx << endl;
	}
}


