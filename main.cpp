/*
 * main.cpp
 *
 *  Created on: 2016Äê5ÔÂ5ÈÕ
 *      Author: LeoBrilliant
 */

#include "MmapTest.h"
#include "ReflectionTest.h"
#include "JsonTest.h"
#include "ChronoTest.h"
#include "MySQLTest.h"

#include <mysql.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>


int main()
{
	char s[10];
	sprintf(s,"%s word", "hello");
	std::cout << s << endl;
//	MySqlTest();
//	TimePointTest();
//	JsonTest();
//	ReflectionTest();
//	mmap_test();
	return 0;
}


