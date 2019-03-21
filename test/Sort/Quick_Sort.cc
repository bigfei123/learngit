 ///
 /// @file    Quick_Sort.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-18 19:11:50
 ///
 
/* 快速排序
 * 时间复杂度O(N*logN),空间复杂度O(logN), O(N)
 * 1.先从数列中取出一个数作为基准数
 * 2.分区过程，将比这个数大的数全放到它的右边，小于或等于它的数全放到它的左边。
 * 3.再对左右区间重复第二步，直到各区间只有一个数。
 * 4.不稳定的算法
*/

#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

void swap(int &a, int &b)
{
	int tmp = 0;
	tmp = a;
	a = b;
	b = tmp;
}

void Quick_Sort(vector<int> & vec, const int & start, const int & end)
{
	if(start >= end)
		return ;
	int mid = vec[end];//待排序的最后一个元素作为基准元素
	int left = start, right = end - 1;
	while(left < right) { //在整个范围内搜寻比mid小或大的元素
	//然后将左侧元素与右侧元素交换
		while(vec[left] < mid && left < right)
		//试图在左侧找到一个比mid更大的元素
			left ++;
		while(vec[right] >= mid && left < right)
		//试图在右侧找到一个比mid更小的元素
			right--;
		swap(vec[left], vec[right]);
	}
	if(vec[left] >= vec[end])
		swap(vec[left], vec[end]);
	else
		left++;
	//cout << "left = " << left << endl;
	Quick_Sort(vec, start, left - 1);
	Quick_Sort(vec, left + 1, end);
}
 
int main(void)
{
	vector<int> vec = {2, 7, 6, 9, 5, 4, 1, 8, 0};
	Quick_Sort(vec, 0, 8);

	for(auto & val : vec)
	{
		cout << val << endl;
	}
	return 0; 
}
