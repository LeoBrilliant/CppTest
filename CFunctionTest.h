/*
 * CFunctionTest.h
 *
 *  Created on: 2016��5��25��
 *      Author: user
 */

#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void SPrintfTest()
{
	char s[10];
	sprintf(s,"%s word", "hello");
	std::cout << s << endl;
}


