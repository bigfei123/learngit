 /// @file    TestQuery.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-25 17:13:32
 ///

#ifndef _TESTQUERY_H__
#define _TESTQUERY_H__

#include <map>
#include <set>
#include <vector>
#include <string>
using std::map;
using std::set;
using std::string;
using std::vector;

class TestQuery
{
public:
	void ReadFile(const string & filename);
	void Query(const string & word);

private:
	void preProcessLine(string & line);
	

private:
	vector<string> _file;
	//保存整个输入文件的一份拷贝.输出文件中的每行保存为vector中的一个元素
	//当需要打印一行时，可以用行号作为下标来提取文本。
	map<string, int> _dict;
	map<string, set<int>> _word2Line;
	//set保证了每行只出现一次且行号按升序保存
};


#endif
