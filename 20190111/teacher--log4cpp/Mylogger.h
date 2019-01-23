 ///
 /// @file    Mylogger.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-01-14 14:37:27
 ///
 
#ifndef __WD_MYLOGGER_H__
#define __WD_MYLOGGER_H__

#include <log4cpp/Category.hh>

#include <string>
using std::string;

namespace wd
{

class Mylogger
{
public:
	enum Priority {
		ERROR = 300,
		WARN,
		INFO,
		DEBUG
	};

	static Mylogger * getInstance();

	static void destroy();

	void warn(const char * msg);
	void error(const char * msg);
	void info(const char * msg);
	void debug(const char * msg);

	void setPriority(Priority p);
private:
	Mylogger();
	~Mylogger();
private:
	log4cpp::Category & _mycat;

	static Mylogger * _pInstance;
};

#define prefix(msg) string("[")\
	.append(__FILE__).append(":")\
	.append(__FUNCTION__).append(":")\
	.append(std::to_string(__LINE__)).append("] ")\
	.append(msg).c_str()

#define LogError(msg) Mylogger::getInstance()->error(prefix(msg))
#define LogWarn(msg) Mylogger::getInstance()->warn(prefix(msg))
#define LogInfo(msg) Mylogger::getInstance()->info(prefix(msg))
#define LogDebug(msg) Mylogger::getInstance()->debug(prefix(msg))

}//end of namespace wd

#endif
