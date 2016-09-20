/*
 * ThreeWorker.cpp
 *
 *  Created on: 2016年9月20日
 *      Author: LeoBrilliant
 */

#include <thread>
#include <iostream>
#include <mutex>


namespace ThreeWorker
{
using namespace std;

mutex a, b, c;
// 因为mutex变量名与全局空间其他变量名冲突，使用static限定变量作用域。
//static mutex a, b, c;
static int count = 5;

void PrintA()
{
	for(int i = 0; i < count; ++i)
	{
		a.lock();
		cout << "A" << endl;
		b.unlock();
	}
	a.unlock();
}

void PrintB()
{
	for(int i = 0; i < count; ++i)
	{
		b.lock();
		cout << "B" << endl;
		c.unlock();
	}
	b.unlock();
}

void PrintC()
{
	for(int i = 0; i < count; ++i)
	{
		c.lock();
		cout << "C" << endl;
		a.unlock();
	}
	c.unlock();
}

void PrintMethod(char c, mutex & curr, mutex & next, int count = 5)
{
	cout << "Thread: " << this_thread::get_id() << endl;
	for(int i = 0; i < count; ++i)
	{
		curr.lock();
		cout << c << endl;
		next.unlock();
	}
	curr.unlock();
}
void ThreeWorkerTest()
{
	cout << __FUNCTION__ <<  " begins" << endl;
	a.lock();
	b.lock();
	c.lock();

	//thread w1(PrintA);
	//thread w2(PrintB);
	//thread w3(PrintC);

	thread w3(PrintMethod, 'C', ref(c), ref(a), 5);
	thread w1(PrintMethod, 'A', ref(a), ref(b), 5);
	thread w2(PrintMethod, 'B', ref(b), ref(c), 5);

	a.unlock();
	w1.join();
	w2.join();
	w3.join();

	cout << __FUNCTION__ << " ends" << endl;
}
};

