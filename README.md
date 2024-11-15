# AI-Based Trading System in C++

This project is an AI-based trading system developed in C++ that uses deep learning to predict market trends and execute trades. The system integrates with market data APIs (e.g., Alpaca) to fetch real-time data, preprocess it, and feed it into a deep learning model to make predictions.

## File Structure

- **src/main.cpp**: The main entry point for the trading system.
- **src/data_preprocessing.cpp**: Processes market data to generate technical indicators.
- **src/model_inference.cpp**: Loads and uses a pre-trained model for predictions.
- **src/trading_logic.cpp**: Core trading strategy (buy/sell) and risk management.
- **src/market_data.cpp**: Fetches market data from external APIs.

## Prerequisites

1. Install CMake (version 3.10+).
2. Install TensorFlow C++ API.
3. Install libcurl (for market data API interaction).
4. Configure API keys in `config/config.json`.

## Building the Project

1. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/AI_Trading_System.git
   cd AI_Trading_System

2. Install dependencies (TensorFlow, libcurl, etc.) based on your system.

3. Run the following command to build the project:

```bash
cmake .
make
```

4. The executable will be created as ``ai_trading_system``.

## Running the System

After building the project, run the system with:

```bash
./ai_trading_system
```
This will start fetching market data, running predictions with the trained model, and executing trades.