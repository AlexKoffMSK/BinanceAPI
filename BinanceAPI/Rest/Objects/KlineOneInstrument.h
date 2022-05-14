#pragma once
#include "../../Json/json11.hpp"
#include <chrono>
#include "../../CommonFunctions/CommonFunctions.h"

namespace Rest::Objects
{
	struct KlineOneInstrument
	{
		std::chrono::milliseconds _open_time;
		double	_open_price;
		double	_high_price;
		double	_low_price;
		double	_close_price;
		double	_volume_trade;
		std::chrono::milliseconds _close_time;
		double	_quote_asset_volume;
		int		_number_of_trades;
		double	_taker_buy_base_asset_volume;
		double	_taker_buy_quote_asset_volume;

		KlineOneInstrument(json11::Json json_data_)
		{
			_open_time = std::chrono::milliseconds((uint64_t)(json_data_[0].number_value()));
			_open_price = std::stod(json_data_[1].string_value());
			_high_price = std::stod(json_data_[2].string_value());
			_low_price = std::stod(json_data_[3].string_value());
			_close_price = std::stod(json_data_[4].string_value());
			_volume_trade = std::stod(json_data_[5].string_value());
			_close_time = std::chrono::milliseconds((uint64_t)(json_data_[6].number_value()));
			_quote_asset_volume = std::stod(json_data_[7].string_value());
			_number_of_trades = json_data_[8].int_value();
			_taker_buy_base_asset_volume = std::stod(json_data_[9].string_value());
			_taker_buy_quote_asset_volume = std::stod(json_data_[10].string_value());
		}

		void Print() //times,openprice, closeprice,numtrades
		{
			std::cout << '[' << CommonFunctions::CovertStampToHumanDate(_open_time) << " - " << CommonFunctions::CovertStampToHumanDate(_close_time) << ']'
				//std::cout << '[' << _open_time << " - " << _close_time << ']'
				<< '[' << std::setprecision(8) << std::setw(8) << _open_price << " , " << std::setprecision(8) << std::setw(8) << _close_price << ']'
				<< '[' << _number_of_trades << ']' << std::endl;
		}

	};
}