 ///
 /// @file    Queue.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-03 15:22:29
 ///
 
class Queue
{
public:
	Queue();
	~Queue();
	void Push(int);
	void Pop();
	int front();
	int back();
	bool empty();
	bool full();

private:
	int * _data;
	int _front;
	int _rear;
	int _size;
};
