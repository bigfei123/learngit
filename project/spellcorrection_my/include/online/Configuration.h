 ///
 /// @file    Configuration.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-23 12:10:36
 ///
 
#ifndef __ONLINE_CONFIGRURATION_H__
#define __ONLINE_CONFIGRURATION_H__

#include <map>
#include <unordered_map>

using namespace std;

namespace online
{

class Configuration
{
public:
	static Configuration * getInstance(const string & file);
	string getConfig(const string & word)const 
	{
		auto cit = _conf.find(word);
		if(cit == _conf.end()) {
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

}//end of namespace std;

#endif
