/*
 * JsonTest.h
 *
 *  Created on: 2016Äê5ÔÂ21ÈÕ
 *      Author: LeoBrilliant
 */

#ifndef JSONTEST_H_
#define JSONTEST_H_

#include <json/json.h>

void JsonTest()
{
	Json::Value json_temp;
	json_temp["name"] = Json::Value("LeoBrilliant");
	json_temp["age"] = Json::Value(31);

	Json::Value root;
	root["key_string"] = Json::Value("value_string");
	root["key_number"] = Json::Value(12345);
	root["key_boolean"] = Json::Value(false);
	root["key_double"] = Json::Value(3.1415926);
	root["key_object"] = json_temp;
	Json::ValueType type = root.type();

	std::cout << type << std::endl;
	std::cout << root["key_double"] << std::endl;

	Json::FastWriter fast_writer;
	std::cout << fast_writer.write(root) << std::endl;

	Json::StyledWriter styled_writer;
	std::cout << styled_writer.write(root) << std::endl;

	Json::Reader reader;
	Json::Value json_object;
	const char * json_document  = "{\"age\" : 26,\"name\" : \"LeoBrilliant\"}";

	if(!reader.parse(json_document, json_object))
	{
		std::cout << "json parse failed" << std::endl;
		//return 0;
	}

	std::cout << json_object["name"] << std::endl;
	std::cout << json_object["age"] << std::endl;
}

void AnotherJsonTest()
{
	Json::Value json_temp;
	json_temp["name"] = Json::Value("LeoBrilliant");
	json_temp["age"] = Json::Value(31);

	Json::Value root;
	root["key_string"] = Json::Value("value_string");
	root["key_number"] = Json::Value(12345);

	using namespace Json;

	root["key_boolean"] = Value(false);
	root["key_double"] = Value(3.1415926);
	root["key_object"] = json_temp;
	root["key_array"].append("array_string");
	root["key_array"].append(2016);

	ValueType type  = root.type();

	StyledWriter styled_writer;
	std::cout << styled_writer.write(root) << endl;

	Reader reader;
	Value json_object;
	const char * json_document = "{\"age\":31, \"name\":\"Áõ±ó\"}"; //LeoBrilliant
	if(!reader.parse(json_document, json_object))
		cerr << "Json Parse Failed" << endl;

	cout << json_object["name"] << endl;
	cout << json_object["name"].asString() << endl;
	cout << json_object["age"] << endl;

	return;
}

#endif /* JSONTEST_H_ */
