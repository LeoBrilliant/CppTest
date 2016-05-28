/*
 * ThreadTest.cpp
 *
 *  Created on: 2016年5月28日
 *      Author: LeoBrilliant
 */

#include "ThreadTest.h"

void f1(int n)
{
	cout << "ThreadID " << this_thread::get_id() << endl;

	for(int i = 0; i < 5; ++i)
	{
		cout << "Thread 1 executing\n";
		++ n;
		this_thread::sleep_for(chrono::milliseconds(10));
	}

	cout << "n in thread1 is " << n << endl;
}

void f2(int & n)
{
	cout << "ThreadID " << this_thread::get_id() << endl;
	for(int i = 0; i < 5; ++i)
	{
		cout << "Thread 2 executing\n";
		++ n;
		this_thread::sleep_for(chrono::milliseconds(10));
	}
	cout << "n in thread2 is " << n << endl;
}

void ThreadTest()
{
	int n = 0;
	thread t1;
	thread t2(f1, n + 1);
	thread t3(f2, ref(n));
	//thread t3(f2, n); //这种传值方式会报错
	thread t4(move(t3));

	t2.join();
	t4.join();
	cout << "Final value of n is " << n << endl;
}


