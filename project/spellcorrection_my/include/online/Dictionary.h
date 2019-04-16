 ///
 /// @file    Dictionary.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-22 21:46:13
 ///
 
#ifndef __ONLINE_DICTIONARY_H__
#define __ONLINE_DICTIONARY_H__

#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

namespace online
{

class Dictionary
{
public:
	static Dictionary * getInstance();
	vector<pair<string, size_t>> & getDict() { return _dict; }
	unordered_map<string, set<int>> & getIndexTable() { return _indexTable;  }

	void initDict(const string & path);
	void initIndex(const string & path);

public:
	class AutoRelease//嵌套类实现资源自动回收
	{
	public:
		~AutoRelease();
	};

private:
	Dictionary() {}
private:
	vector<pair<string, size_t>> _dict;
	unordered_map<string, set<int>> _indexTable;

	static AutoRelease _ar;
	static Dictionary * _pInstance;

};

}//end of namespace online

#define getDict() Dictionary::getInstance()->getDict()
#define getIndexTable() Dictionary::getInstance()->getIndexTable()

#endif
