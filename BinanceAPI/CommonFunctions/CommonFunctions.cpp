#include "CommonFunctions.h"

namespace CommonFunctions
{
	std::chrono::milliseconds GetCurrentTimeMilliseconds()
	{
		return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
	}

	std::string CovertStampToHumanDate(std::chrono::milliseconds unix_timestamp)
	{
		int64_t time_stamp = unix_timestamp.count() % (60LL * 60 * 1000 * 24);
		int64_t day = unix_timestamp.count() / (60LL * 60 * 1000 * 24);
		//15 10 00 000 000 000L;
		uint64_t h = time_stamp / (60LL * 60 * 1000);
		uint64_t min = (time_stamp - h * 60 * 60 * 1000) / (60L * 1000);
		uint64_t sec = (time_stamp - h * 60 * 60 * 1000 - min * 60 * 1000) / 1000;
		uint64_t millis = (time_stamp - h * 60 * 60 * 1000 - min * 60 * 1000 - sec * 1000);
		//uint64_t micros = (nanosec - h * 60 * 60 * 1000 - min * 60 * 1000 - sec * 1000 - millis * 1000000) / 1000;
		//uint64_t nanos = (nanosec - h * 60 * 60 * 1000 - min * 60 * 1000 - sec * 1000 - millis * 1000000 - micros * 1000);

		//return std::format("{}:{:02}:{:02}:{:03}:{:03}:{:03}", h, min, sec, millis, micros, nanos);
		return std::format("{} {}:{:02}:{:02}:{:03}", day, h, min, sec, millis);
	}

}
