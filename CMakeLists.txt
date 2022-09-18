cmake_minimum_required(VERSION 3.23)
project(ded_summer_school C CXX)

set(CMAKE_C_STANDARD 99)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -D_DEBUG -D_EJUDGE_CLIENT_SIDE")

add_executable(main_quadratic quadratic/main.cpp quadratic/quadraticUtils.cpp quadratic/quadraticSolve.cpp quadratic/utils.cpp)
add_executable(tests_quadratic quadratic/tests.cpp quadratic/quadraticSolve.cpp quadratic/testUtils.cpp quadratic/utils.cpp)
add_executable(string_functions string_functions/main.cpp string_functions/utils.cpp)
add_executable(onegin onegin/onegin.cpp onegin/utils.cpp)