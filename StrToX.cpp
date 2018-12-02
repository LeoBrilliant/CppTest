/*
 * StrToX.cpp
 *
 *  Created on: 2018年11月27日
 *      Author: LeoBrilliant
 */
#include <cstddef>
#include <cmath>
#include <cctype>
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <functional>

//float str2f( char * str, size_t len )
float str2f( const std::string & str )
{
	float f = 0.0;
	int sign = 1;
	int dot_index = -1;
	int sign_index = -1;
	bool start_parsing = false;

	for(size_t i = 0; i < str.length(); ++i )
	{
		if( str[i] == ' ' )
		{
			if( ! start_parsing )
				continue;
			else
				break;
		}
		else if( str[i] == '-' )
		{
			if( !start_parsing)
			{
				start_parsing = true;
			}

			if( sign_index == -1 )
			{
				sign_index = i;
				sign = -1;
			}
			else
			{
				bool valid = false;
				for(int j = sign_index + 1; j <= i; ++j )
				{
					if( std::isdigit(str[j]) || str[j] == '.' )
					{
						valid = true;
					}
				}
				if( !valid )
				{
					start_parsing = false;
					break;
				}
			}
		}
		else if( str[i] == '.' )
		{
			if(!start_parsing)
				start_parsing = true;
			if( dot_index == -1 )
				dot_index = i;
			else
				break;
		}
		else if( str[i] >= '0' && str[i] <= '9' )
		{
			if(!start_parsing)
				start_parsing = true;
			int num = str[ i ] - '0';
			if( dot_index == -1 )
				f = f * 10 + num * 1.0;
			else
				f = f + num * pow(0.1, i - dot_index);
		}
		else
		{
			std::cout << "not a valid number" << std::endl;
			break;
		}
	}
	if( !start_parsing )
	{
		std::cout << "we didn't find a number" << std::endl;
	}
	return f * sign;
}

void str2fTest()
{
	using namespace std;
	// float f;

//	cout << str2f( "1" ) << endl;
//
//	cout << str2f( "1.0" ) << endl;
//
//	cout << str2f( "" ) << endl;
//
//	cout << str2f( "       " ) << endl;

//	cout << str2f( " 1 1234" ) << endl;
//
//	cout << str2f( "-1" ) << endl;

	cout << str2f( "- 123.12345" ) << endl;

	cout << setiosflags(ios::fixed) << str2f( "-123.12345" ) << endl;

	cout << str2f( " -." ) << endl;

	cout << str2f( " -   - " ) << endl;

	cout << str2f( " -- " ) << endl;

	cout << str2f( " a- " ) << endl;

	cout << str2f( " 1a- " ) << endl;
}

float str2f2(const std::string& str)
{
	float f;
	sscanf(str.c_str(), "%f", &f);
	return f;
}

float str2f3(const std::string& str)
{
	using namespace std;
	float f;

	stringstream ss;
	ss.str( str );

	ss >> f;

	return f;
}

class StrToF
{
	enum { READY, EXPECT_SIGN_DOT_DIGIT, EXPECT_DOT_DIGIT, EXPECT_DIGIT, FINISH, NOT_A_NUM } status;
	inline bool isdot(char c) { return c == '.'; }
	inline bool isplus(char c) { return c == '+'; }
	inline bool isminus(char c) { return c == '-'; }
	inline bool issign(char c) { return isplus( c ) or isminus( c ); }
	inline int c2i( char c ) { return c - '0'; }
	float f;
	int sign;
	enum { SUCCESS, FAILURE, NEVER_RUN} result;
	float factor;

	void processSignDotDigit(char c)
	{
		if( isplus( c ) )
		{
			status = EXPECT_DOT_DIGIT;
		}
		else if( isminus( c ))
		{
			status = EXPECT_DOT_DIGIT;
			sign = -1;
		}
		else if( isdot( c ))
		{
			status = EXPECT_DIGIT;
			factor = 0.1;
		}
		else if( isdigit( c ) )
		{
			status = EXPECT_DOT_DIGIT;
			f =  c2i( c );
		}
		else if ( isspace( c ))
		{
			return;
		}
		else
		{
			status = NOT_A_NUM;
			result = FAILURE;
		}
	}

	void processDotDigit( char c )
	{
		if(isdigit( c ))
		{
			f = f * 10 + c2i(c);
		}
		else if( isdot( c ) )
		{
			factor = 0.1;
			status = EXPECT_DIGIT;
		}
		else
		{
			status = NOT_A_NUM;
			result = FAILURE;
		}
	}

	void processDigit( char c )
	{
		if( isdigit( c ))
		{
			f = f + c2i( c ) * factor;
			factor *= 0.1;
		}
		else
		{
			status = FINISH;
			result = SUCCESS;
		}
	}
	void process(char c)
	{
		switch(status)
		{
		case EXPECT_SIGN_DOT_DIGIT:
			processSignDotDigit(c);
			break;
		case EXPECT_DOT_DIGIT:
			processDotDigit(c);
			break;
		case EXPECT_DIGIT:
			processDigit(c);
			break;
		}
	}
	void reset()
	{
		status = READY;
		f = 0.0;
		sign = 1;
		result  = NEVER_RUN;
		factor = 1;
	}
public:
	StrToF() : status(READY),f(0.0), sign(1),result(NEVER_RUN),factor(1) {}
	// using namespace std;
	float str2f(const std::string& str)
	{
		reset();
		status = EXPECT_SIGN_DOT_DIGIT;
		for(auto c : str)
		{
			if(result == SUCCESS || result == FAILURE)
			{
				break;
			}
			process(c);
		}
		return f * sign;
	}
};
// void str2f2Test(float(*fut)(const std::string&) )
void str2f2Test(std::function<float(const std::string&)> fut )
{
	using namespace std;

	string s;
//	s = "1";
//	cout << fut(s) << endl;
//	s = "1.0";
//	cout << fut(s) << endl;
//	s = "-1";
//	cout << fut(s) << endl;
//	s = "-1.0";
//	cout << fut(s) << endl;
//	s = "- 1";
//	cout << fut(s) << endl;
//	s = "-a";
//	cout << fut(s) << endl;
//	s = "a";
//	cout << fut(s) << endl;
	s = " 1.12345";
	cout << fut(s) << endl;
	s = "1.12345   ";
	cout << fut(s) << endl;
	s = "  1.12345  ";
	cout << fut(s) << endl;
	s = ".12345  ";
	cout << fut(s) << endl;
	s = "  1.12 345  ";
	cout << fut(s) << endl;
	s = "+1.12345  ";
	cout << fut(s) << endl;
	s = "  +-1.12345";
	cout << fut(s) << endl;

	s = "  -01010100.1234500";
	cout << setiosflags(ios::fixed) << fut(s) << endl;
}

void StrToFTest()
{
//	str2fTest();
//	str2f2Test( str2f2 );

	str2f2Test( str2f3 );

	StrToF s2f;
	str2f2Test( std::bind(&StrToF::str2f, &s2f, std::placeholders::_1));
}
