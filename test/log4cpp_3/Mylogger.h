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

	template <class... Args>
	void warn(const char* msg,Args...args)
	{
		myCat.warn(msg, args...);
	}
	template <class... Args>
	void error(const char* msg,Args...args)
	{
		myCat.error(msg, args...);
	}
	template <class... Args>
	void debug(const char* msg,Args...args)
	{
		myCat.debug(msg, args...);
	}
	template <class... Args>
	void info(const char* msg,Args...args)
	{
		myCat.info(msg, args...);
	}
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

//__VA_ARGS__的作用定义参数列表的最后一个参数为省略号
//##__VA_ARGS__宏前面加上##的作用在于，当可变参数的个数为0时这里的##起到把前面多余的“,”去掉的作用
#define LogError(msg, ...) Mylogger::getInstance()->error(prefix(msg), ##__VA_ARGS__)
#define LogWarn(msg, ...) Mylogger::getInstance()->warn(prefix(msg),##__VA_ARGS__)
#define LogInfo(msg, ...) Mylogger::getInstance()->info(prefix(msg),##__VA_ARGS__)
#define LogDebug(msg, ...) Mylogger::getInstance()->debug(prefix(msg),##__VA_ARGS__)
}//end of namespace DF
#endif
