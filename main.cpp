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

int main()
{
    cout << "This is C++ Test" << endl;

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
    SizeOfTest();

    LOG_INFO << "This is end of main. " << g_quit_test_of_sfitqd << bb::endl;

    return 0;
}


