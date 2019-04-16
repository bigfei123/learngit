 ///
 /// @file    013.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-04-15 15:33:56
 ///
 
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
 
void fun(vector<vector<int>> & tt, vector<int> & pp)
{
	for(size_t i = 0; i < tt[0].size(); ++i) {
		int min = 1 << 30;
		for(size_t j = 0; j < tt.size(); ++j) {
			if(min > tt[j][i]) {
				min = tt[j][i];
			}
		}
		pp.push_back(min);
	}

	for(auto & elem : pp) {
		cout << elem << " ";
	}
	cout << endl;
}

int main(void)
{
	int a1[] = {0, 1, 2, 7, 9 };
	int a2[] = {1, 9, 7, 4, 5 };
	int a3[] = {2, 3, 8, 3, 1 };
	int a4[] = {4, 5, 6, 8, 2 };
	int a5[] = {5, 9, 1, 4, 1 };
	vector<int> pp;

	vector<vector<int>> array;
	array.push_back(vector<int>(a1, a1 + 5));
	array.push_back(vector<int>(a2, a2 + 5));
	array.push_back(vector<int>(a3, a3 + 5));
	array.push_back(vector<int>(a4, a4 + 5));
	array.push_back(vector<int>(a5, a5 + 5));

	fun(array, pp);
}