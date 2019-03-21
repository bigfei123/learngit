 ///
 /// @file    Iteratively.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-10 20:22:47
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
	vector<int> PrintListReversingly_Iteratively(ListNode * pHead)
	{
		ListNode * node = pHead;
		stack<int> st;
		int count = 0;
		while(node) {
			st.push(node->_data);
			count++;
			node = node->_next;
		}

		vector<int> vec(count);
		for(int i = 0; i < count && !st.empty(); ++i)
		{
			cout << st.top() << " in vector" << endl;
			vec[i] = st.top();
			st.pop();
		}
		return vec;
	}
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
	vector<int> vec = solu.PrintListReversingly_Iteratively(list);
	cout << "there are " << vec.size() << " datas in vector" << endl;
	for(size_t i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << " ";
	}
	cout << endl;

	return 0;
}
