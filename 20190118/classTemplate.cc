 ///
 /// @file    classTemplate.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-19 20:43:25
 ///
#include <string> 
#include <iostream>
using std::cout;
using std::endl;
using std::string;

template <class T, size_t kSize = 10>
class Stack
{
public:
	Stack()
	: _top(-1)
	, _data(new T[kSize]())
	{}

	~Stack();

	bool full();
	bool empty();
	void push(const T & t);
	void pop();
	T top();

private:
	int _top;
	T* _data; 
};

template <class T,size_t kSize>
Stack<T, kSize>::~Stack()
{
	delete [] _data;
	cout << "~Stack()" << endl;
}

template <class T, size_t kSize>
bool Stack<T, kSize>::full()
{
	return _top == (kSize - 1);
}

template <class T, size_t kSize>
bool Stack<T, kSize>::empty()
{
	return _top == -1;
}

template <class T, size_t kSize>
void Stack<T, kSize>::push(const T & t)
{
	_data[++_top] = t;
}

template <class T, size_t kSize>
void Stack<T, kSize>::pop()
{
	_top --;
}

template <class T  , size_t kSize>
T Stack<T, kSize>::top()
{
	return _data[_top];
}

void test0()
{
	Stack<int , 10> st;
	cout << " is full? " << st.full() << endl;
	cout << " is empty? " << st.empty() << endl;
	st.push(1);
	cout << " is empty? " << st.empty() << endl;
	for(int number = 3; number != 12; ++number) {
		st.push(number);
	}
	cout << "is full? " << st.full() << endl;

	while(!st.empty())
	{
		cout << st.top() << endl;
		st.pop();
	}
	cout << "is empty?" << st.empty() << endl;
}

void test1()
{
	Stack<string, 10> st;
	cout << " is full? " << st.full() << endl;
	string alpha = "aa";
	st.push(alpha);
	cout << "is empty?" << st.empty() << endl;

	for(int number = 1; number != 10; ++number) {
		st.push(string(2, 'a'+ number));
	}

	cout << "is empty?" << st.full() << endl;

	while(!st.empty())
	{
		cout << st.top() << endl;
		st.pop();
	}

	cout << "is empty? " << st.empty() << endl;
	return; 
}

int main()
{
	//test0();
	test1();
	return 0;
}
