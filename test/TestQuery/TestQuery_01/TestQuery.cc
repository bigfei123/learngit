 ///
 /// @file    TestQuery.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-25 17:18:53
 ///
#include "TestQuery.h" 
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::stringstream;	
using std::map;
 
void TestQuery::ReadFile(const string & filename)
{
	ifstream ifs(filename);
	if(!ifs) {
		cout << "open file error! " << endl;
		ifs.close();
		exit(0);
	}
	string line;
	size_t lineNumber = 0;
	while(getline(ifs, line)){
		_file.push_back(line);
		preProcessLine(line);
		stringstream ss(line);
		string word;
		while(ss >> word){
			++_dict[word];  //词频统计
			_word2Line[word].insert(lineNumber);//容器的嵌套使用
		}
	++lineNumber;
	}
	ifs.close();
}

void TestQuery::Query(const string & word)
{
	int count = _dict[word];
	cout << word << "  occurs " 
		 << count << (count > 1? " times.": " time.") << endl;
		auto lines = _word2Line[word];
		for(auto & number : lines) {		
			cout << "	(line " << number + 1 << ")" 
				 << _file[number] << endl;
		}
}
	
void TestQuery::preProcessLine(string & line)
{
	//非字母的字符全部换成空格
	//for(size_t idx = 0; idx != line.size(); ++idx){
	//
	//}
	for(auto & ch : line){
		if(!isalpha(ch)){
			ch = ' ';
		}else if(isupper(ch)){
			ch = tolower(ch);
		}
	}
}


