 ///
 /// @file    dictionary.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-08 15:18:19
 ///
 
#include "dictionary.h"
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::ifstream;
using std::ofstream;
using std::stringstream;
 
void Dictionary::read(const string & filename)
{
	ifstream ifs(filename);
	if(!ifs) {
		cout << "the file open error";
		return ;
	}else {
		string line;
		while(getline(ifs, line)) {
			stringstream ss(line);
			string word;
			while(ss >> word){
				string processWord = preprocess(word);
				insert(processWord);
			}
		}
	}
	ifs.close();
}

void Dictionary::store(const string & filename)
{
	ofstream ofs(filename);
	if(!ofs) {
		cout << "the file open error";
		ofs.close();
		return ;
	}
	for(it = _dic.begin(); it != _dic.end(); ++it) {
		ofs << "|" << it->first << "----->" << it->second << "|" << endl;
	}
	ofs.close();
}

string Dictionary::preprocess(const string & word)
{
	for(size_t idx = 0; idx != word.size(); ++idx) {
		if(isalpha(word[idx]))
			return word;
		else 
			return string();
	}
}

void Dictionary::insert(const string & word)
{
	if(word != string()) {
		++_dic[word]; //词频统计 1.未找到word，添加新的记录
					  //		 2.已找到word，word匹配的下标+1
	}
}


