/*
 * ReflectionTest.h
 *
 *  Created on: 2016Äê5ÔÂ8ÈÕ
 *      Author: LeoBrilliant
 */

#ifndef REFLECTIONTEST_H_
#define REFLECTIONTEST_H_

#include <iostream>
#include <string>
#include "DynBase.h"

using namespace std;

class A : public Object
{
	DECLARE_CLASS(A)
public:
	A(){cout << hex << (long)this << "A Constructor" <<endl; }
	~A(){cout << hex << (long)this << "A Destructor" << endl; }
};

IMPLEMENT_CLASS(A)

class B : public Object
{
	DECLARE_CLASS(B)
public:
	B(){cout << hex << (long)this << "B Constructor" <<endl; }
	~B(){cout << hex << (long)this << "B Destructor" << endl; }
};

IMPLEMENT_CLASS(B)

void ReflectionTest()
{
	Object *p = Object::CreateObject("A");
	delete p;
}

#endif /* REFLECTIONTEST_H_ */
