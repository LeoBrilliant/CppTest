/*
 * ChainHashTableTest.cpp
 *
 *  Created on: 2016Äê4ÔÂ21ÈÕ
 *      Author: LeoBrilliant
 */


#include "ChainHashTableTest.h"

template<typename Key>
void ChainHashTableTest<Key>::TestSuite()
{
	//this->ContructorTest();
}

template<typename Key>
void ChainHashTableTest<Key>::ContructorTest()
{
	cout << __FUNCTION__ << endl;

	cout << "TestCase(" << IncCaseCount() << ")" ;
	ChainHashTable<Key> cht1;
	cout << typeid(cht1).name() << "\t";
	assert( typeid(cht1) == typeid(ChainHashTable<Key>));
	assert( &cht1 != NULL);
	assert(cht1.Size() == 0);
	cht1.GetDetail("Hello");
	IncCasePassed();
	cout << "Passed" << endl;
//
}
