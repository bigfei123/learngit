 ///
 /// @file    LeetCode.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-25 20:10:30
 ///

#ifndef __LEETCODE_H__
#define __LEETCODE_H__
#include <unordered_map>
#include <list>
#include <utility>
using std::unordered_map;
using std::list;


class LRUCache
{
public:
	LRUCache(size_t capacity);

	int get(int key);

	void put(int key, int value);

private:
	struct CacheNode
	{
		CacheNode(int k, int v)
		: key(k)
		, value(v)
		{}

		int key;
		int value;
	};
private:
	size_t _capacity;
	//list容器对象
	list<CacheNode> _nodes;
	//map容器对象
	unordered_map<int, list<CacheNode>::iterator> _cache;
};





#endif
