 ///
 /// @file    Bubble_sort.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-18 13:48:06
 ///
 
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::istringstream;
 
//时间复杂度O(N^2)
//空间复杂度O(1)

void swap(int &a, int &b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}

void Bubble_Sort(vector<int> & vec)
//应该传vector的引用，否则会进行值复制
{
	for(size_t i = 0; i < vec.size()-1; ++i)
	{
		for(size_t j = 0; j < vec.size()-i-1; ++j)
		{
			if(vec[j] > vec[j+1])
			{
				swap(vec[j], vec[j+1]);
			}
		}
	}
}

int main()
{
	vector<int> vec;

	int number = 0;
	string line;
	getline(cin, line);
	istringstream temp(line);
	while(temp >> number) {
		vec.push_back(number);
	}

	Bubble_Sort(vec);
	for(auto & idx : vec) {
		cout << idx << endl;
	}
}


