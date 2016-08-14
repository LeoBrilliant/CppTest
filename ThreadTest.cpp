/*
 * ThreadTest.cpp
 *
 *  Created on: 2016年5月28日
 *      Author: LeoBrilliant
 */

#include "ThreadTest.h"

void f1(int n, mutex & mctrl)
{
	cout << "ThreadID " << this_thread::get_id() << endl;
	int workcounter = 0;
	int sleepcounter = 0;
	//	for(int i = 0; i < 5; ++i)
	while(1)
	{
		if(mctrl.try_lock())
		{
			cout << "Thread 1 executing: " << ++workcounter << endl;;
			++ n;
		}
		else
		{
			cout << "Thread 1 has no work to do, sleep for 1 second. " << ++sleepcounter << endl;
			this_thread::sleep_for(chrono::seconds(5));
		}
	}

	cout << "n in thread1 is " << n << endl;
}

void f2(int & n, mutex * mp)
{
	int workcounter = 0;
	int sleepcounter = 0;

	cout << "ThreadID " << this_thread::get_id() << endl;
	//	for(int i = 0; i < 5; ++i)
	while(true)
	{
		if(mp->try_lock())
		{
			cout << "Thread 2 executing: " << ++workcounter << endl;;
			++ n;
		}
		else
		{
			cout << "Thread 2 has no work to do, sleep for 1 second. " << ++sleepcounter << endl;
			this_thread::sleep_for(chrono::seconds(5));
		}
	}
	cout << "n in thread2 is " << n << endl;
}

void ThreadTest()
{
	int n = 0;
	mutex m1, m2;
	m1.lock();
	m2.lock();
	thread t1;
//	thread t2(f1, n + 1, ref(m1));
	thread t3(f2, ref(n), &m2);
	//thread t3(f2, n); //这种传值方式会报错
	thread t4(move(t3));

//	t2.detach();

	cout << "sizeof mutex: " << sizeof(mutex) << endl;
	while(1)
	{
		cout << "input here: " ;
		int command;
		cin >> command;
		switch(command)
		{
		case 1:
			m1.unlock();
			break;
		case 2:
			m2.unlock();
			break;
		case 3:
			cout << "n is " << n << endl;
			break;
		default:
			goto label;
			break;
		}

	}

label:
	//	t2.join();
	//	t4.join();
	cout << "Final value of n is " << n << endl;
}


