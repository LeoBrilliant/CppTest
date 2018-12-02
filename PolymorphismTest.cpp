/*
 * PolymorphismTest.cpp
 *
 *  Created on: Sep 22, 2017
 *      Author: bliu
 */

#include <iostream>

using namespace std;

class IBase
{
public:
    virtual void func() = 0;

    virtual ~IBase()
    {

    }
};

void IBase::func()
{
    cout << __func__ << " interface" << endl;
}

class Base1 : public IBase
{
public:
    virtual void func()
    {
        cout << __func__ << " base" << endl;
    }
    virtual ~Base1()
    {

    }
};

class Derived1 : public Base1
{
public:
    virtual void func()
    {
        cout << __func__ << " derived" << endl;
    }
};

void PolymorphismTest()
{
    Base1 b1;
    Derived1 d1;

    b1.func();
    d1.func();

    Base1 * pb1;
    Derived1 * pd1;

    pb1 = &b1;
    pb1->func();

    pb1 = &d1;
    pb1->func();

    //pd1 = &b1;
    //pd1->func();

    pd1 = &d1;
    pd1->func();

    Base1 & rb1 = b1;
    rb1.func();
    Base1 & rb2 = d1;
    rb2.func();

    //Derived1 & rd1 = b1;
    //rd1.func();

    Derived1 & rd2 = d1;
    rd2.func();

    Derived1& rd3 = rd2;
    rd3.func();

    Derived1&  rd4 = *(Derived1 *)pb1;
    rd4.func();

    Derived1 d4 = *(Derived1 *)&b1;
    d4.func();

    Derived1& rd5 = *(Derived1 *)&b1;
    rd5.func();

    Derived1 * pd2 = (Derived1 *)&b1;
    pd2->func();

    //
    IBase& rib1 = b1;
    rib1.func();

    IBase& rib2 = d1;
    rib2.func();

    IBase * pib1 = & b1;
    pib1->func();

    IBase * pib2 = & d1;
    pib2->func();

    pib1 = pib2;
    pib1->func();

    pib2 = &rb2;
    pib2->func();

}

