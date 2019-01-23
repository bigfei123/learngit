 ///
 /// @file    test.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-22 18:56:03
 ///

#ifndef _RSS_H__
#define _RSS_H__
#include <vector>
#include <string>
using std::string;
using std::vector;

class RssItem
{
public:
	string title;
	string link;
	string description;
	string content;
};

class RssReader
{
public:
	RssReader();	

	void parseRss(const char*filename); //解析
	void dump(const string & filename);  //输出

private:
	vector<RssItem> _rss;
};

#endif
