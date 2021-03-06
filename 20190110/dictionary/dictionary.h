 ///
 /// @file    dictionary.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-12 16:12:39
 ///
#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::stringstream;

class Record
{
public:
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
