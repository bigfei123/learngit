 ///
 /// @file    DoubleList.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-11 12:19:40
 ///


#include "DList.h"
#include <iostream>

using std::cout;
using std::endl;

//节点类构造函数
Node::Node()
{
	cout << "Node()" << endl;
}

//节点类析构函数
Node::~Node()
{
	cout << "~Node() " << endl;
}
  
//链表类构造函数
DList::DList()
: _size(0)
,_head(new Node)
,_tail(_head)
{
	_head->pre = NULL;
	_tail->next =NULL;
	cout << "DList() " << endl;
}
//链表类析构函数
DList::~DList()
{
	Node * p = _tail;
	for(;_size > 0; --_size)
	{
		Node * q= p;
		p = p->pre;
		delete q;//释放q指向的空间
		q = NULL;//防止野指针
		cout << "_size = " << _size <<  endl;
	}	
	p = NULL;
	_head = NULL;
	_tail = NULL;
}
//在尾部添加数据
void DList::Push_back(int value)
{
	if(_size == 0)
		_tail->data = value;
	else{
		Node * p = new Node;
		p->data = value;
		p->pre = _tail;
		p->next = NULL;
		_tail->next = p;
		_tail = p;
    	}
	++_size;
	cout << "Push_back() = " << value << endl;
}

//在头节点添加数据
void DList::Push_front(int value)
{
	if(_size == 0)
		_head->data = value;
	else{
		insert(_head, value);
		_head = _head->pre;
	}
	++_size;
	cout << "Push_front() = " << value << endl;
}

//尾部删除
//让q指向该节点，然后尾节点前移,size减1
void DList::Pop_back()
{
	Node *q = _tail;
	_tail = _tail->pre;
	cout << "Pop_back() = " << q->data << endl;
	erase(q);

	q = NULL;//防止野指针
	--_size;
}

//头部删除
//让q指向当前节点，头指针后移，size减1
void DList::Pop_front()
{
	Node *q = _head;
	_head = _head->next;
	cout << "Pop_front() = " << q->data << endl;
	erase(q);

	q= NULL;//防止野指针
	-- _size;
}

//节点前插入
void DList::insert(Node *node , int value)
{
	Node * p =new Node;
	p->data = value;
	
	p->next = node;
	p->pre = node->pre;
	if(node->pre !=NULL)
		node->pre->next = p;
	node->pre = p;

	p = NULL;
}

//删除节点:
//让p指向当前删除节点，若该节点有后继节点
//则将后继节点连入该节点的前继节点，若该节点有前继节点
//则将前继节点指向该节点的后继节点。
void DList::erase(Node *node)
{
	Node * p = node;
	if(p->next != NULL)
	{
		p->next->pre = p->pre;
	}
	if(p->pre !=NULL)
		p->pre->next = p->next;
	p->pre = NULL;
	p->next = NULL;
	delete p;

	p = NULL;
}

//遍历打印
void DList::display() const
{
	Node *p =_head;
	for(int i = _size;i >0 ; --i,p = p->next)
		cout << p->data << endl;
	p=NULL;
} 


