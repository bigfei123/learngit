 ///
 /// @file    Dlist.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-03 21:15:00
 ///
 
#include "Dlist.h"
#include <iostream>

using std::cout;
using std::endl;

Node::Node()
{	cout << "Node()" << endl;	}

Node::~Node()
{
	cout << "~Node() " << endl;
}

Dlist::Dlist()
: _head(new Node)
, _tail(_head)
, _size(0)
{
	_head->pre = nullptr;
	_tail->next = nullptr;
	cout << "Dlist()" << endl;
}

Dlist::~Dlist()
{
	Node * p = _tail;
	cout << "Size = " << _size << endl;
	while(_size) {
		Node * q = p;
		p = p->pre;
		delete q ;
		q = nullptr;
		--_size;
		cout << "Size = " << _size << endl;
	}
	p = nullptr;
	_head = nullptr;
	_tail = nullptr;
	cout << "~Dlist()" << endl;
}

void Dlist::Push_back(int val)
{
	if(_size == 0)
		_tail->data = val;
	else {
		Node * p = new Node;
		p->data = val;
		p->pre = _tail;
		p->next = nullptr;
		_tail->next = p;
		_tail = p;
	}
	++_size;
	cout << "Push_back(int)" << endl;
}

void Dlist::Push_front(int val)
{
	if(_size == 0)
		_head->data = val;
	else {
		Node * p = new Node;
		p->data = val;
		p->next = _head;
		p->pre = nullptr;
		_head->pre = p;
		_head = p;
	}
	++_size;
	cout << "Push_front(int)" << endl;
}

void Dlist::Pop_back()
{
	Node * p = _tail;
	_tail = _tail->pre;
	delete p;
	p = nullptr;
	--_size;
	cout << "Pop_back()" << endl;
}

void Dlist::Pop_front()
{
	Node * p = _head;
	_head = _head->next;
	delete p;
	--_size;
	cout << "Pop_front()" << endl;
}

void Dlist::insert(Node *node, int val)
{
	if(node == _head) {
		Push_front(val);
	}else {
		Node * p = new Node;
		node->pre->next = p;
		p->pre = node->pre;
		p->next = node;
		node->pre = p;
		p->data = val;
		++_size;
	}
	cout << "insert(Node*, int)" << endl;
}

void Dlist::erase(Node *node)
{
	if(node == _tail) {
		Pop_back();
	}else if(node == _head){
		Pop_front();
	}
	else {
		node->pre->next = node->next;
		node->next->pre = node->pre;
		delete node;
		--_size;
		cout << "erase(Node*)" << endl;
	}
}

Node* Dlist::getPtr()
{
	Node * p = _head->next;
	return p;
}

void Dlist::display() 
{
	Node * p = _head;
	int idx = _size;
	while(idx){
		cout << p->data << endl;;
		p = p->next;
		idx--;
	}
	p = nullptr;
}



