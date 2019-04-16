 ///
 /// @file    Configuration.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-20 20:17:38
 ///
 
#ifndef __DICT_CONFIGURATION_H__
#define __DICT_CONFIGURATION_H__

#include <unordered_map>
#include <string>
using namespace std;

namespace dict
{

//配置文件类，单例对象
class Configuration
{
public:
	static Configuration * getInstance();
	string getConfig(const string & word) const
	{
		auto cit = _conf.find(word);
		if(cit == _conf.end()){
			return string();
		}
		return cit->second;
	}

private:
	Configuration(const string &);
	void init(const string &);
	static void destory();

private:
	unordered_map<string, string> _conf;
	static Configuration * _pInstance;
};

#define getConfig(s) Configuration::getInstance()->getConfig(s)

}//end of namespace dict

#endif
