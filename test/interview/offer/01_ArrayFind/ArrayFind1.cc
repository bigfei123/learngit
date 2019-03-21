 ///
 /// @file    ArrayFind.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-07 19:36:15
 ///
 
//暴力解法,两层大循环
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
 
class Solution
{
public:
	bool Find(vector<vector<int>> array, int target)
	{
		bool isFound = false;

		for(size_t i = 0; i < array.size(); ++i)
		{
			for(size_t j = 0;j < array[i].size(); ++j)
			{
				if(false == isFound && target == array[i][j])
					isFound = true;
			}
		}
		return isFound;
	}
};

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

	Solution solu;
	cout << solu.Find(array, 7) << endl;
	return 0;
}
