 ///
 /// @file    mylog.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-06-14 11:00:41
 ///
 
#include "mylog4cpp_class.h"  //对应模块的头文件一定要放在第一个位置

#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>

using namespace log4cpp;

Mylog4cpp * Mylog4cpp::_plog = NULL;

Mylog4cpp * Mylog4cpp::getInstance()
{
	if(NULL ==_plog)
	{
		_plog = new Mylog4cpp;
	}
	return _plog;
}

void Mylog4cpp::destroy()
{
	if(_plog != NULL)
		delete _plog;
}

Mylog4cpp::Mylog4cpp()
: _root(Category::getRoot())
{
	PatternLayout * ptnLy1 = new PatternLayout();
	ptnLy1->setConversionPattern("%d:%p %c %x:%m%n");
	PatternLayout * ptnLy2 = new PatternLayout();
	ptnLy2->setConversionPattern("%d:%p %c %x:%m%n");

	OstreamAppender * osAppender = new OstreamAppender("osAppender", &cout);
	osAppender->setLayout(ptnLy1);
	FileAppender* fileAppender = new FileAppender("fileAppender", "mylog.log");
	fileAppender->setLayout(ptnLy2);

	_root.addAppender(osAppender);
	_root.addAppender(fileAppender);
	_root.setPriority(Priority::DEBUG);
}

void Mylog4cpp::setPriority(priority p)
{
	switch(p)
	{
	case ERROR:
		_root.setPriority(Priority::ERROR);
		break;
	case WARN:
		_root.setPriority(Priority::WARN);
		break;
	case INFO:
		_root.setPriority(Priority::INFO);
		break;
	case DEBUG:
		_root.setPriority(Priority::DEBUG);
		break;
	default:
		_root.setPriority(Priority::DEBUG);
	}
}

void Mylog4cpp::error(const char * msg)
{
	_root.error(msg);
}
void Mylog4cpp::warn(const char * msg)
{
	_root.warn(msg);
}
void Mylog4cpp::info(const char * msg)
{
	_root.info(msg);
}

void Mylog4cpp::debug(const char * msg)
{
	_root.debug(msg);
}

Mylog4cpp::~Mylog4cpp()
{
	//delete _plog;//无限递归调用~Mylog4cpp函数, 不能在这使用
	Category::shutdown();
}
void logError(const char * msg)
{
	Mylog4cpp * _plog = Mylog4cpp::getInstance();
	_plog->error(msg);
}
void logWarn(const char * msg)
{
	Mylog4cpp * _plog = Mylog4cpp::getInstance();
	_plog->warn(msg);
}
void logInfo(const char * msg)
{
	Mylog4cpp * _plog = Mylog4cpp::getInstance();
	_plog->info(msg);
}
void logDebug(const char * msg)
{
	Mylog4cpp * _plog = Mylog4cpp::getInstance();
	_plog->debug(msg);
}
