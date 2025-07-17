cmake_minimum_required(VERSION 3.10)
project(LightweightEncryptor)

# Use modern C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include header files
include_directories(include)

# Add all .cpp files from src folder
file(GLOB SRC_FILES "src/*.cpp")

# Define the main executable
add_executable(encryptor main.cpp ${SRC_FILES})