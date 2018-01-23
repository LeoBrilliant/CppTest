/*
 * main.cpp
 *
 *  Created on: May 2, 2017
 *      Author: bliu
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <signal.h>

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

using namespace std;

#define LOG_INFO cout

namespace bb = std;

const int MAX_SIG_NUM = 64;

bool g_quit_test_of_sfitqd = false;

void (*fp[MAX_SIG_NUM])(int);

void signal_handler( int sig )
{
    LOG_INFO << "received signal: " << sig << bb::endl;
    if(fp[sig - 1])
    {
        (*(fp[sig - 1]))(sig);
    }
}

void Test_catch_signal()
{
    for(int i = 1; i <= MAX_SIG_NUM; ++i)
    {
        sighandler_t f = signal( i, signal_handler );
        fp[i - 1] = f;
    }

    while( !g_quit_test_of_sfitqd) { sleep(2); }
}

extern void Test_make_time();
extern void StateMachineTest1();
extern void StateMachineTest2();
extern void OperatorTest();
extern void StringStreamTest();
extern void ThreadTest();
extern void AsioTest();
extern void FusionTest();
extern void OverloadTestCase();
extern void SharedPtrTest();
extern void StaticVariableTest();
extern void PolymorphismTest();
extern void FunctionPtrTest();
extern void StrategyPatternTest();
extern void GTestTest();
extern void ConvertionTest();
extern void PropertyTreeTest();
extern void SizeOfTest();
extern void MetaProgrammingTest();

//void ThreeWorkerTest();

int main()
{
    cout << "This is C++ Test" << endl;

	//使用命名空间的方式解决变量名冲突问题
//	ThreeWorker::ThreeWorkerTest();
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

//    Test_catch_signal();

//    Test_make_time();
//    StateMachineTest2();

//    OperatorTest();
//    StringStreamTest();

//    ThreadTest();
//    AsioTest();
//    FusionTest();
//    OverloadTestCase();
//    SharedPtrTest();
//    StaticVariableTest();
//    PolymorphismTest();
//    FunctionPtrTest();
//    StrategyPatternTest();
//    GTestTest();
//    ConvertionTest();
//    PropertyTreeTest();
//    SizeOfTest();
    MetaProgrammingTest();
    LOG_INFO << "This is end of main. " << g_quit_test_of_sfitqd << bb::endl;

    return 0;
}


