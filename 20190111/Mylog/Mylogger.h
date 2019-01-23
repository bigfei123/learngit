 ///
 /// @file    Mylogger.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-13 17:53:48
 ///

#ifndef _MYLOGGER_H_
#define _MYLOGGER_H_
#include <log4cpp/Category.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <string>
using std::string;
using namespace log4cpp;
namespace DF
{
class Mylogger
{
public:
	enum Priority {
		ERROR = 300,
		WARN,		//301
		INFO,		//302
		DEBUG		//303
	};

	void warn(const char* msg);
	void error(const char* msg);
	void debug(const char* msg);
	void info(const char* msg);
	static Mylogger * getInstance();
	static void destroy();
	void Set_Priority(Priority p);

private:
	//输出格式
	PatternLayout * patternLayout1;//终端输出格式
	PatternLayout * patternLayout2;//日志文件输出格式
	PatternLayout * patternLayout3;//滚动文件输出格式
	//指定日志输出的目的地
	OstreamAppender * ostreamAppender;//终端输出
	FileAppender * fileAppender;//日志文件输出
	RollingFileAppender * rollingfileAppender;//滚动文件输出

	//日志记录器
	
private:
	Mylogger();
	~Mylogger();
	Category & myCat;
	static Mylogger * _pInstance ;
}; 


#define prefix(msg) string("[")\
	.append(__FILE__).append(":")\
	.append(__FUNCTION__).append(":")\
	.append(std::to_string(__LINE__)).append("]")\
	.append(msg).c_str()
	//用append()方法，避免由于“+”的使用产生过多的中间变量
	//"\"表示宏多行表示在同一行里

#define LogError(msg) Mylogger::getInstance()->error(prefix(msg))
#define LogWarn(msg) Mylogger::getInstance()->warn(prefix(msg))
#define LogInfo(msg) Mylogger::getInstance()->info(prefix(msg))
#define LogDebug(msg) Mylogger::getInstance()->debug(prefix(msg))

}//end of namespace DF
#endif
