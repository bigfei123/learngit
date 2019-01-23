 ///
 /// @file    test.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-22 08:51:16
 ///
#include <vector>
#include <deque>
#include <list>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::deque;
using std::list;

template <class Container>
void display(const Container & c){
	for(auto & elem : c) {
		cout << elem << " ";
	}
	cout << endl;
}

void test0(){
	vector<int> vec{1, 2, 3, 4, 5};
	vector<int>::const_iterator it = vec.end();
	//vec.insert(it, 6);
	cout << "*it= " <<* (vec.insert(it, 6))<< endl;
	display(vec);
	//int  numbers = vec.back();
	//cout << "numbers = " << numbers << endl;
}
int main(void)
{
	test0();
}
