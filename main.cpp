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
#include "Factorial.h"

void SizeOfTest();

void ListTest();
//void ThreeWorkerTest();

extern void LuaTest();

extern void OperatorTest();

void InheritanceTest();

void VirtualInheritanceTest();

// void GTestTutorial(int argc, char ** argv);

void StrToFTest();

int main(int argc, char ** argv)
{
//	OperatorTest();
//	LuaTest();
//	FactorialTest();
	//ListTest();
	//使用命名空间的方式解决变量名冲突问题
//	ThreeWorker::ThreeWorkerTest();
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
//	InheritanceTest();
//	VirtualInheritanceTest();
//	GTestTutorial(argc, argv);

	StrToFTest();
	return 0;
}


