 ///
 /// @file    dictonary.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-24 19:35:18
 ///
#include "dictionary.h" 
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::ifstream;
using std::ofstream;
using std::stringstream;

void Dictionary::Read(const string & filename)
{
	ifstream ifs(filename);
	if(!ifs){
		cout << "open file error! " << endl;
		return ;
	}
	string line;
	string word;
	while(getline(ifs, line)){
		stringstream ss(line);
		while(ss >> word) {
			string processword = process(word);
			insert(processword);
		}
	}
	ifs.close();
}

string Dictionary::process(const string & word)
{
	for(size_t idx = 0; idx != word.size(); ++idx)
	{
		if(isalpha(word[idx]))
			return word;
		else
			return string();
	}
}

void Dictionary::insert(const string & word)
{
	if(word != string()){
		++_dic[word]; //词频统计 1.未找到word，添加到新的记录
					  //		 2.已找到word, word匹配的下标+1
		//it = _dic.find(word);
		//if(it == _dic.end())
		//	_dic.insert(std::make_pair(word, 1));
		//it->second++;
	}
}


void Dictionary::Store(const string & filename)
{
	ofstream ofs(filename);
	if(!ofs) {
		cout << "open file error " << endl;
		ofs.close();
		return ;
	}
	for(it = _dic.begin(); it != _dic.end(); ++it){
		ofs << "|" << it->first << "------->" << it->second << "|" << endl; 
	}
	ofs.close();	
}

bool operator<(const auto & lhs, const auto & rhs)
{
	return lhs->first < rhs->second;
}
