/*
 * main.cpp
 *
 *  Created on: 2016Äê4ÔÂ21ÈÕ
 *      Author: LeoBrilliant
 */

#include <iostream>

#include "header1.h"

#include "UT/UT1.h"

//#include "UnitTest/ChainHashTableTest.h"
#include "ChainHashTableTest.h"

using namespace std;

int main()
{
	cout << "Test Project!" << endl;

	C1 c1;
	c1.C1F1();
	c1.C1F2();

	UTC1 uc1;
	uc1.test1();
	uc1.test2();
	uc1.test3();

	ChainHashTableTest<int> chtt;
	//chtt.ContructorTest();
}



