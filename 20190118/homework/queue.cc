 ///
 /// @file    queue.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-20 19:00:35
 ///

#ifndef _QUEUE_H__
#define _QUEUE_H__
#include <iostream>
using std::cout;
using std::endl;

template <class T, size_t kSize = 10>
class Queue
{
public:
	Queue();

	~Queue();

	bool full() const;
	bool empty() const;
	void push_back(const T & t);
	void push_front(const T & t);
	void pop_front();
	void pop_back();
	T top();

private:
	T * _data;
	int _front;
	int _rear;
};
template <class T, size_t kSize>
Queue<T, kSize>::Queue()
: _data(new T[kSize]())
, _front(0)
, _rear(0)
{cout << "Queue()" << endl;}

template <class T, size_t kSize>
Queue<T, kSize>::~Queue()
{	
	delete [] _data;
	cout << "~Queue()" << endl;	
}


template <class T, size_t kSize>
bool Queue<T, kSize>::full() const
{
	if((_rear + 1) % kSize == _front)
		return true;
	return false;
}

template <class T, size_t kSize>
bool Queue<T, kSize>::empty() const
{
	if(_rear == _front)
		return true;
	return false;
}

template <class T, size_t kSize>
void Queue<T, kSize>::push_back(const T & t) 
{
	if(!full()){
		_data[_rear++] = t;
	}
	else {
		cout << "queue is full" << endl;
	}
}

template <class T, size_t kSize>
void Queue<T, kSize>::pop_front()
{
	if(!empty()) {
		++_front;
	}
	else {
		cout << "queue is empty" << endl;
	}
}

template <class T, size_t kSize>
void Queue<T, kSize>::pop_back()
{
	if(!empty()) {
		--_rear;
	}
	else {
		cout << "queue is empty" << endl;
	}
}

template <class T, size_t kSize>
T Queue<T, kSize>::top()
{
	return _data[_rear-1];
}


int main(void)
{
	Queue<int, 10> queue;
	cout << "is empty?  " << queue.empty() << endl;
	for(int number = 1; number != 10; ++number) {
		queue.push_back(number);
	}
	queue.pop_front();
	queue.pop_front();
	while(!queue.empty()){
		cout << queue.top() << endl;
		queue.pop_back();
	}
}
#endif
