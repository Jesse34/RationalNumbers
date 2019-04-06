cmake_minimum_required(VERSION 3.8)
project(RationalNumbers)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Rational.cpp Rational.h)
add_executable(RationalNumbers ${SOURCE_FILES})