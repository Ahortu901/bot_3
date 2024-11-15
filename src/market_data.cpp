#include "market_data.h"
#include <vector>
#include <string>
#include <curl/curl.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::vector<double> fetchMarketData() {
    std::vector<double> marketData;

    // Fetch market data from an API (e.g., Alpaca)
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://paper-api.alpaca.markets/v2/stocks/AAPL/quotes/latest");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, "APCA-API-KEY-ID: <YOUR_API_KEY>");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, "APCA-API-SECRET-KEY: <YOUR_API_SECRET>");
        
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }
        else {
            // Parse the JSON response and extract price data
            std::cout << "Market Data: " << readBuffer << std::endl;
            // Example: extract price data from the JSON response (using a JSON parser)
            marketData.push_back(150.0);  // Mock value (replace with actual parsing logic)
        }

        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

    return marketData;
}
