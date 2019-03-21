 ///
 /// @file    Dlist.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-03 21:11:01
 ///
 
#ifndef __DLIST_H__
#define __DLIST_H__

struct Node
{
	Node();
	~Node();

	int data;
	Node *pre;
	Node *next;
};

class Dlist
{
public:
	Dlist();
	~Dlist();

	void Push_back(int value);
	void Push_front(int value);
	void Pop_back();
	void Pop_front();
	void insert(Node *node, int value);
	void erase(Node *node);
	void display() ;
	Node*getPtr();
private:
	Node * _head;
	Node * _tail;
	int _size;
};


#endif
