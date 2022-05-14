#pragma once
#include "RestApi.h"
#include "Http/HttpRequest.h"


namespace Rest
{
	Rest::Objects::BestsOneInstrument GetCurrentBests(std::string symbol)
	{
		//https://api.binance.com/api/v3/ticker/bookTicker?symbol=BTCUSDT
		//есть функци€, котора€ умеет ответ этого запроса превращать в json
		//мы умеем парсить json
		std::string request = "https://api.binance.com/api/v3/ticker/bookTicker?symbol=" + symbol;
		json11::Json response_json = Rest::Http::SendRequestAndGetResponseAsJson(request);

		// ак синхронизировать по времени.  ак за 1 запрос получить два и более типа данных валидных в единицу времени 

		Rest::Objects::BestsOneInstrument bests(response_json, CommonFunctions::GetCurrentTimeMilliseconds());

		return bests;
		/*
		{
			"symbol"  :"BTCUSDT",
			"bidPrice":"38511.67000000",
			"bidQty"  :"0.71236000",
			"askPrice":"38511.68000000",
			"askQty"  :"0.05721000"
		}
		symbols=["BTCUSDT","BNBBTC"]
		*/
	}

	std::map<std::string, Rest::Objects::BestsOneInstrument> GetCurrentBestsMultiplyInstruments(std::vector<std::string> symbols)
	{
		//https://api.binance.com/api/v3/ticker/bookTicker?symbols=\[\"BTCUSDT\",\"BNBBTC\"\]

		std::string request = "https://api.binance.com/api/v3/ticker/bookTicker?symbols=\\[\\\"";
		
		for (int i = 0; i<symbols.size(); ++i)
		{
			request.append(symbols[i]);
			if (i != symbols.size() - 1)
			{
				request.append("\\\",\\\"");
			}
		}
		request.append("\\\"\\]");
		
		json11::Json response_json = Rest::Http::SendRequestAndGetResponseAsJson(request);
		//std::cout << response_json.dump() << std::endl;

		std::chrono::milliseconds current_time = CommonFunctions::GetCurrentTimeMilliseconds();

		std::map< std::string, Rest::Objects::BestsOneInstrument> tmp_result;

		for (auto one_instrument_bests_json : response_json.array_items())
		{
			tmp_result.emplace(one_instrument_bests_json["symbol"].string_value(), Rest::Objects::BestsOneInstrument(one_instrument_bests_json, current_time));
		}
		
		return tmp_result;
		/*
		[
			{
				"askPrice": "0.01022800",
				"askQty": "22.56700000",
				"bidPrice": "0.01022700",
				"bidQty": "39.64500000",
				"symbol": "BNBBTC"
			},
			{
				"askPrice": "33536.27000000",
				"askQty": "1.80223000",
				"bidPrice": "33536.26000000",
				"bidQty": "12.97005000",
				"symbol": "BTCUSDT"
			}
		]
		*/
	}
	
	//https://api.binance.com/api/v3/klines?symbol=BTCUSDT&interval=1m&startTime=1652054400000&endTime=1652054460000
	//интервал принимает значение 
	//1m 3m 5m 15m 30m 1h 2h 4h	6h 8h 12h 1d 3d	1w 1M

	std::vector<Rest::Objects::KlineOneInstrument> GetKline(std::string symbol, std::string interval, std::chrono::milliseconds start_time, std::chrono::milliseconds end_time)
	{
		//формирование запроса
		//—ишный и питоновский вариант записи - std::string request = fmt::format("https://api.binance.com/api/v3/klines?symbol={}&interval={}&startTime={}&endTime={}" , symbol , interval , start_time.count() , end_time.count());
		std::string request = "https://api.binance.com/api/v3/klines?symbol=" + symbol + "&interval=" + interval + "&startTime=" + std::to_string(start_time.count()) + "&endTime=" + std::to_string(end_time.count());
		//std::cout << request << std::endl;
		
		//посылка запроса
		json11::Json response_json = Rest::Http::SendRequestAndGetResponseAsJson(request);
		
		//std::cout << response_json.dump() << std::endl;

		//парсинг ответа
		std::vector<Rest::Objects::KlineOneInstrument> kline_vec;
		for (json11::Json one_kline_json : response_json.array_items())
		{
			kline_vec.emplace_back(one_kline_json);
		}
		
		return kline_vec;

		/*
		[
			[
				1652054400000,		// 0   Open time
				"34038.39000000",	// 1   Open
				"34113.05000000",	// 2   High
				"34038.39000000",	// 3   Low
				"34100.00000000",	// 4   Close
				"85.32290000",		// 5   Volume
				1652054459999,		// 6   Close time
				"2907188.86066760",	// 7   Quote asset volume
				1086,				// 8   Number of trades
				"51.28593000",		// 9   Taker buy base asset volume
				"1747345.12864030",	// 10  Taker buy quote asset volume
				"0"					// 11  Ignore.
			],
			[
				1652054460000,
				"34099.99000000",
				"34105.92000000",
				"34059.28000000",
				"34078.60000000",
				"24.19280000",
				1652054519999,
				"824605.63166400",
				615,
				"7.73977000",
				"263813.76332600",
				"0"
			]
		]

		User avatar
		level 1
		Palmke86
		Ј
		4 yr. ago
		Taker buy means the buyer is the taker and seller is the maker.
		
		Base asset means the quantity is expressed as the amount of coins that were received by the buyer 
		(as opposed to quote asset which would be the amount paid by the buyer in btc/eth/usdt, depending on the market)
		
		'Volume' is the total amount of traded coins in the timeframe, disregarding which side is the taker
		
		So basically to calculate maker buy volume (or taker sell, which is the same):
		
		'Volume' - ' Taker buy base asset volume' = ' Maker buy base asset volume'
		
		------------------------
		
		The Maker is the person who puts an order in the orderbook. Taker is the one that matches an existing order.
		
		An order goes through immediately once a match can be made, so there is always a maker and a taker. Even when both are using Limit orders. 
		The one that comes second gets matched immediately, therefore his/her order never gets in the book and he/she is a taker.



		*/
	}
}