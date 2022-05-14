#pragma once
#include "json11.hpp"

namespace JsonTests
{
	void Test1()
	{
		json11::Json json = json11::Json::object
		{
			{"id", 4},
			{"Name", "Vasya"},
			{"IsAlive", true}
		};
		std::cout << json.dump() << std::endl;
	}

	void Test2()
	{
		std::vector<json11::Json> v;
		for (int i = 0; i < 5; i++)
		{
			json11::Json json = json11::Json::object
			{
				{"id", i+6},
				{"Name", "Vasya_"+ std::to_string(i)},
				{"IsAlive", std::rand() % 2 == 0}
			};
			v.push_back(json);
		}
		json11::Json j = v;
		std::cout << j.dump() << std::endl;

		std::cout << j.is_array() << std::endl;
		std::cout << j.array_items()[0]["id"].dump() << std::endl;
		std::cout << j.array_items()[0].dump() << std::endl;
		
		for (auto json : j.array_items())
		{
			int a = json["id"].int_value();
			std::cout << a << ", ";
		}


	}
}