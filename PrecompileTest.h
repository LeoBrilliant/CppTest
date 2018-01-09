/*
 * PrecompileTest.h
 *
 *  Created on: 2016Äê5ÔÂ25ÈÕ
 *      Author: user
 */

#ifndef PRECOMPILETEST_H_
#define PRECOMPILETEST_H_

#define STR(x) #x

#define STRA(x) STR(str##x)

#include <iostream>
#include <typeinfo>

using namespace std;

void STRTest()
{
	int int_a = 10;

	cout << STR(int_a) << int_a << endl;

	string str(STR(int_a));

	cout << str << str.length() << endl;

	string s(STRA(int_a));

	cout << s << s.length() << endl;

	cout << typeid(int).name() << endl;

	cout << typeid(int **).name() << endl;

	cout << typeid(int &).name() << endl;

	cout << typeid(long).name() << endl;
}



#endif /* PRECOMPILETEST_H_ */
