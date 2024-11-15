#include "trading_logic.h"
#include <iostream>

void placeTrade(const std::vector<double>& predictions, double currentPrice) {
    double stopLossPercentage = 0.02;  // 2% stop-loss
    double takeProfitPercentage = 0.04;  // 4% take-profit

    double stopLossPrice = currentPrice * (1 - stopLossPercentage);
    double takeProfitPrice = currentPrice * (1 + takeProfitPercentage);

    // Example: if model predicts price will go up
    if (predictions[0] > 0.5) {
        std::cout << "Placing buy order at " << currentPrice
                  << ", Stop-loss: " << stopLossPrice
                  << ", Take-profit: " << takeProfitPrice << std::endl;
        // Send buy order logic (using Alpaca, IB API, or other trading APIs)
    } else {
        std::cout << "Placing sell order at " << currentPrice
                  << ", Stop-loss: " << stopLossPrice
                  << ", Take-profit: " << takeProfitPrice << std::endl;
        // Send sell order logic
    }
}
