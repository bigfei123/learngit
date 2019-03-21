 ///
 /// @file    dictionary.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-04 15:49:01
 ///
 
#include "dictionary.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::stringstream;
 
void Dictionary::read(const string & filename)
{
	ifstream ifs(filename);
	if(!ifs) {
		cout << "the file open error"  << endl;
		ifs.close();
	}
	
	string line;
	while(getline(ifs, line)) {
		stringstream ss(line);
		string word;
		while(ss >> word) {
			string processWord = preprocess(word);
			insert(processWord);
			addNew(word);
		}
	}
	ifs.close();	
	std::sort(vec.begin(), vec.end());
}

void Dictionary::store(const string & filename)
{
	ofstream ofs(filename);
	if(!ofs) {
		cout << "the file open error " << endl;
		ofs.close();
	}
	for(it = vec.begin(); it != vec.end(); ++it) {
		ofs << (*it).word << "-------->" << (*it).freq << endl;
	}
	ofs.close();
}

string Dictionary::preprocess(const string & word)
{
	for(size_t idx = 0; idx != word.size(); ++idx) {
		if(!isalpha(word[idx]))	
			return string();
		return word;
	}
}

void Dictionary::insert(const string & word)
{
	if(word == string()) {
		return ;
	}

	for(it = vec.begin(); it != vec.end(); ++it) {
		if(word == (*it).word) {
			(*it).freq += 1;
			break;
		}
	}
}

void Dictionary::addNew(const string & word)
{
	if(it == vec.end()) {
		Record newRecord;
		newRecord.word = word;
		newRecord.freq = 1;
		vec.push_back(newRecord);
	}
}

bool operator<(const Record & lhs, const Record & rhs)
{
	return lhs.word < rhs.word;
}
