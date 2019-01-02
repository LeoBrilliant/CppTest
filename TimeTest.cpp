/*
 * TimeTest.cpp
 *
 *  Created on: Jan 16, 2018
 *      Author: bliu
 */


#include <iostream>
#include <time.h>
#include <sys/time.h>

int TimeTest()
{
    int result;
    struct timespec tp;
    clockid_t clk_id;
    struct timeval tv;

//    clk_id = CLOCK_MONOTONIC;
    clk_id = CLOCK_REALTIME;

    gettimeofday(&tv, NULL);
    result = clock_gettime(clk_id, &tp);

    using namespace std;

    cout << "result:" << result << endl;
    cout << "tp.tv_sec:" << tp.tv_sec << endl;
    cout << "tp.tv_nsec: " << tp.tv_nsec << endl;
    cout << "tv.tv_sec:" << tv.tv_sec << endl;
    cout << "tv.tv_usec:" << tv.tv_usec << endl;

    gettimeofday(&tv, NULL);
    result = clock_getres(clk_id, &tp);
    cout << "result:" << result << endl;
    cout << "tp.tv_sec:" << tp.tv_sec << endl;
    cout << "tp.tv_nsec: " << tp.tv_nsec << endl;
    cout << "tv.tv_sec:" << tv.tv_sec << endl;
    cout << "tv.tv_usec:" << tv.tv_usec << endl;

    return result;
}
