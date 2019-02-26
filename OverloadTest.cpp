/*
 * OverloadTest.cpp
 *
 *  Created on: Sep 18, 2017
 *      Author: bliu
 */

#include <iostream>

using namespace std;

class OverloadTest
{
public:
    OverloadTest(){}
    void handle(const int i)  {   cout << __func__ << "int" << endl;   }
    void handle(double d)   {   cout << __func__ << "double" << endl;    }
    void handle(char c)   {   cout << __func__ << "c" << endl;    }
};

template<typename Arg>
class ActionHolder
{
public:
    ActionHolder(const Arg * a): handler(&OverloadTest::handle), a(a)
    {
        cout << __func__ << handler << endl;
    }

    typedef void (OverloadTest::*handler_type)( Arg );
    handler_type handler;
    const Arg * a;

    void operator()(OverloadTest * ot)
    {
        cout << "operator()" << endl; (ot->*handler)(*a);
    }
};

class OverloadTest1
{
public:
    void func(int = 0) { cout << __func__ << "int" << endl; }
    void func(int & ir) { cout << __func__ << "int ref" << endl; }
};

void OverloadTestCase()
{
//    cout << &OverloadTest::handle << endl;

    OverloadTest olt;

    int i = 1;
    ActionHolder<int> ahi(&i);

    ahi(&olt);

    char c = 'a';
    ActionHolder<char> ahc(&c);
    ahc(&olt);

    double d = 1.234;
    ActionHolder<double> ahd(&d);
    ahd(&olt);

    OverloadTest1 olt1;
//    olt1.func(i);
}


