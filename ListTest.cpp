/*
 * ListTest.cpp
 *
 *  Created on: 2016年10月2日
 *      Author: LeoBrilliant
 */

#include <list>
#include <iostream>

using namespace std;


void ListTest()
{
	list<int> li;
	li.push_back(1);
	li.push_back(2);
	li.push_back(3);

	cout << li.front() << endl;

	int i = li.front();

	cout << li.front() << endl;
}

