/*
 * ThreadTest.cpp
 *
 *  Created on: Sep 6, 2017
 *      Author: bliu
 */

#include <iostream>
#include <cstdlib>
#include <boost/thread.hpp>
#include <boost/foreach.hpp>

using namespace std;

class BankAccount
{
    boost::mutex mtx_;
    int balance_;
public:
    void Deposit(int amount)
    {
        mtx_.lock();
        balance_ += amount;
        mtx_.unlock();
    }

    void WithDraw(int amount)
    {
        mtx_.lock();
        balance_ -= amount;
        mtx_.unlock();
    }

    int GetBalance()
    {
        mtx_.lock();
        int b = balance_;
        mtx_.unlock();
        return b;
    }
};

BankAccount JoesAccount;

void inline ShowBalance()
{
    int myPocket = JoesAccount.GetBalance();
    cout << boost::this_thread::get_id() << " : " << myPocket << endl;
}
void bankAgent()
{
    for(int i = 10; i > 0; --i)
    {
        JoesAccount.Deposit(500);
        ShowBalance();
        //sleep(1);
    }
}

void Joe()
{
    for(int i = 10; i > 0; --i)
    {
        JoesAccount.WithDraw(100);
        ShowBalance();
        //sleep(1);
    }
}

void test1()
{
    cout << __func__ << endl;
    boost::thread thread1(bankAgent);
    boost::thread thread2(Joe);
    thread1.join();
    thread2.join();
}


class VectorThread
{
    vector<string> vs;
    boost::mutex m_read;
    boost::mutex m_write;
public:
    VectorThread()
    {
        m_read.lock();
    }

    void write()
    {
        string s;
        while(true)
        {
            cout << "input here >";
            cin >> s;
            m_write.lock();
            vs.push_back(s);
/*            if(m_read.try_lock())
                m_read.unlock();
            else*/
                m_read.unlock();
            m_write.unlock();

            if(s.compare("exit") == 0)
            {
                return;
            }
        }
    }

    void read()
    {
        while(true)
        {
            m_read.lock();
            cout << boost::this_thread::get_id() << " : ";
            if(vs.size())
            {
                BOOST_FOREACH(string & s, vs)
                {
                    cout << s << endl;
                    if(s.compare("exit") == 0)
                    {
                        m_read.unlock();
                        return;
                    }
                }
                m_write.lock();
                vs.clear();
                m_write.unlock();
            }
        }
    }
};

static void test2()
{
    cout << __func__ << endl;
    VectorThread vt;
    boost::thread t1(boost::bind(&VectorThread::read, &vt));
    vt.write();
    t1.join();
}
void ThreadTest()
{
    cout << __func__ << endl;
    // test1();
    test2();
}

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

void ThreadTest1()
{
	int n = 0;
	mutex m1, m2;
	m1.lock();
	m2.lock();
	thread t1;
//	thread t2(f1, n + 1, ref(m1));
	thread t3(f2, ref(n), &m2);
	//thread t3(f2, n); //ÕâÖÖ´«Öµ·½Ê½»á±¨´í
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

