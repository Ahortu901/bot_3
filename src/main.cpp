#include <iostream>
#include <fstream>
#include "market_data.h"
#include "data_preprocessing.h"
#include "model_inference.h"
#include "trading_logic.h"

int main() {
    // Load configuration files
    std::ifstream config("config/config.json");
    std::ifstream modelConfig("config/model_config.json");

    // Fetch market data (e.g., Alpaca API)
    std::vector<double> marketData = fetchMarketData();
    
    // Preprocess the market data (e.g., calculate technical indicators)
    std::vector<double> features = preprocessData(marketData);

    // Load the trained model and run inference
    std::vector<double> predictions = runModelInference(features);

    // Execute trading strategy based on predictions
    placeTrade(predictions, marketData.back());  // Example: using last market price as current price

    return 0;
}
