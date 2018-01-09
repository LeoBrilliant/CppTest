/*
 * OperatorTest.cpp
 *
 *  Created on: May 25, 2017
 *      Author: bliu
 */


#include <iostream>

using namespace std;

#define OUTPUT(x)  cout << #x << "\t:\t" << x << endl

void OperatorTest()
{
    int i = 0;

    OUTPUT(i);

    int j = ~i;
    OUTPUT(~i);
    OUTPUT(j);

    int k = 1;
    OUTPUT(k);
    OUTPUT(~k);

//    enum Dir {S = 0, B = 1};

    enum Dir {S, B };
    Dir d = S;

    cout << d << endl;
    OUTPUT(d);

    OUTPUT(~d);

    OUTPUT(!d);

    double ad[2] = {1, 2};

    cout << ad[~d] << endl;
    //Dir d2 = ~d;

    //OUTPUT(d2);
}
