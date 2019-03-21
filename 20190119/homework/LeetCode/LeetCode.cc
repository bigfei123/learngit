 ///
 /// @file    LeetCode.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-25 20:15:34
 ///
#include "LeetCode.h" 
#include <unordered_map>
#include <list>
#include <iostream>

using std::cout;
using std::endl;
using std::unordered_map;
using std::list;

LRUCache::LRUCache(size_t capacity)
: _capacity(capacity) 
{}

int	LRUCache::get(int key)
{
	//获取该节点迭代器，若存在移动节点到链头，并返回value
	//					若不存在，返回-1
	auto it = _cache.find(key);
	if(it == _cache.end())
		return -1;
	else {
		_nodes.splice(_nodes.begin(), _nodes, it->second);
		return it->second->value;
	}
}

void LRUCache::put(int key, int value) {
	//key本身存在->1.更新新的value
	//			   2.将此节点移动到链头(splice)
	unordered_map<int, list<CacheNode>::iterator>::iterator it;
	
	if((it = _cache.find(key)) != _cache.end()){
		it->second->value = value;
		_nodes.splice(_nodes.begin(), _nodes, it->second);
		//在链表_nodes中，将当前迭代器位置移动到链表头处
	}else{
	//key不存在->1.弹出链尾节点,删除该节点在map中的记录
	//			 2.将(key,value)插入list中
	//			 3.将该节点记录在map中
		if(_nodes.size() == _capacity){
			auto & deleteNode = _nodes.back();
			_cache.erase(deleteNode.key);
			_nodes.pop_back();
		}
		_nodes.push_front(CacheNode(key, value));
		_cache.insert(std::make_pair(key, _nodes.begin()));
	}
}
	
