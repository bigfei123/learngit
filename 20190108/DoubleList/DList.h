 ///
 /// @file    DoubleList.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-11 12:19:58
 ///
#ifndef _DLIST_H_ 
#define _DLIST_H_

#include <iostream>
using std::cout;
using std::endl;

class Node
{
public:
	Node();
	~Node();
public:
	int data;
	Node *pre;
	Node *next;
};

class DList
{
public:
	DList();

	~DList();

	void Push_back(int value);  // 在尾部添加数据

	void Push_front(int value); // 在头部添加数据

	void Pop_back();			// 在尾部删除一个数据

	void Pop_front();			// 在头部删除一个数据

	void insert(Node *node,int value); // 在某个节点之前添加数据

	void erase(Node *node);			// 删除一个指定的节点

	void display() const;		// 打印链表

private:
	Node *_head;
	Node *_tail;
	int _size;
};

#endif
