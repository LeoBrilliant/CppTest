/*
 * OperatorTest.cpp
 *
 *  Created on: 2017年5月25日
 *      Author: LeoBrilliant
 */

#include <iostream>
//#include <unique_ptr>

using namespace std;


#define OUTPUT(x) cout << #x << "\t:\t" << x << endl

// ! exclamation
void ExclamationTest()
{
	int i = 0;
	OUTPUT(i);
	OUTPUT(!i);

	int j = !i;
	OUTPUT(j);
	OUTPUT(!j);

	int k = !j;
	OUTPUT(k);
	OUTPUT(!k);

	enum TE { S, B, N};
	TE t = S;
	OUTPUT(t);
	OUTPUT(!t);

/*
	TE t2 = !t;
	OUTPUT(t2);
	OUTPUT(!t2);
*/

	int m = !t;
	OUTPUT(m);
	OUTPUT(!m);

	int n = 2;
	OUTPUT(n);
	OUTPUT(!n);

	int p = !n;
	OUTPUT(p);
	OUTPUT(!p);
}

// ~
void TildeTest()
{
	int i = 0;
	OUTPUT(i);
	OUTPUT(~i);

	int j = ~i;
	OUTPUT(j);
	OUTPUT(~j);

	int k = ~j;
	OUTPUT(k);
	OUTPUT(~k);

	enum TE { S, B, N};
	TE t = S;
	OUTPUT(t);
	OUTPUT(~t);

/*
	TE t2 = ~t;
	OUTPUT(t2);
	OUTPUT(~t2);
*/

	int m = ~t;
	OUTPUT(m);
	OUTPUT(~m);

	int n = 2;
	OUTPUT(n);
	OUTPUT(~n);

	int p = -1;
	OUTPUT(p);
	OUTPUT(~p);
}

void OperatorTest()
{
	ExclamationTest();

	TildeTest();

//	std::unique_ptr<int> upi;
}

