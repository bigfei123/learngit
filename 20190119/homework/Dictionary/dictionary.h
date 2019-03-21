 ///
 /// @file    dictionary.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-24 19:23:05
 ///

#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__
#include <string>
#include <map>
#include <iostream>
using std::string;
using std::map;


class Dictionary
{
public:
	//Dictionary(size_t capacity)
	//{
	//	_dic.reserve(capacity);
	//}
	void Read(const string & filename);
	void Store(const string & filename);
	string  process(const string & word);
	void insert(const string & word);

private:
	map<string, int> _dic;
	map<string, int>::iterator it;

};




#endif
