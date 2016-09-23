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
#include "ThreeWorkers.h"

void SizeOfTest();


//void ThreeWorkerTest();

int main()
{
	//使用命名空间的方式解决变量名冲突问题
	ThreeWorker::ThreeWorkerTest();
//	SizeOfTest();
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


