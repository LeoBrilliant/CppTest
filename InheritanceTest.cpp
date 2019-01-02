/*
 * InheritanceTest.cpp
 *
 *  Created on: 2018年10月16日
 *      Author: LeoBrilliant
 */

#include <iostream>

using namespace std;

class Base1 {
public:
	virtual void f() { cout << "Base1::f" << endl; }
	virtual void g() { cout << "Base1::g" << endl; }
	virtual void h() { cout << "Base1::h" << endl; }
};

class Base2 {
public:
	virtual void f() { cout << "Base2::f" << endl; }
	virtual void g() { cout << "Base2::g" << endl; }
	virtual void h() { cout << "Base2::h" << endl; }
};

class Base3 {
public:
	virtual void f() { cout << "Base3::f" << endl; }
	virtual void g() { cout << "Base3::g" << endl; }
	virtual void h() { cout << "Base3::h" << endl; }
};

class Derive : public Base1, public Base2, public Base3
{
public:
	virtual void f() { cout << "Derive::f" << endl; }
	virtual void g1() { cout << "Derive::g1" << endl; }
};

typedef void(*Fun)(void);

void InheritanceTest()
{
	Fun pFun = NULL;
	Derive d;

	size_t ** pVtab = (size_t**)&d;

	// Base1's vtable
	// pFun = (Fun)*((size_t*)*(size_t*)((size_t*)&d + 0) + 0);
	pFun = (Fun)pVtab[0][0];
	pFun();

	// pFun = (Fun)*((size_t*)*(size_t*)((size_t*)&d + 0) + 1);
	pFun = (Fun)pVtab[0][1];
	pFun();
	pFun = (Fun)*((size_t*)*(size_t*)((size_t*)&d + 0) + 1);
	pFun();

	// pFun = (Fun)*((size_t*)*(size_t*)((size_t*)&d + 0) + 2);
	pFun = (Fun)pVtab[0][2];
	pFun();

	// Derive's vtable
	// pFun = (Fun)*((size_t*)*(size_t*)((size_t*)&d + 0) + 3);
	pFun = (Fun)pVtab[0][3];
	pFun();

	// The tail of the vtable
	// pFun = (Fun)*((size_t*)*(size_t*)((size_t*)&d + 0) + 4);
	pFun = (Fun)pVtab[0][4];
	// pFun();
	cout << pFun << endl;

	// Base2's vtable
	// pFun = (Fun)*((size_t*)*(size_t*)((size_t*)&d + 1) + 0);
	pFun = (Fun)pVtab[1][0];
	pFun();

	// pFun = (Fun)*((size_t*)*(size_t*)((size_t*)&d + 1) + 1);
	pFun = (Fun)pVtab[1][1];
	pFun();

	// pFun = (Fun)*((size_t*)*(size_t*)((size_t*)&d + 1) + 2);
	pFun = (Fun)pVtab[1][2];
	pFun();

	// The tail of the vtable
	// pFun = (Fun)*((size_t*)*(size_t*)((size_t*)&d + 1) + 3);
	pFun = (Fun)pVtab[1][3];
	cout << pFun << endl;

	// Base3's vtable
	// pFun = (Fun)*((size_t*)*(size_t*)((size_t*)&d + 2) + 0);
	pFun = (Fun)pVtab[2][0];
	pFun();

	// pFun = (Fun)*((size_t*)*(size_t*)((size_t*)&d + 2) + 1);
	pFun = (Fun)pVtab[2][1];
	pFun();

	// pFun = (Fun)*((size_t*)*(size_t*)((size_t*)&d + 2) + 2);
	pFun = (Fun)pVtab[2][2];
	pFun();

	// The tail of the vtable
	// pFun = (Fun)*((size_t*)*(size_t*)((size_t*)&d + 2) + 3);
	pFun = (Fun)pVtab[2][3];
	cout << pFun << endl;

}


class Base4
{
public:
	int i;
	virtual void f() { cout << "Base4::f" << endl; }
};

class Middle1: virtual public Base4
{
public:
	int j;
	virtual void mf1() { cout << "Middle1::mf1" << endl; }
};


void VirtualInheritanceTest()
{
	Base4 b4;
	Middle1 m1;

	cout << "sizeof Base4: " << sizeof(b4) << endl;
	cout << "sizeof Middle1: " << sizeof(m1) << endl;

	b4.i = 1;

	m1.j = 3;

	cout << &m1 << endl;

	cout << &(m1.j) << endl;

	cout << &(m1.i) << endl;

	cout << &b4 << endl;

	cout << &(b4.i) << endl;
}
