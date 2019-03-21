 ///
 /// @file    Recursively.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-10 19:35:16
 ///
 
#include <stack>
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::stack;
 
struct ListNode
{
	int _data;
	ListNode * _next;
};

class Solution
{
public:
	vector<int> PrintListReversingly_Recursively(ListNode * pHead)
	{
		if(pHead) {
			PrintListReversingly_Recursively(pHead->_next);
			vec.push_back(pHead->_data);
		}
		return vec;
	}
private:
	vector<int> vec;
};

int main(void)
{
	ListNode list[4]; 
	list[0]._data = 1;
	list[0]._next = &list[1];
	list[1]._data = 2;
	list[1]._next = &list[2];
	list[2]._data = 3;
	list[2]._next = &list[3];
	list[3]._data = 4;
	list[3]._next = nullptr;

	Solution solu;
	vector<int> res;
	vector<int> vec = solu.PrintListReversingly_Recursively(list);
	cout << "there are " << vec.size() << " datas in vector" << endl;
	for(size_t i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << " ";
	}
	cout << endl;

	return 0;
}
