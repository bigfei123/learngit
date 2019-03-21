 ///
 /// @file    TextQuery.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-01 22:52:21
 ///
 
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <memory>
#include <fstream>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::map;
using std::set;
using std::shared_ptr;
using std::istringstream;
using LineNo = vector<string>::size_type;
 
class QueryResult;
class TestQuery
{
public:
	TestQuery(ifstream&);
	QueryResult query(const string&) const;
private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<LineNo>>> wm;
};

TestQuery::TestQuery(ifstream& ifs)
: file(new vector<string>)
{
	string text;
	while(getline(ifs, text)){
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while(line >> word){
			auto & lines = wm[word];
			if(!lines)
				lines.reset(new set<LineNo>);
			lines->insert(n);
		}
	}
}

class QueryResult
{
public:
	QueryResult(string s,
				shared_ptr<set<LineNo>> p,
				shared_ptr<vector<string>> f)
		:sought(s), lines(p), file(f) {}
public:
friend std::ostream & print(std::ostream&, const QueryResult&);
private:
	string sought; //查询单词
	shared_ptr<set<LineNo>> lines;  //出现的行号
	shared_ptr<vector<string>> file;//输入文件
};

QueryResult TestQuery::query(const string & sought) const
{
	static shared_ptr<set<LineNo>> nodata(new set<LineNo>);
	auto loc = wm.find(sought);
	if(loc == wm.end())
		return QueryResult(sought, nodata, file); //未找到
	else
		return QueryResult(sought, loc->second, file);
}

std::ostream & print(std::ostream & os, const QueryResult & qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " "
	   << (qr.lines->size() > 0 ?  "times": "time") << endl;

	for(auto num : *qr.lines) //对set中每个单词
		os << "\t(line" << num + 1 << ")"
		   << *(qr.file->begin() + num) << endl;
	return os;
}


