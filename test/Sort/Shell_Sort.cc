 ///
 /// @file    Shell_Sort.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-19 16:40:07
 ///
 
/* 希尔排序：
 * 时间复杂度：O(N*logN),时间复杂度依赖于步长的选择。
 * 空间复杂度：O(1)
*/

#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
 
void swap(int&a, int &b)
{
	int tmp = 0;
	tmp = a;
	a = b;
	b = tmp;
}

void Shell_Sort(vector<int>& vec, const int &length, int step) 
{
	while(step > 0) {
		for(int i = step; i < length; ++i) {
			int temp = i;
			while(temp >= step) {
				if(vec[temp] < vec[temp - step]) {
					swap(vec[temp], vec[temp - step]);
				}
				temp -= step;
			}
		}
		--step;
	}
}

int main(void)
{
	vector<int> vec = {2, 7, 6, 9, 5, 4, 1, 8, 0};
	Shell_Sort(vec, 9, 1);

	for(auto & val : vec)
	{
		cout << val << endl;
	}
	return 0; 
 
}
