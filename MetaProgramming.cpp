/*
 * MetaProgramming.cpp
 *
 *  Created on: Jan 23, 2018
 *      Author: leo
 */

#include <iostream>
#include <typeinfo>

using namespace std;

template<int n> struct Factorial
{
	enum { val = Factorial<n-1>::val * n };
};

template<> struct Factorial<0>
{
	enum { val = 1 };
};

template<int n> struct Fib
{
	enum { val = Fib<n-1>::val + Fib<n-2>::val };
};

template<> struct Fib<1>
{
	enum { val = 1 };
};

template<> struct Fib<0>
{
	enum { val = 0 };
};

template<int n, template<int> class F> struct Accumulate
{
	enum { val = Accumulate<n-1, F>::val + F<n>::val };
};

template<template<int> class F> struct Accumulate<0, F>
{
	enum { val = F<0>::val };
};

template<int n> struct Identity
{
	enum { val = n };
};

template<int n> struct Square
{
	enum { val = n * n };
};

template<int n> struct Cube
{
	enum { val = n * n * n};
};

template<bool> struct StaticCheck
{
	StaticCheck(...);
};

template<> struct StaticCheck<false>
{

};

#define STATIC_CHECK(expr, msg) { \
	class Error_##msg{};	\
	sizeof(( StaticCheck<expr>(Error_##msg())));	\
}

template<class To, class From> To safe_cast(From from)
{
	STATIC_CHECK( sizeof(From) <= sizeof(To), NarrowingConversion );
	cout << typeid(from).name() << endl;
	cout << typeid(To).name() << endl;
	return reinterpret_cast<To>( from );
}

#define STATIC_ASSERT( x ) \
		do { typedef int a[ (x) ? 1 : -1 ]; } while ( 0 )

void MetaProgrammingTest()
{
	cout << "Factorial Test" << endl;
	cout << Factorial<12>::val << endl;
	cout << Factorial<0>::val << endl;
	cout << Factorial<1>::val << endl;
//	cout << Factorial<13>::val << endl;

	cout << "Fibonacci Test" << endl;
	cout << Fib<5>::val << endl;
	cout << Fib<20>::val << endl;
	cout << Fib<12>::val << endl;

	cout << "Accumulate Test" << endl;
	cout << Accumulate<4, Identity>::val << endl;
	cout << Accumulate<4, Square>::val << endl;
	cout << Accumulate<4, Cube>::val << endl;

	cout << "Static Check Test" << endl;
	void * p = 0;
	long long i = safe_cast<long long>(p);
	i = safe_cast<long long, void *>(p);
//	i = safe_cast<void *, long long>(p);
	cout << "long long cast OK" << endl;
	//unsigned u = safe_cast<unsigned>(i);

	cout << "Static Assert Test" << endl;
	STATIC_ASSERT( sizeof(int) <= sizeof(long) );
	//STATIC_ASSERT( sizeof(double) <= sizeof(int) );
}
