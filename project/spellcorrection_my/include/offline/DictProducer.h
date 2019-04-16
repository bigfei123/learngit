 ///
 /// @file    DictProducer.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-20 21:47:46
 ///

#ifndef __DICT_DICTPRODUCCER_H__
#define __DICT_DICTPRODUCCER_H__

#include "SplitTool.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

namespace dict
{

class Configuration;

class DictProducer
{
public:
	DictProducer();
	DictProducer(SplitTool * splitTool);
	void buildDict();
	void buildIndex();
	void store() const;

private:
	void getStopWordDict(const string &);
	void getFiles();
	void strProcess(string &);
	int getBytesCode(char);

private:
	string _dir;					//字典源文件目录
	vector<std::string> _files;		//所有字典源文件
	SplitTool * _splitTool;			//分词工具对象指针,英文时为NULL
	unordered_set<string> _stopWordsDict;		//停用词词典
	unordered_map<string, size_t> _dict;		//词典
	unordered_map<string, set<size_t>> _index;  //索引

};

}//end of namespace dict

#endif
