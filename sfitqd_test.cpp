/*
 * sfitqd_test.cpp
 *
 *  Created on: May 11, 2017
 *      Author: bliu
 */

#include <signal.h>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <exception>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/program_options.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/foreach.hpp>
#include <bb/core/CompactMsg.h>
#include <bb/core/compat.h>
#include <bb/core/date.h>
#include <bb/core/env.h>
#include <bb/core/messages.h>
#include <bb/core/timeval.h>
#include <bb/core/LuaState.h>
#include <bb/core/Log.h>
#include <bb/core/PersistentSequenceNumber.h>
#include <bb/core/DatedFilenameFormatter.h>
#include <bb/io/Socket.h>
#include <bb/io/SendTransport.h>
#include <bb/threading/Lock.h>
#include <libshfe/shfeparsers.h>
//#include "ThostFtdcMdApi.h"

#include <tbb/concurrent_hash_map.h>
#include <tbb/atomic.h>

using namespace bb;

timeval_t make_time(const char * yyyymmdd)
{
    int datenum = atoi(yyyymmdd);

    int year = datenum /10000;
    int month = (datenum % 10000)/100;
    int day = (datenum % 100);

    struct tm tm = {};

    tm.tm_mday = day;
    tm.tm_mon = month - 1;
    tm.tm_year = year - 1900;

    tm.tm_isdst = -1;
    const time_t midnight = mktime( &tm );

    return timeval_t ( static_cast<int32_t> ( midnight ) );
}


void Test_make_time()
{
    using namespace std;

    string s;
    timeval_t t;

    cout << "Test case 1" << endl;
    s = "";
    t = make_time(s.c_str());
    cout << t << endl;
    LOG_INFO << t << bb::endl;

    cout << "Test case 2" << endl;
    s = "20170512";
    t = make_time(s.c_str());
    cout << t << endl;
    LOG_INFO << t << bb::endl;

    cout << "Test case 3" << endl;
    s = "2017";
    t = make_time(s.c_str());
    cout << t << endl;
    LOG_INFO << t << bb::endl;

    cout << "Test case 4" << endl;
    s = "1234568";
    t = make_time(s.c_str());
    cout << t << endl;
    LOG_INFO << t << bb::endl;

    cout << "Test case 5" << endl;
    s = "123456789";
    t = make_time(s.c_str());
    cout << t << endl;
    LOG_INFO << t << bb::endl;
}

