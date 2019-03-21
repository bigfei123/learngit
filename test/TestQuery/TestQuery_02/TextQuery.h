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
		file->push_back(text);       //保存此行文本
		int n = file->size() - 1;	 //当前行号
		istringstream line(text);    //将文本分解为单词
		string word;
		while(line >> word) {		 //对行中每个单词
			//如果单词不在wm中，以之为下标在wm中添加一项
			auto & lines = wm[word];  //lines 是shared_ptr<set>
			if(!lines) //在我们第一次遇到这个单词时，此指针为空
				lines.reset(new set<LineNo>);//分配一个新的set
			lines->insert(n);		 //将此行号插入set中
		}
	}
}

class QueryResult
{
public:
	QueryResult(string s,					 //保存查询单词
				shared_ptr<set<LineNo>> p,	 //保存单词出现行号的set 
				shared_ptr<vector<string>> f)//保存输入文件的vector
		:sought(s), lines(p), file(f) {}
public:
friend std::ostream & print(std::ostream&, const QueryResult&);
private:
	string sought;					//查询单词
	shared_ptr<set<LineNo>> lines;  //出现的行号
	shared_ptr<vector<string>> file;//输入文件
};

QueryResult TestQuery::query(const string & sought) const
{
	static shared_ptr<set<LineNo>> nodata(new set<LineNo>);
	//当我们没找到时，返回一个局部static对象，它指向空的行号set的shared_ptr
	auto loc = wm.find(sought);
	//使用find而不是下标运算符，避免将单词添加到wm中
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


