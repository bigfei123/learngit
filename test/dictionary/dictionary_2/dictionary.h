 ///
 /// @file    dictionary.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-04 15:43:38
 ///
 
#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include <string>
#include <map>

using std::string;
using std::map;

//dictionary之map实现

class Dictionary
{
public:

	void read(const string & filename);
	void store(const string & filename);
	string preprocess(const string & word);
	void insert(const string & word);

private:
	map<string, int> _dic;
	map<string, int>::iterator it;
};


#endif
