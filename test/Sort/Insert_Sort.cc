 ///
 /// @file    Insert_Sort.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-18 15:55:43
 ///
 
/* 插入排序：
 * 时间复杂度O(N^2), 空间复杂度O(1)
 * 通过扫面前面已排序的子列表，将位置i处的元素定位到从0到i
 * 的子列表之内的正确的位置上
*/

#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
 
void Insert_Sort(vector<int> & vec, const int & length)
{
	for(int i = 1; i < length; ++i) {
		for(int j = 0; j < i; ++j) {
			if(vec[j] > vec[i]) {
				int tmp = vec[i];
				//将tmp插入到子列表之中,for循环移位，空出j所在的位置
				for(int k = 0; k < i-j; ++k) {
					vec[i-k] = vec[i-k-1];
				}
				vec[j] = tmp;
				break;
			}
		}
	}
}


int main()
{
	vector<int> vec = {2, 6, 3, 7, 5, 8, 1};
	int length = vec.size();

	Insert_Sort(vec, length);
	for(auto & idx : vec) {
		cout << idx << endl;
	}
}


