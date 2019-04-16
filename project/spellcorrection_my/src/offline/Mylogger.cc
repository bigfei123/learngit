 ///
 /// @file    Mylogger.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-13 18:17:04
 ///
 
#include "../include/Mylogger.h"
#include <log4cpp/Category.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <iostream>
using std::cout;
using std::endl;

namespace dict
{
Mylogger * Mylogger:: _pInstance = nullptr;

Mylogger * Mylogger::getInstance()
{
	if(nullptr == _pInstance) {
		_pInstance = new Mylogger();
		atexit(destroy);
	}
	return _pInstance;
}

void Mylogger::destroy()
{
	if(_pInstance)
		delete _pInstance;
}


Mylogger::Mylogger()
:myCat(Category::getInstance("myCat"))
{
	patternLayout1 = new PatternLayout();//终端
	patternLayout1 ->setConversionPattern("%d %c [%p] %m%n ");

	patternLayout2 = new PatternLayout();//日志文件
	patternLayout2 ->setConversionPattern("%d %c [%p] %m%n ");

	ostreamAppender = new OstreamAppender("console",&cout);
	ostreamAppender ->setLayout(patternLayout1);
	fileAppender = new FileAppender("fileAppender", "../log/test.log");
	ostreamAppender ->setLayout(patternLayout2);
	
	myCat.addAppender(ostreamAppender);
	myCat.addAppender(fileAppender);
	myCat.setPriority(log4cpp::Priority::DEBUG);
}

Mylogger::~Mylogger()
{
	Category::shutdown();
}

}
