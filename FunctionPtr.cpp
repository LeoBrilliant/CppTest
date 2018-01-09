/*
 * FunctionPtr.cpp
 *
 *  Created on: Sep 25, 2017
 *      Author: bliu
 */

#include <iostream>

#include <boost/bind.hpp>

#include <boost/function.hpp>

#include <boost/shared_ptr.hpp>

using namespace std;

void TestFunc1()
{
    cout << __func__ << endl;
}

void TestFunc2(int i1, int i2)
{
    cout << __func__ << endl;
    cout << "i1 = " << i1 << endl;
    cout << "i2 = " << i2 << endl;
}

class FunctionPtr
{
public:
    int FunctionPtrFunc1(int i1, int i2)
    {
        cout << __func__ << endl;
        cout << "i1 = " << i1 << endl;
        cout << "i2 = " << i2 << endl;
        return 1;
    }
};

template <typename Type>
int TempFunc(Type i)
{
    cout << __func__ << endl;
    cout << "i = " << i << endl;
    return 1;
}

template <typename Type>
class TempClass
{
public:
    int TempClassFunc1(int i)
    {
        cout << __func__ << endl;
        cout << "i = " << i << endl;
        return 1;
    }
};

void FunctionPtrTest()
{
    TestFunc1();

    void (*fp1)() = TestFunc1;

    fp1();
    (*fp1)();
    fp1();

    cout << TestFunc1 << endl;
    cout << &TestFunc1 << endl;

    cout << fp1 << endl;
    cout << ios::fixed << ios::hex << (size_t) fp1 << endl;
    cout << ios::fixed << ios::hex << (size_t) &fp1 << endl;
    cout << ios::fixed << ios::hex << (size_t) *fp1 << endl;

    int i1 = 1;
    int i2 = 2;
    TestFunc2(i1, i2);

    boost::function1<void, int> bf1 = boost::bind(TestFunc2, _1, i1);
    bf1(3);

    boost::function1<void, int>bf2 = boost::bind(TestFunc2, i1, _1);
    bf2(3);

    boost::function<void()> bf3 = boost::bind(TestFunc2, 4, 5);
    bf3();

    FunctionPtr fpc;
    boost::function1<int, int> bf4 = boost::bind(&FunctionPtr::FunctionPtrFunc1, &fpc, 1, _1);
    bf4(5);

    boost::function1<int, int> bf5 = boost::bind<int>(&FunctionPtr::FunctionPtrFunc1, &fpc, 1, _1);
    bf5(56);

    typedef boost::function1<int, int> FuncType;

    FuncType funcArray[5];
    funcArray[0] = bf4;
    funcArray[1] = bf5;

    funcArray[0](33);
    // (*funcArray[1])(44);

    boost::function<int(int)> bf6 = boost::bind<int>(&FunctionPtr::FunctionPtrFunc1, &fpc, -1, _1);
    funcArray[2] = bf6;
    funcArray[2](99);

    boost::function<int(int)> bf7 = boost::bind<int>(&TempFunc<int>, 1);
    bf7(77);

    TempClass<int> tci;
    boost::function<int(int)> bf8 = boost::bind<int>(&TempClass<int>::TempClassFunc1, &tci, _1);
    bf8(88);

    boost::shared_ptr<int> spi;
    boost::shared_ptr< TempClass<int> > sp1(new TempClass<int>());
    boost::function<int(int)> bf9 = boost::bind<int>(&TempClass<int>::TempClassFunc1, sp1, _1);
    bf9(99);

}

