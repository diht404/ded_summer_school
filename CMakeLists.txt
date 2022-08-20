cmake_minimum_required(VERSION 3.23)
project(ded_summer_school C CXX)

set(CMAKE_C_STANDARD 99)

add_executable(main quadratic/main.cpp quadratic/quadraticUtils.cpp quadratic/quadraticSolve.cpp)
add_executable(tests_quadratic quadratic/tests.cpp quadratic/quadraticSolve.cpp)