/*
 * Log4CPlusTest.h
 *
 *  Created on: 2016��8��14��
 *      Author: LeoBrilliant
 */

#ifndef LOG4CPLUSTEST_H_
#define LOG4CPLUSTEST_H_


#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <iostream>
#include <log4cplus/consoleappender.h>
#include <log4cplus/layout.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/fileappender.h>
#include <log4cplus/helpers/loglog.h>

#include <tchar.h>
//#include <log4cplus/helpers/sleep.h>

using namespace log4cplus;
using namespace log4cplus::helpers;
using namespace std;

void Log4CPlusTest()
{
	cout << "Log4CPlusTest" << endl;
	SharedObjectPtr<Appender> appender(new ConsoleAppender());

	appender->setName(LOG4CPLUS_TEXT("appender for test"));

	auto_ptr<Layout> layout(new PatternLayout(LOG4CPLUS_TEXT("%d{%m/%d/%y %H:%M:%S} - %m[%l]%n")));

	appender->setLayout(layout);

	Logger logger = Logger::getInstance(LOG4CPLUS_TEXT("test"));

	logger.addAppender(appender);
	//logge
	logger.setLogLevel(ALL_LOG_LEVEL);

	LOG4CPLUS_DEBUG(logger, "This is the first log Message...");

	sleep(1);

	LOG4CPLUS_WARN(logger, "This is the Second log Message...");

	return;
}

//Failed
/*void Log4CPlusTestFile()
{
	tstring file_name = _T("log.txt");

	initialize();

	log4cplus::helpers::LogLog::getLogLog()->setInternalDebugging(true);

	SharedAppenderPtr appender(new FileAppender((file_name)));
	appender->setName(LOG4CPLUS_TEXT("MAIN"));
	Logger::getRoot().addAppender(appender);
	auto_ptr<Layout> pPatternLayout(new PatternLayout(_T("%d{%y/%m/%d %H:%M:%S} - %m [%l] %n")));
	appender->setLayout(pPatternLayout);

	Logger root = Logger::getRoot();

	root.setLogLevel(ALL_LOG_LEVEL);

	LOG4CPLUS_TRACE(Logger::getRoot(), "ABC");
}*/

void Log4CPlusTestLogFile()
{
	tstring file_name = _T("Test.log");
	SharedAppenderPtr appender(new FileAppender(file_name));

	appender->setName("logFileTest");

	Logger logger = Logger::getInstance("test.subsetof_filelog");

	logger.addAppender(appender);

	for(int i = 0; i < 5; ++i)
	{
		LOG4CPLUS_DEBUG(logger, "Entering loop#" << i << "Endline#");
	}
	return;
}


void printMsgs()
{
	cout << "Entering printMsgs()..." << endl;

	LogLog::getLogLog()->debug("This is a Debug statement");
	LogLog::getLogLog()->warn("This is a Waring...");
	LogLog::getLogLog()->error("This is a Error...");

	cout << "Exiting printMsgs()..." << endl;

	return;
}

void Log4CPlusTestLogLog()
{
	cout << "Test begins" << endl;
	printMsgs();

	cout << "Turning on debug..." << endl;

	LogLog::getLogLog()->setInternalDebugging(true);
	printMsgs();

	cout << "Turning on quiet mode..." << endl;
	LogLog::getLogLog()->setQuietMode(true);
	printMsgs();

	return;
}
#endif /* LOG4CPLUSTEST_H_ */
