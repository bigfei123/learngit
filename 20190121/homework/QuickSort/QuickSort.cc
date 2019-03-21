 ///
 /// @file    QuickSort.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-26 17:21:51
 ///
 
#include "QuickSort.h"
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main()
{
	QuickSort<int> qs;
	vector<int> vec = {6, 1, 3, 5, 0, 2, 7, 9};
	qs.quicksort(vec, 0, vec.size()-1);
	qs.display(vec);
	return 0;
}
