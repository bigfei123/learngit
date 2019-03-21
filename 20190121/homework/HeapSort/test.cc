 ///
 /// @file    test.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-26 16:40:18
 ///

#include "HeapSort.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using std::cout;
using std::endl;
using std::vector;
 
int main(void)
{
	vector<int> arr;
	for(int i=10; i<20; ++i)
	{
		arr.push_back(i);
	}

	random_shuffle(arr.begin(), arr.end());  //洗牌打乱顺序
	HeapSort<int> heap(arr);
	heap.Sort(std::less<int>());
	heap.PrintArray(arr);
	heap.Sort(std::greater<int>());
	heap.PrintArray(arr);
	return 0;
 
}
