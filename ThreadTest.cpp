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
