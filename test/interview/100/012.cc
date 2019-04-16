 ///
 /// @file    012.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-04-15 14:57:48
 ///
 
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
 
void fun(vector<vector<int>> & vec)
{
	float sum = 0;
	for(size_t i = 0; i < vec.size(); ++i) {
		for(size_t j = 0; j < vec[0].size(); ++j) {
			if(i == 0 || i == vec.size()-1) {
				sum += vec[i][j];		
			}
			if(j == 0 || j == vec.size() -1) {
				sum += vec[i][j];
			}
		}
	}
	sum = sum - vec[0][0] - vec[0][vec.size()-1] - vec[vec.size()-1][0] - vec[vec.size()-1][vec.size()-1];
	float avg = sum / (vec.size() * 4 - 4);
	cout << "sum = " << sum << endl;
	cout << "size = " << (vec.size() * 4 - 4) << endl;
	cout << "avg = " << avg << endl;
}

int main(void)
{
	int a1[] = {0, 1, 2, 7, 9 };
	int a2[] = {1, 9, 7, 4, 5 };
	int a3[] = {2, 3, 8, 3, 1 };
	int a4[] = {4, 5, 6, 8, 2 };
	int a5[] = {5, 9, 1, 4, 1 };

	vector<vector<int>> array;
	array.push_back(vector<int>(a1, a1 + 5));
	array.push_back(vector<int>(a2, a2 + 5));
	array.push_back(vector<int>(a3, a3 + 5));
	array.push_back(vector<int>(a4, a4 + 5));
	array.push_back(vector<int>(a5, a5 + 5));

	fun(array);
}
