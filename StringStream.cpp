/*
 * StringStream.cpp
 *
 *  Created on: Sep 1, 2017
 *      Author: bliu
 */

#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

void StringStreamTest()
{
    stringstream ss;
    stringstream ss2;

    ss << "Hello World ";
    ss << 10;
    ss << "\x01";

    ss << setprecision(9) << 3.1415926;
    ss << std::fixed;
    ss << '\x41';
    cout << ss.str() << endl;

    char * cp = new char[1024];

    strncpy(cp, ss.str().c_str(), 1024);

    ss2 << "This is test stream";
    ss2 << ss.str();

    cout << ss2 << endl;
    cout << ss2.str() << endl;

    ss.clear();
    delete [] cp;
}


