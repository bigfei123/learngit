 ///
 /// @file    ostream_iterator.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-24 16:52:10
 ///

#include <iterator>
#include <vector>
#include <algorithm>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::copy;
using std::ostream_iterator;
 
int main(void)
{
	vector<int> numbers{1, 2, 3, 4, 5, 6};

	ostream_iterator<int> osi(cout, " ");
	cout << endl;
	copy(numbers.begin(), numbers.end(), osi);

	return 0;
}
