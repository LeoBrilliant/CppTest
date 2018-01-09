/*
 * SizeOfTest.cpp
 *
 *  Created on: Jan 9, 2018
 *      Author: bliu
 */


#include <iostream>
#include <stdint.h>

using namespace std;

class TestClass1
{
    int i1;
    uint32_t ui1;
    char c1;
public:
    char ca1[10];

    void Function()
    {

    }
};

void SizeOfTest()
{
    cout << sizeof(TestClass1) << endl;
}
