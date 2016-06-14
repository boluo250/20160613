 ///
 /// @file    mylog.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-06-14 10:52:50
 ///
 
#ifndef __MYLOG4CPP_CLASS_H__
#define __MYLOG4CPP_CLASS_H__

#include <log4cpp/Category.hh>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Mylog4cpp
{
public:
	enum priority
	{// 自定义的优先级，用来设置Category的优先级
		ERROR, WARN, INFO, DEBUG
	};
public:
	static Mylog4cpp * getInstance();
	static void destroy();

	void error(const char * msg);
	void warn(const char * msg);
	void info(const char * msg);
	void debug(const char * msg);

	void setPriority(priority p);

private:
	Mylog4cpp();
	~Mylog4cpp();

private:
	static Mylog4cpp * _plog;
	log4cpp::Category & _root;
};

//将整型数据转换成字符串
inline string int2str(int idx)
{
	std::ostringstream oss;
	oss << idx;
	return oss.str();
}

//带参数的宏定义，为日志信息添加后缀
#define postfix(msg) \
		string(msg).append("{").append(__FILE__).\
					   append(":").append(__func__).\
		               append(":").append(int2str(__LINE__)).\
					   append("}").c_str()


void logError(const char * msg);
void logWarn(const char * msg);
void logInfo(const char * msg);
void logDebug(const char * msg);

#define LogError(msg) logError(postfix(msg))
#define LogWarn(msg)  logWarn(postfix(msg))
#define LogInfo(msg)  logInfo(postfix(msg))
#define LogDebug(msg) logDebug(postfix(msg))


#endif
