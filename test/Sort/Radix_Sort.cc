 ///
 /// @file    Radix_Sort.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-19 16:47:30
 ///
 
/* 基数排序：
 * 时间复杂度为O(N)，空间复杂度为O(M)，M为桶的数量
 * 不是基于比较的排序，基于桶排序的思想。先将各位桶排序再一次倒出，然后十位
*/

#include <queue>
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::queue;
 
int pickNumber(const int &number, const int &loc)
{
	//返回一个十进制数的第几位，个位为0
	int temp = number;
	if(loc > 0) {
		temp = number/(loc * 10);
	}
	return temp % 10;
}

void Radix_Sort(vector<int> & vec, const int &length)
{
	queue<int> bucket[10];
	for(int i = 0; i < 2; ++i) {
		for(int j = 0; j < length; ++j) {
			int k = pickNumber(vec[j], i);
			bucket[k].push(vec[j]);
		}
		int k = 0;
		for(int j = 0; j < length; ++j) {
			while(!bucket[j].empty())
			{
				vec[k++] = bucket[j].front();
				bucket[j].pop();
			}
		}
	}
}

int main(void)
{
	vector<int> vec = {2, 7, 6, 9, 5, 4, 1, 8, 0};
	Radix_Sort(vec, 9);

	for(auto & val : vec)
	{
		cout << val << endl;
	}
	return 0; 
 
}
