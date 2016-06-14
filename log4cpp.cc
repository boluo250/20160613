 ///
 /// @file    log4cpp.cc
 /// @author  boluo(169180920@qq.com)
 /// @date    2016-06-13 20:29:42
 ///
 
#include <iostream>
#include <string>
//log4cpp需要的头文件
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/Priority.hh>

using namespace std;
using namespace log4cpp;

int main()
{
	//指定日志输出信息
	Appender *osAppender = new OstreamAppender("osAppender",&cout);//控制台
	Appender *fileAppender = new FileAppender("fileAppender","file.log");//file
	Appender *rollfileAppender = new RollingFileAppender("rollfileAppender",//rollfile格式
														 "rollfile.log",
														 2 * 1024,
														 3);
	//格式化日志信息（输出的格式）	
	PatternLayout *osLayout = new PatternLayout();
	PatternLayout *fileLayout = new PatternLayout();
	PatternLayout *rollfileLayout = new PatternLayout();
	//%d日期 %p优先级 %c Category  %x NDC %m message %n 换行
	osLayout->setConversionPattern("%d: %p %c %x: %m%n");
	fileLayout->setConversionPattern("%d: %p %c %x: %m%n");
	rollfileLayout->setConversionPattern("%d: %p %c %x: %m%n");

	osAppender->setLayout(osLayout);
	fileAppender->setLayout(fileLayout);
	rollfileAppender->setLayout(rollfileLayout);

	//日志输出
	Category &root = Category::getRoot();
	Category &sub1 = root.getInstance("sub1");//子类

	root.addAppender(fileAppender);
	root.addAppender(rollfileAppender);
	root.setPriority(Priority::WARN);

	sub1.addAppender(osAppender);
	sub1.setPriority(Priority::WARN);//优先级为WARN,小于WARN的不能输出


	string strError;
	for(int i = 0; i != 100; i++)
	{
		ostringstream oss;
		oss << i << ":Root Error Message!";
		strError = oss.str();
		root.error(strError);
	}
	sub1.error("system error");
	sub1.warn("system warn");
	sub1.info("system info");

	Category::shutdown();   //关闭Category

	return 0;
}
