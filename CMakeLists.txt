cmake_minimum_required(VERSION 3.23)
project(ded_summer_school C CXX)

set(CMAKE_C_STANDARD 99)

add_executable(quadratic quadratic.cpp solve.cpp quadratic.h)
add_executable(tests_quadratic tests.cpp solve.cpp quadratic.h)