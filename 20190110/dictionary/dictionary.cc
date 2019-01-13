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
	string str;

	if(!ifs)
	{
		cout << "open readfile failed" << endl;
		return ;
	}

	//逐行读取，将行读入字符串str
	while(getline(ifs,str))
	{
		//字符串str给ss赋值一行
		stringstream ss(str);
		string word;
		//在ss的输入流中，逐词输入到word中
		while(ss >> word)
		{
			vector<Record>::iterator it;
			//对于读入的每一个单词，逐个与容器中的单词进行比较，相等freq加一，跳出for循环
			for(it = vec.begin(); it != vec.end(); ++it)
			{
				if(word == (*it).word)
				{
					(*it).freq +=1;
					break;
				}
			}
			//如果比较到最后发现没有相同的单词，则添加到容器中并使freq加一
			if(it == vec.end())
			{ Record newRe;
				newRe.word = word;
				newRe.freq =1;
				vec.push_back(newRe);
			}
		}
	}
	ifs.close();
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

