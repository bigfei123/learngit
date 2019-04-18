 ///
 /// @file    018.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-04-17 15:42:32
 ///
 
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
 
void display(vector<vector<int>> & vec)
{
	for(size_t i = 0; i < vec.size(); ++i){
		for(size_t j = 0; j < vec[0].size(); ++j) {
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void fun(vector<vector<int>> & vec)
{
	int temp = 0;
	for(size_t i = 0; i < vec.size(); ++i){
		for(size_t j = 0; j < vec[0].size(); ++j) {
			temp = vec[i][j];
			vec[i][j] = vec[j][i];
			vec[j][i] = temp;
		}
	}
}

int main(void)
{
	int a1[] = {100, 200, 300};
	int a2[] = {400, 500, 600};
	int a3[] = {700, 800, 900};

	vector<vector<int>> array;
	array.push_back(vector<int>(a1, a1 + 3));
	array.push_back(vector<int>(a2, a2 + 3));
	array.push_back(vector<int>(a3, a3 + 3));

	display(array);
	fun(array);
	display(array);
	return 0;
}
