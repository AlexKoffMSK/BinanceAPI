#pragma once
#include "ExecutionFunctions.h"
#include "../Rest/RestApi.h"

namespace ExecutionFunctions
{
    void GetBests()
    {
        while (true)
        {
            //RestApiHelper::GetCurrentBests("BTCUSDT").Print();
            //auto bests = RestApiHelper::GetCurrentBestsMultiplyInstruments({ "BTCUSDT", "BNBBTC" });
            auto all_instruments_bests = Rest::GetCurrentBestsMultiplyInstruments({ "BTCUSDT", "ETHUSDT", "BNBUSDT" });
            for (auto [symbol, bests] : all_instruments_bests)
            {
                std::cout << '[' << symbol << ']';
                bests.Print();
            }

            std::cout << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(50)); //бинанс дает максимальную частоту без бана - 50 запросов в 1 миллисекунду
        }
    }

    void GetKLines()
    {
        //https://api.binance.com/api/v3/klines?symbol=BTCUSDT&interval=1m&startTime=1652054400000&endTime=1652054460000
        std::vector<Rest::Objects::KlineOneInstrument> klines = Rest::GetKline("BTCUSDT", "1m", 1652054400000ms, 1652058200000ms);
        for (Rest::Objects::KlineOneInstrument kl : klines)
        {
            kl.Print();
        }
    }

}
