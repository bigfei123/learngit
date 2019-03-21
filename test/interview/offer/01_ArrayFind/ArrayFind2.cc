 ///
 /// @file    ArrayFind.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-07 19:36:15
 ///
 
//分治解法：从右上角开始
//如果查找的元素比当前位置元素小，就向左走
//如果查找的元素比当前位置元素大，就向下走
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
		bool res = false;
		int row = array.size();
		int col = array[0].size();
		
		for(	int i = 0, j = col - 1;
				(i >= 0 && i < row) && (j >= 0 && j < col);
			)
		{
			if(target == array[i][j]) {
				res = true;
				break;
			}else if(target < array[i][j]) {
				cout << target << " < " << array[i][j] << " turn left" << endl;
				j--;
			}else {
				cout << target << " > " << array[i][j] << " turn down" << endl;
				i++;
			}
		}
		return res;
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
