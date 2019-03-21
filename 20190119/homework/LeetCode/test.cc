 ///
 /// @file    test.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-25 21:45:07
 ///
#include "LeetCode.h" 
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	LRUCache cache(2);
	cache.put(1, 1);
	cout << "get(1) = " << cache.get(1) << endl;
	cache.put(2, 2);
	cout << "get(2) = " << cache.get(2) << endl;
	cout << "get(1) = " << cache.get(1) << endl;
	cache.put(3, 3);
	cout << "get(1) = " << cache.get(1) << endl;
	cout << "get(2) = " << cache.get(2) << endl;
	cout << "get(3) = " << cache.get(3) << endl;
	cache.put(4, 4);
	cout << "get(1) = " << cache.get(1) << endl;
	cout << "get(2) = " << cache.get(2) << endl;
	cout << "get(3) = " << cache.get(3) << endl;
	cout << "get(4) = " << cache.get(4) << endl;
 
}
