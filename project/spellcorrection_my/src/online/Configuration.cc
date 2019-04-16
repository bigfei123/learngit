 ///
 /// @file    Configuration.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-23 12:15:09
 ///
 
#include "../../include/online/Configuration.h"
#include "../../include/online/Mylogger.h"
#include <stdlib.h>
#include <boost/algorithm/string.hpp>
#include <vector>
#include <fstream>
#include <iostream>
using std::cout;
using std::endl;
 
namespace online
{

Configuration * Configuration::_pInstance;

Configuration::Configuration(const string & file)
{
	init(file);
}

Configuration * Configuration::getInstance(const string & file)
{
	if(!_pInstance) {
		_pInstance = new Configuration(file);
		atexit(destory);
	}

	return _pInstance;
}

void Configuration::init(const string & file)
{
	std::ifstream input(file);
	if(!input) {
		LogError("Open config file \"%s\" failed", file.c_str());
		exit(EXIT_FAILURE);
	}else {
		LogInfo("Open config file \"%s\" success", file.c_str());
	}

	std::string line;
	std::vector<string> vec;
	while(getline(input, line)){
		boost::split(vec, line, boost::is_any_of(" \t,:"), boost::token_compress_on);
		_conf.emplace(vec[0], vec[1]);
	}

	input.close();
}

void Configuration::destory()
{
	if(_pInstance){
		delete _pInstance;
	}
}


}//end of namespace online
