 ///
 /// @file    log4cpp1.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-12 18:53:43
 ///
#include <log4cpp/Category.hh> 
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <iostream>
using std::cout;
using std::endl;
using namespace log4cpp;
 
void test1()
{
	//控制日志输出格式
	PatternLayout * patternLayout = new PatternLayout();
	patternLayout ->setConversionPattern("%d %c [%p] %m%n ");

	//指定日志输出的目的地
	OstreamAppender *ostreamAppender = new OstreamAppender("console",&cout);
	ostreamAppender->setLayout(patternLayout);
	
	FileAppender * fileAppender = new FileAppender("FileAppender","DF.log");
	
	//日志记录器
	Category & root = Category::getRoot();
	root.setAppender(ostreamAppender);
	root.setPriority(Priority::DEBUG);
	root.setPriority(Priority::ERROR);

	//执行记录日志的操作
	root.emerg("this is an emerg message");
	root.fatal("this is an fatal message");
	root.alert("this is an alert message");
	root.error("this is an error message");
	root.info("this is an info message");
	root.crit("this is an crit message")	;
	root.debug("this is an debug message");
	//回收内存
	Category::shutdown();
	

}
void test2()
{
	//控制日志输出格式
	PatternLayout * patternLayout1 = new PatternLayout();
	patternLayout1 ->setConversionPattern("%d %c [%p] %m%n ");

	PatternLayout * patternLayout2 = new PatternLayout();
	patternLayout2 ->setConversionPattern("%d %c [%p] %m%n ");

	
	//指定日志输出的目的地
	OstreamAppender *ostreamAppender = new OstreamAppender("console",&cout);
	ostreamAppender->setLayout(patternLayout1);
	
	FileAppender * fileAppender = new FileAppender("fileAppender","DF.log");
	ostreamAppender->setLayout(patternLayout2);
	//日志记录器
	Category & myCat= Category::getRoot().getInstance("myCat");
	myCat.addAppender(ostreamAppender);
	myCat.addAppender(fileAppender);
	//myCat.setPriority(Priority::DEBUG);
	myCat.setPriority(Priority::ERROR);//Category的优先级

	//只有当每一条日志的优先级大于Category优先级时，该条日志才会被记录
	//执行日记日志的操作
	myCat.emerg("this is an emerg message");//每一条日志的优先级
	myCat.fatal("this is an fatal message");
	myCat.alert("this is an alert message");
	myCat.error("this is an error message");
	myCat.info("this is an info message");
	myCat.crit("this is an crit message")	;
	myCat.debug("this is an debug message");
	myCat.notice("this is an notice message");
	myCat.warn("this is an warn message");
	//回收内存
	Category::shutdown();
}
//对日志文件进行分割，防止日志文件过大
void test3()
{
	//控制日志输出格式
	PatternLayout * patternLayout1 = new PatternLayout();
	patternLayout1 ->setConversionPattern("%d %c [%p] %m%n ");

	PatternLayout * patternLayout2 = new PatternLayout();
	patternLayout2 ->setConversionPattern("%d %c [%p] %m%n ");

	
	//指定日志输出的目的地
	OstreamAppender *ostreamAppender = new OstreamAppender("console",&cout);
	ostreamAppender->setLayout(patternLayout1);
	
	RollingFileAppender * rollingfileAppender =
		new RollingFileAppender("rollingFileAppender",
				"rollingDF.log",5 * 1024,3);
	ostreamAppender->setLayout(patternLayout2);
	//日志记录器
	Category & myCat= Category::getRoot().getInstance("myCat");
	myCat.addAppender(ostreamAppender);
	myCat.addAppender(rollingfileAppender);
	//myCat.setPriority(Priority::DEBUG);
	myCat.setPriority(Priority::ERROR);//Category的优先级

	//只有当每一条日志的优先级大于Category优先级时，该条日志才会被记录
	//执行日记日志的操作
	for(int idx = 0; idx != 100; ++idx){
		myCat.emerg("this is an emerg message");//每一条日志的优先级
		myCat.fatal("this is an fatal message");
		myCat.alert("this is an alert message");
		myCat.error("this is an error message");
		myCat.info("this is an info message");
		myCat.crit("this is an crit message")	;
		myCat.debug("this is an debug message");
		myCat.notice("this is an notice message");
		myCat.warn("this is an warn message");
	}
	//回收内存
	Category::shutdown();
}
int main(void)
{
	test1();
	//test2();
	//test3();
 
}
