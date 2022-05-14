#include <iostream>
#include <string>
#include <chrono>
#include "ExecutionFunctions/ExecutionFunctions.h"

int main(void)
{
    //auto json = json11::ReadJsonFromString(response_from_rest); //формируем json из строки на основе встроенного парсера

    //"curl https://api.binance.com/api/v3/time" запрос отправляется через встроенную в windows функцию curl пробел !установленный формат запроса!
    //формируем json на основе встроенного парсера
    //auto response_json = Rest::SendRequestAndGetResponseAsJson("curl https://api.binance.com/api/v3/time");
   
    //uint64_t server_time_int = response_json["serverTime"].number_value();
    //std::cout << server_time_int << std::endl;

    //uint64_t our_current_time_ns = std::chrono::system_clock::now().time_since_epoch().count();
    //uint64_t our_current_time_ms = our_current_time_ns / 1000000ULL;// -3ULL * 60 * 60 * 1000;

    //std::cout << our_current_time_ms - server_time_int << std::endl;
    //std::cout << our_current_time_ms << std::endl;
    //std::cout << our_current_time_ns << std::endl;
    //std::cout << time(0) << std::endl;
    //std::cout << server_time_int << std::endl;
    
    //GeteBests();
    ExecutionFunctions::GetKLines();
}

//static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
//{
//    ((std::string*)userp)->append((char*)contents, size * nmemb);
//    return size * nmemb;
//}
    /*CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://www.google.com");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        std::cout << readBuffer << std::endl;
    }
    return 0;*/
/*
 -d, --data <data>   HTTP POST data
 -f, --fail          Fail silently (no output at all) on HTTP errors
 -h, --help <category>  Get help for commands
 -i, --include       Include protocol response headers in the output
 -o, --output <file>  Write to file instead of stdout
 -O, --remote-name   Write output to a file named as the remote file
 -s, --silent        Silent mode
 -T, --upload-file <file>  Transfer local FILE to destination
 -u, --user <user:password>  Server user and password
 -A, --user-agent <name>  Send User-Agent <name> to server
 -v, --verbose       Make the operation more talkative
 -V, --version       Show version number and quit
*/