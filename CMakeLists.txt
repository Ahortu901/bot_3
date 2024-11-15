cmake_minimum_required(VERSION 3.10)

project(AI_Trading_System)

set(CMAKE_CXX_STANDARD 11)

# Include TensorFlow
include_directories(/path/to/tensorflow/include)
link_directories(/path/to/tensorflow/lib)

# Include libcurl
find_package(CURL REQUIRED)

# Add source files
add_executable(ai_trading_system
    src/main.cpp
    src/data_preprocessing.cpp
    src/model_inference.cpp
    src/trading_logic.cpp
    src/market_data.cpp
)

# Link libraries
target_link_libraries(ai_trading_system
    tensorflow_cc
    curl
)
