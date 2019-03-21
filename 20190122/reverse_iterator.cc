 ///
 /// @file    reverse_iterator.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-24 17:05:24
 ///
#include <vector> 
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
 
int main(void)
{
	vector<int> numbers{1, 2, 3, 4, 5};
	vector<int>::reverse_iterator rit = numbers.rbegin();
	while(rit != numbers.rend()) {
		cout << *rit<< " ";
		++rit;
	}
	cout << endl;
	return 0; 
}
