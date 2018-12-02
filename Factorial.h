/*
 * Factorial.h
 *
 *  Created on: 2017年2月18日
 *      Author: LeoBrilliant
 */

#ifndef FACTORIAL_H_
#define FACTORIAL_H_

#include <iostream>
using namespace std;

template<int n>struct Factorial{
	enum{ val = Factorial<n - 1>::val * n};
};

template<> struct Factorial<0> {
	enum{ val = 1};
};

int FactorialTest()
{
	cout << Factorial<12>::val << endl;
}

#endif /* FACTORIAL_H_ */
