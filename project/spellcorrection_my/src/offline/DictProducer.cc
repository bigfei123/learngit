 ///
 /// @file    DictProducer.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-20 21:55:01
 ///
 
#include "../include/DictProducer.h"
#include "../include/Mylogger.h"
#include "../include/Configuration.h"

#include <string>
#include <fstream>
#include <sstream>
#include <dirent.h>
#include <sys/types.h>

using namespace std;

namespace dict
{

//不传参创建英文字典
DictProducer::DictProducer()
: _splitTool(nullptr)
{
	_dir = getConfig("enDictionaryDir");
	if(_dir.size() == 0) {
		LogError("No dictionary source file");
		exit(EXIT_FAILURE);
	}
}

//传参创建中文词典
DictProducer::DictProducer(SplitTool * splitTool)
: _splitTool(splitTool)
{
	_dir = getConfig("cnDictionaryDir");
	if(_dir.size() == 0) {
		LogError("No dictionary source file");
		exit(EXIT_FAILURE);
	}
}

void DictProducer::buildDict()
{
	//如果_splitTool为nullptr,则返回中文字典目录
	string stopWordsFile = _splitTool ? getConfig("cnStopWordDict")
		: getConfig("enStopWordsDict");

	//先创建停用词词典，将该目录下所有词典插入_stopWordsDict
	getStopWordDict(stopWordsFile);

	getFiles();			//从指定目录中读取文件并压入_files
	ifstream input;
	string line, word;
	vector<string> words;
	//对于该目录下的所有文件，逐个进行分词，并建立词典
	for(const auto & file : _files) {
		input.open(file);
		if(input) {
			LogInfo("Open dictionary file \"%s\" success", file.c_str());
			while(getline(input, line)) {
				if(!line.size())
					continue;
				//处理中文
				if(_splitTool) {
					_splitTool->cut(words, line);
					for(const auto & e : words) {
						if(_stopWordsDict.find(e) == _stopWordsDict.end())
							_dict[e]++;
					}
				}else {
					strProcess(line);
					istringstream ss(line);
					while(ss >> word) {
						if(_stopWordsDict.find(word) == _stopWordsDict.end())
							_dict[word]++;
					}
				}
			}
		}else{
			LogError("Open dictionary file \"%s\"failed", file.c_str());
		}
		input.close();
	}
	LogInfo("Build dict.dat success");
}

void DictProducer::getFiles() 
{
	DIR * dir = opendir(_dir.c_str());
	if(!dir) {
		LogError("No such dirctory");
	}
	struct dirent * fileInfo;
	string file;

	while((fileInfo = readdir(dir)) != nullptr) {
		if(fileInfo->d_type == DT_REG) { //DT_REG为普通文件
			file = _dir + "/" + fileInfo->d_name;//查找该目录下的文件
			_files.push_back(file);
			LogDebug("add \"%s\" to dictionary files" , file.c_str());
		}
	}
}

void DictProducer::getStopWordDict(const string & file) 
{
	ifstream input(file);
	if(input) {
		LogInfo("Open stopwords dictionary file \"%s\" success", file);
	}else {
		LogWarn("Open stopwords dictionary file \"%s\" failed", file);
		input.close();
		return ;
	}

	string word;
	while(input >> word) {
		//将该目录下所有字典插入到_stopWordsDict
		_stopWordsDict.insert(move(word));
	}
	input.close();
}

void DictProducer::buildIndex()
{
	size_t idx = 0;
	for(const auto & record : _dict) {
		for(auto cit = record.first.cbegin();
				cit != record.first.cend();){
			//*cit为每一个单词的一个字母
			string s;
			int len = getBytesCode(*cit);
			//s是一个utf—8字符,每个字符当作索引
			s = string(cit, cit + len);
			cit = cit + len;

			auto it = _index.find(s);
			if(it == _index.end()) {
				_index.insert(make_pair(move(s), set<size_t>{idx}));
			}else {
				it->second.insert(idx);
			}
		}
		++idx;
	}
	LogInfo("Create index.dat success");
}

void DictProducer::store() const 
{
	string file = _splitTool ? getConfig("cnDictionaryStoreFile")
		: getConfig("enDictionaryStoreFile");
	if(file.size() == 0) {
		LogError("No dictionary store file");
		exit(EXIT_FAILURE);
	}

	ofstream output(file);
	for(const auto & record : _dict){ 
		output << record.first << " "
			   << record.second << '\n';
	}
	output.close();

	file = _splitTool ? getConfig("cnIndexStoreFile") : getConfig("enIndexStoreFile");
	if(file.size() == 0) {
		LogError("No index store file");
		exit(EXIT_FAILURE);
	}

	output.open(file);
	for(const auto & record : _index) {
		output << record.first << ":";
		for(const auto & i : record.second) {
			output << ' ' << i;
		}
		output << '\n';
	}
	output.close();
}

void DictProducer::strProcess(string & str) {
	for(auto & c : str) {
		if(!isalpha(c)) {
			c = ' ';
		}else {
			c = tolower(c);
		}
	}
}

//返回一个utf-8编码字符的字节数
int DictProducer::getBytesCode(char c) {
	if(!(c & 0x80)) {  //若最高位为0,按位与操作后为0，饭后字节数为1
		return 1;
	}
	int cnt = 0;
	 do{ //否则循环左移一位进行按位与操作，判断最高位1的个数
		c <<= 1;
		cnt ++;
	}while(c & 0x80);
	return cnt;
}

}//end of namespace dict

