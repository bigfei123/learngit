 ///
 /// @file    dictionary.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-12 15:02:06
 ///
#include "dictionary.h" 
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::stringstream;

void Dictionary::read(const string & filename)
{
	ifstream ifs(filename.c_str());
	string line;
	if(!ifs)
	{
		cout << "open readfile failed" << endl;
		return ;
	}
	//逐行读取，将行读入字符串str
	while(getline(ifs,line))
	{
		//字符串str给ss赋值一行
		stringstream ss(line);
		string word;
		//在ss的输入流中，逐词输入到word中
		while(ss >> word)
		{
			string processedWord = preprocess(word);//判断是否为字母
			insert(processedWord);
			addNew(word);
		}
	}
	ifs.close();
	std::sort(vec.begin(), vec.end());
}



void Dictionary::store(const string & filename)
{
	//从流中写数据
	vector<Record>::iterator it;
	ofstream ofs(filename);
	if(!ofs)
	{
		cout << "open store_file failed" << endl;
	}
	for(it = vec.begin(); it !=vec.end(); ++it)
	{
		ofs <<"|" << (*it).word <<"         " << (*it).freq <<"|" << endl;
	}
	ofs.close();
}

//判断字符串是否为数字，是——输出空串，否——返回word
string Dictionary::preprocess(const string & word)
{
	for(size_t idx = 0; idx!= word.size(); ++idx) {
		if(!isalpha(word[idx])) //判断是否为字母
			return string(); //输出空字符串
		return word;
	}
}

void Dictionary::insert(const string & word)
{
	if(word == string()) {
		return ;
	}

	//对于读入的每一个单词，逐个与容器中的单词进行比较，相等freq加一，跳出for循环
	for(it = vec.begin(); it != vec.end(); ++it)
	{
		if(word == (*it).word)
		{
			(*it).freq +=1;
			break;
		}
	}
}

void Dictionary::addNew(const string &  word)
{
	if(it == vec.end())
	{
		Record newRe;
		newRe.word = word;
		newRe.freq =1;
		vec.push_back(newRe);
	}
}

bool operator<(const Record & lhs, const Record & rhs)
{
	return lhs.word < rhs.word;
}
