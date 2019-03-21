 ///
 /// @file    Mylogger.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-13 18:17:04
 ///
 
#include "Mylogger.h"
#include <log4cpp/Category.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <iostream>
using std::cout;
using std::endl;
using namespace::log4cpp;
namespace DF
{
Mylogger * Mylogger:: _pInstance = nullptr;

Mylogger * Mylogger::getInstance()
{
	if(nullptr == _pInstance) {
		_pInstance = new Mylogger();
	}
	return _pInstance;
}

void Mylogger::destroy()
{
	if(_pInstance)//如果对象存在则撤销对象
		delete _pInstance;
}


Mylogger::Mylogger()
:myCat(Category::getInstance("myCat"))
{
	patternLayout1 = new PatternLayout();//终端
	patternLayout1 ->setConversionPattern("%d %c [%p] %m%n ");

	patternLayout2 = new PatternLayout();//日志文件
	patternLayout2 ->setConversionPattern("%d %c [%p] %m%n ");

	//patternLayout3 = new PatternLayout();//滚动文件
	//patternLayout3 ->setConversionPattern("%d %c [%p] %m%n "); 

		
	ostreamAppender = new OstreamAppender("console",&cout);
	ostreamAppender ->setLayout(patternLayout1);
	fileAppender = new FileAppender("fileAppender", "DF.log");
	ostreamAppender ->setLayout(patternLayout2);
	
	//rollingfileAppender= new RollingFileAppender("rollingfileAppender"
	//				,"rollingDF.log",5*1024,3);
	//ostreamAppender ->setLayout(patternLayout3);

	myCat.addAppender(ostreamAppender);
	myCat.addAppender(fileAppender);
	myCat.setPriority(log4cpp::Priority::DEBUG);
	//myCat.addAppender(rollingfileAppender);
	
	cout << "Mylogger() " << endl;
}

Mylogger::~Mylogger()
{
	cout << "~Mylogger()" << endl;
	Category::shutdown();
}

void Mylogger::Set_Priority(Priority p)
{
	switch(p)
	{
		case WARN:
			myCat.setPriority(Priority::WARN);
			break;
		case ERROR:
			myCat.setPriority(Priority::ERROR);
			break;
		case INFO:
			myCat.setPriority(Priority::INFO);
			break;
		case DEBUG:
			myCat.setPriority(Priority::DEBUG);
			break;
	}
}

//void Mylogger::warn(const char * msg)
//{
//	myCat.warn(msg);
//}
//
//void Mylogger::error(const char * msg)
//{
//	myCat.error(msg);
//}
//
//void Mylogger::debug(const char * msg)
//{
//	myCat.debug(msg);
//}
//
//void Mylogger::info(const char * msg)
//{
//	myCat.info(msg);
//}

}//end of namespace DF
