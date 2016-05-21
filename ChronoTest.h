/*
 * ChronoTest.h
 *
 *  Created on: 2016Äê5ÔÂ21ÈÕ
 *      Author: LeoBrilliant
 */

#ifndef CHRONOTEST_H_
#define CHRONOTEST_H_

#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;
void TimePointTest()
{
	time_point<system_clock> p1, p2, p3;
	p2 = system_clock::now();

	time_t now_time = system_clock::to_time_t(p2);
	cout << "now: " << ctime(&now_time) << endl;
	cout << duration_cast<std::chrono::microseconds>(p2.time_since_epoch()).count() << endl;

	duration<time_t, std::micro> milli_dura = duration_cast<microseconds>(p2.time_since_epoch());

	cout << milli_dura.count() << endl;

	time_point<system_clock> p4(milli_dura);
	time_t new_time = (system_clock::to_time_t(p4));
	cout << ctime(&new_time) << endl;

	tm t = *localtime(&new_time);
	time_t ticks = time(NULL);
	tm t2 = *localtime(&ticks);
	//cout << put_time(&t, "%c %Z") << endl;
	cout << asctime(&t) << endl;
	cout << asctime(&(*gmtime(&new_time))) << endl;

	cout << asctime(&(*localtime(&ticks))) << endl;

	tm * ptm = localtime(&ticks);
	cout << asctime(ptm) << endl;
}

#endif /* CHRONOTEST_H_ */
