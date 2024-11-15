#include "data_preprocessing.h"
#include <vector>
#include <iostream>

// Preprocess market data into technical indicators (e.g., moving average, RSI)
std::vector<double> preprocessData(const std::vector<double>& prices) {
    std::vector<double> features;
    double movingAverage = 0.0;

    // Simple moving average for the last 5 prices
    int window = 5;
    for (int i = 0; i < prices.size(); ++i) {
        if (i >= window - 1) {
            double sum = 0.0;
            for (int j = i - window + 1; j <= i; ++j) {
                sum += prices[j];
            }
            movingAverage = sum / window;
            features.push_back(movingAverage);
        }
    }

    // Add other technical indicators as needed (e.g., RSI, MACD)
    return features;
}
