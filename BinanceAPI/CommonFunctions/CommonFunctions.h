#pragma once
#include <chrono>
#include <format>

namespace CommonFunctions
{
	std::chrono::milliseconds GetCurrentTimeMilliseconds();

	std::string CovertStampToHumanDate(std::chrono::milliseconds unix_timestamp);

}