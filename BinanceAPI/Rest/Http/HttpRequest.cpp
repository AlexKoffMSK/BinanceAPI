#pragma once
#include "HttpRequest.h"
#include "../../Constants/FileNames.h"

namespace Rest::Http
{
	std::string ReadFileAndReturnString(std::string filename_to_read_from)
	{
		//std::ifstream ifs;
		//ifs.open(filename);

		std::ifstream ifs(filename_to_read_from);
		if (!ifs.is_open())
		{
			return "";
		}

		std::string str;
		while (!ifs.eof())
		{
			str.push_back(ifs.get());
		}
		return str;
	}

	std::string SendRequestAndGetResponse(std::string request)
	{
		//std::system(request.c_str());
		//std::system("echo %cd%");
		
		//" > " - это команда записи результата командной строки в файл. Обязательно пробелы вокруг и следом путь и имя файла.
		// 2> nul - это убрать неосновной вывод в мусорку, а 1> - отправить основной вывод в файл
		//request += (" 2> nul 1> " + temp_file_for_response);
		request += (" 1> " + FileNames::kTempFileForResponse + " 2> nul");
		
		std::system(request.c_str());

		return ReadFileAndReturnString(FileNames::kTempFileForResponse);
	}

	json11::Json SendRequestAndGetResponseAsJson(std::string request)
	{
		std::string full_request = "curl \"" + request + "\" 1> " + FileNames::kTempFileForResponse + " 2> nul";
		
		//std::cout << full_request << std::endl;
		
		std::system(full_request.c_str());

		std::system((std::string("type ") + FileNames::kTempFileForResponse + " >> " + FileNames::kRestResponseHistory).c_str());
		
		std::system((std::string("echo , >> ") + FileNames::kRestResponseHistory).c_str());

		auto response_json = json11::ReadJsonFromFile(FileNames::kTempFileForResponse);
		
		return response_json;
	}

	//1651449600000
	//1651536000000

	/*
	история
	[
	[
    1499040000000,      // Open time
    "0.01634790",       // Open
    "0.80000000",       // High
    "0.01575800",       // Low
    "0.01577100",       // Close
    "148976.11427815",  // Volume
    1499644799999,      // Close time
    "2434.19055334",    // Quote asset volume
    308,                // Number of trades
    "1756.87402397",    // Taker buy base asset volume
    "28.46694368",      // Taker buy quote asset volume
    "17928899.62484339" // Ignore.
	]
	]
	
	
	
	
	*/
}