 ///
 /// @file    dictionary.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-04 15:43:38
 ///
 
#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include <string>
#include <vector>
using std::string;
using std::vector;

struct Record
{
	string word;
	int freq;
};

class Dictionary
{
public:
	Dictionary(size_t capacity)
	{
		vec.reserve(capacity);
	}	

	void read(const string & filename);
	void store(const string & filename);
	string preprocess(const string & word);
	void insert(const string & word);
	void addNew(const string & word);

private:
	vector<Record> vec;
	vector<Record>::iterator it;
};


#endif
