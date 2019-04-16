 ///
 /// @file    Configuration.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-21 19:20:01
 ///
 
#include "../include/Configuration.h"
#include "../include/Mylogger.h"
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <boost/algorithm/string.hpp>
using std::cout;
using std::endl;

namespace dict
{
Configuration * Configuration::_pInstance;

Configuration::Configuration(const string & file)
{
	init(file);
}

Configuration * Configuration::getInstance()
{
	if(!_pInstance) {
		_pInstance = new Configuration("/home/dafei/project/spellcorrection_my/conf/dict.conf");
		atexit(destory);
	}
	return _pInstance;
}

void Configuration::destory() 
{
	if(_pInstance)
		delete _pInstance;
}

void Configuration::init(const string & file)
{
	std::ifstream input(file);

	if(!input) {
		LogError("Open config file \"%s\" failed", file.c_str());
		exit(EXIT_FAILURE);
	}else{
		LogInfo("Open config file \"%s\" success", file.c_str());
	}

	string line;
	vector<string> vec;
	while(getline(input, line)) {
		if(!line.size())
			continue;
		//使用boost库的字符串分割函数
		//is_any_of表示其中任何一个字符都可以作为分隔符(空格或:)
		//token_compress_on表示多个分隔符表示一个，默认没有
		boost::split(vec, line, boost::is_any_of(" \t,:"), boost::token_compress_on);
		//配置文件都是键值对,对应文件代号---->路径
		_conf.emplace(vec[0], vec[1]);
	}

	input.close();
}


}//end of namespace dict
 
