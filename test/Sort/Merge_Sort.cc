 ///
 /// @file    Merge_Sort.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-18 16:17:38
 ///
 
/* 归并排序
 * 时间复杂度O(N*logN), 空间复杂度O(N)
 * 先将所有数两个一组排序，再将两组四个数一起排序为新的一组
 * 循环下去每次合并两组，知道所有数有序
*/

#include <iostream>
#include <vector>
using std::cout;
using std::vector;
using std::endl;
 
void Merge(vector<int> & vec, const int & start, const int &mid, const int & end)
{
	vector<int> TempArray;
	int i = start;
	int j = mid + 1;
	int k = end - start + 1;
	while(i <= mid && j <= end)
	{
		if(vec[i] <= vec[j]) {
			TempArray.push_back(vec[i++]);
		}else {
			TempArray.push_back(vec[j++]);
		}
	}

	while(i <= mid) {
		TempArray.push_back(vec[i++]);
	}
	while(j <= end) {
		TempArray.push_back(vec[j++]);
	}
	for(int i = 0; i < k; ++i) {
		vec[start + i] = TempArray[i];
	}
}

void Merge_Sort(vector<int> & vec, const int & start, const int &end)
{
	if(start < end)
	{
		int mid = start + (end - start)/2;//(start + end) / 2;
		Merge_Sort(vec, start, mid);
		Merge_Sort(vec, mid+1, end);
		Merge(vec, start, mid, end);
	}
}

int main(void)
{
	vector<int> vec = {2, 7, 6, 9, 5, 4, 1, 8, 0};
	Merge_Sort(vec, 0, 8);

	for(auto & val : vec)
	{
		cout << val << endl;
	}
	return 0; 
}
