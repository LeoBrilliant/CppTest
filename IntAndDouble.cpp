/*
 * IntAndDouble.cpp
 *
 *  Created on: Jul 23, 2018
 *      Author: bliu
 */

#include <iostream>

using namespace std;

#define PRINT( x ) \
    cout << #x << '\t' << x

#define PRINTLN( x ) \
    PRINT( x ); \
    cout << endl

void IntAndDoubleTest()
{
    int i1 = 1;
    double d1 = i1;

    PRINTLN( i1 );
    PRINTLN( d1 );

    d1 = 2.5;
    i1 = d1;

    PRINTLN( i1 );
    PRINTLN( d1 );

    i1 = *(int *)(& d1);
    PRINTLN( i1 );
    PRINTLN( d1 );

    i1 = 1;
    d1 = *(double *)(& i1);
    PRINTLN( i1 );
    PRINTLN( d1 );

    d1 = 2.5;
    i1 = static_cast<int>(d1);
    PRINTLN( i1 );
    PRINTLN( d1 );

/*    i1 = dynamic_cast<int>(d1);
    PRINTLN( i1 );
    PRINTLN( d1 );

    i1 = reinterpret_cast<int>(d1);
    PRINTLN( i1 );
    PRINTLN( d1 );
*/
}


