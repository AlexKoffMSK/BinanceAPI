#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "../../Json/json11.hpp"

namespace Rest::Http
{
	std::string ReadFileAndReturnString(std::string filename_to_read_from);
	std::string SendRequestAndGetResponse(std::string request);
	json11::Json SendRequestAndGetResponseAsJson(std::string request);

}