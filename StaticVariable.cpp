/*
 * StaticVariable.cpp
 *
 *  Created on: Sep 22, 2017
 *      Author: bliu
 */

#include <iostream>

using namespace std;

#define OUTPUT(x)  cout << std::fixed << #x << "\t:\t" << x << endl

static int i1 = 1;

static const int i2 = 2;

int StaticInit()
{
    static int counter = 1;
    cout << __func__ << endl;
    return counter ++;
}

static int i3 = StaticInit();

static void StaticVariableTest1()
{
    OUTPUT(i1);
    OUTPUT(i2);
    OUTPUT(i3);
    static int i4 = StaticInit();
    OUTPUT(i4);

    for(int i = 1; i <= 10; ++i)
    {
        static int i5 = StaticInit();
        OUTPUT(i5);
    }
}

void StaticVariableTest()
{
    StaticVariableTest1();
}
