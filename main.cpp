/*
 * main.cpp
 *
 *  Created on: 2016��5��5��
 *      Author: LeoBrilliant
 */

#include "MmapTest.h"
#include "ReflectionTest.h"
#include "JsonTest.h"
#include "ChronoTest.h"
#include "MySQLTest.h"
#include "PrecompileTest.h"
#include "CFunctionTest.h"

#include "ThreadTest.h"
#include "ZmqTest.h"

#include "Log4CPlusTest.h"

extern void SizeOfTest();

int main()
{
	SizeOfTest();
//	Log4CPlusTest();
//	Log4CPlusTestLogFile();
//	Log4CPlusTestLogLog();
//	ZmqTest();
//	ThreadTest();
//	STRTest();
//	SPrintfTest();
//	MySqlTest();
//	TimePointTest();
//	JsonTest();
//	ReflectionTest();
//	mmap_test();
	return 0;
}


