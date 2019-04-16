 ///
 /// @file    011.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-04-15 14:46:41
 ///
 
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
 
void fun(vector<vector<int>> & vec)
{
	for(size_t i = 0; i < vec.size(); ++i) {
		for(size_t j = 0; j <= i; ++j) {
			vec[i][j] = 0;	
		}
	}
}

int main(void)
{
	int a1[] = {1, 2, 8, 9, };
	int a2[] = {2, 4, 9, 12, };
	int a3[] = {4, 7, 10, 13, };
	int a4[] = {6, 8, 11, 15, };

	vector<vector<int>> array;
	array.push_back(vector<int>(a1, a1 + 4));
	array.push_back(vector<int>(a2, a2 + 4));
	array.push_back(vector<int>(a3, a3 + 4));
	array.push_back(vector<int>(a4, a4 + 4));

	for(size_t i = 0; i < array.size(); ++i) {
		for(size_t j = 0; j < array[0].size(); ++j) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

	fun(array);

	for(size_t i = 0; i < array.size(); ++i) {
		for(size_t j = 0; j < array[0].size(); ++j) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
