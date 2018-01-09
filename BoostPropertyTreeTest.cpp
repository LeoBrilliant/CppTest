/*
 * BoostPropertyTreeTest.cpp
 *
 *  Created on: Nov 15, 2017
 *      Author: bliu
 */

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <iostream>

using namespace boost::property_tree;
using namespace std;

void WriteJsonTest()
{
	ptree root;
	root.put( "key1", "value1" );
	root.put( "key2", 2 );

	json_parser::write_json( cout, root );

	stringstream ss;
	json_parser::write_json ( ss, root );

	ss << "\n";
	cout << ss.str() << endl;

	cout << strlen( ss.str().c_str() ) << endl;
}

void PropertyTreeTest()
{
	WriteJsonTest();
}

