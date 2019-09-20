cmake_minimum_required(VERSION 3.14)
project(chrono)

set(CMAKE_CXX_STANDARD 11)

add_executable(chrono main.cpp Clock.cpp Clock.h Timer.cpp Timer.h)