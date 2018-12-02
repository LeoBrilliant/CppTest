/*
 * ConversionTest.cpp
 *
 *  Created on: Oct 30, 2017
 *      Author: bliu
 */

#include <iostream>
#include <assert.h>
#include <gtest/gtest.h>

using namespace std;

template<typename T>
T SetAllBits()
{
	T ret = 0;

	for( size_t i = 0; i < sizeof(T) * 8; ++ i )
	{
		ret <<= 1;
		ret |= 1;
	}
	return ret;
}

int Low32Bit( long int value )
{
	unsigned int mask = SetAllBits<unsigned int>();

	int temp = value & mask;

	return temp;
}

int High32Bit( long int value )
{
	unsigned int mask = SetAllBits<unsigned int>();

	int temp = ( value >> 32 ) & mask;

	return temp;
}



void SplitLongInt( long int value )
{
    unsigned long mask = 0;
    assert(sizeof(mask) == 8);

    cout << "value is: " << value << endl;
    for(int i = 0; i < 32; ++ i)
    {
        mask |= 1;
        mask <<= 1;
    }

    cout << "mask is: " << mask << endl;

    int low32bit = value & mask;
    cout << "lower 32 bits is: " << low32bit << endl;

    mask <<= 32;
    cout << "mask is: " << mask << endl;

    int high32bit = (value & mask) >> 32;
    cout << "high 32 bits is: " << high32bit << endl;
}

TEST(SetAllBits, UnsignedInt)
{
	unsigned int target = SetAllBits<unsigned int>();
	unsigned int flag = 1;
	ASSERT_TRUE( target );
	for(size_t i = 0; i < sizeof( unsigned int ); ++i)
	{
		ASSERT_TRUE( target & flag );
		flag <<= 1;
	}
}

TEST(Low32Bit, Zero)
{
	ASSERT_EQ( 0, Low32Bit(0) );
}

TEST(High32Bit, Zero)
{
	ASSERT_EQ( 0, High32Bit(0) );
}

TEST(Low32Bit, One)
{
	ASSERT_EQ( 1, Low32Bit(1) );
}

TEST(High32Bit, One)
{
	ASSERT_EQ( 0, High32Bit(1) );
}

TEST(Low32Bit, Bound1)
{
	long long value = ( long int ) 1 << 32;
	unsigned int i = Low32Bit( value );
	ASSERT_EQ( 0, Low32Bit( i ) );
}

TEST(High32Bit, Bound1)
{
	long long value = ( long int ) 1 << 32;
	unsigned int i = High32Bit( value );
	ASSERT_EQ( 1, i );
}

TEST(Low32Bit, Bound2)
{
	long long value = ( long int ) 1 << 63;
	unsigned int i = Low32Bit( value );
	ASSERT_EQ( 0, Low32Bit( i ) );
}

TEST(High32Bit, Bound2)
{
	long long value = ( long int ) 1 << 63;
	unsigned int i = High32Bit( value );
	ASSERT_EQ( 1 << 31, i );
}

void ConvertionTest()
{
/*    long int value = 0;
    cout << "input here>";
    cin >> value;
    SplitLongInt(value);*/

	int argc = 1;
	string AppName("C++Test");
	char * argv[] = { (char *)AppName.data() };
	::testing::InitGoogleTest(& argc, argv);

	int ret = RUN_ALL_TESTS();
	cout << "test result: " << ret << endl;
}

