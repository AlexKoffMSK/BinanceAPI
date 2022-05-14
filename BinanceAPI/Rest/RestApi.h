#pragma once
#include <string>
#include <iomanip>
#include <chrono>
#include <vector>
#include "../Rest/Objects/BestOneInstrument.h"
#include "../Rest/Objects/KlineOneInstrument.h"

namespace Rest
{
	Rest::Objects::BestsOneInstrument GetCurrentBests(std::string symbol);
	std::map<std::string, Rest::Objects::BestsOneInstrument> GetCurrentBestsMultiplyInstruments(std::vector<std::string> symbols);
	std::vector<Rest::Objects::KlineOneInstrument> GetKline(std::string symbol, std::string interval, std::chrono::milliseconds start_time, std::chrono::milliseconds end_time);
}