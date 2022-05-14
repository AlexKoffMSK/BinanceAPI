#pragma once
#include <chrono>
#include "../../Json/json11.hpp"

using namespace std::chrono_literals;

namespace Rest::Objects
{
	struct BestsOneInstrument
	{
		std::chrono::milliseconds _time_stamp = 0ms;
		double _bid_price;
		double _ask_price;
		double _bid_volume;
		double _ask_volume;

		BestsOneInstrument(json11::Json json_data_, std::chrono::milliseconds time_stamp_)
		{
			_time_stamp = time_stamp_;
			_bid_price = std::stod(json_data_["bidPrice"].string_value());
			_ask_price = std::stod(json_data_["askPrice"].string_value());
			_bid_volume = std::stod(json_data_["bidQty"].string_value());
			_ask_volume = std::stod(json_data_["askQty"].string_value());
		}

		void Print()
		{
			std::cout << '[' << _time_stamp << ']'
				<< '[' << std::setprecision(8) << _bid_price << " , " << std::setprecision(8) << _bid_volume << ']'
				<< '[' << std::setprecision(8) << _ask_price << " , " << std::setprecision(8) << _ask_volume << ']' << std::endl;
		}
	};
}