 ///
 /// @file    Sort2Array.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-08 21:07:24
 ///
 
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;


class Solution
{
public:
	auto Merge(int array1[], const int len1, int array2[], const int len2)
	//void Merge(vector<int> array1, const int len1, vector<int> array2, const int len2)
	{
		//i, j为array1[]，array2数组实际末尾下标，k为array1[]数组中进行归并位置的下标
		int i = len1 - 1;
		int j = len2 - 1;
		int k = len1 + len2 - 1;
		cout << "k = " << k << endl;
		while(i >= 0 && j >= 0) {
			//如果array1[]数组中未处理末尾的数大于或等于array2数组中未处理末尾的数
			//则将array1[]的该位置的数插入到array1[]数组末尾，否则插入array2该位置的数
			if(array1[i] >= array2[j]) {
				array1[k--] = array1[i--];
			}else {
				array1[k--] = array2[j--];
			}
		}
		//如果数组array2中还有元素没有插入到数组array1[]中，则全部一次插入到数组array1[]前面位置
		while(j >= 0) {
			array1[k--] = array2[j--];
		}
	}
};
 
int main(void)
{
	Solution solu;
	int array1[20] = {1, 3, 5, 7, 9};
	int array2[] = {2, 4, 6, 8, 10};

	int len1 = sizeof(array2) / sizeof(array2[0]); //5
	int len2 = sizeof(array2) / sizeof(array2[0]);
	
	//vector<int> array1;
	//array1.reserve(20);
	//array1 = {1, 3, 5, 7, 9};
	//vector<int> array2 = {2, 4, 6, 8, 10};

	//int len1= array1.size();
	//cout << "len1 = " << len1 << endl;
	//int len2= array1.size();

	solu.Merge(array1, len1, array2, len2);
	for(int i = 0; i < 10; ++i) {
		cout << array1[i] << " ";
	}

	//vector<int>::iterator it = array1.begin();
	//while(it != array1.end()) {
	//	cout << *it << " ";
	//	++it;
	//}
	cout << endl;
}
