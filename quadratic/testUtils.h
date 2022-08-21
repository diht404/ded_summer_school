/**
 * @file testUtils.h
 * @author diht404
 * @date 08.20.2022
 *
 * Utils file for unit tests
 */
#include "quadratic.h"

struct Test
{
    Equation equation = {};
    Solution solution = {};
};

/**
 * @brief Checks if two double numbers that can be NAN is equal.
 * @param data checking double number
 * @param answer correct double number
 * @return are two double numbers equal
 */
bool equalNan(double data, double answer);

/**
 * @brief Check if two Solution structures are equal
 * @param solution checking Solution struct
 * @param correctSolution correct Solution struct
 * @return are two Solution structures equal
 */
bool equalSolutions(const Solution *solution,
                    const Solution *correctSolution);

/**
 * @brief Test function for test function solve(Equation *equation, Solution *solution)
 * @param Test struct with fields Equation equation and Solution correctSolution
 * @return does function solve works correct
 */
bool testSolve(Test *test);

/**
 * @brief Tests program
 * @param tests array of test data
 * @param len number of tests
 * @return void
 */
void runTests(Test tests[], size_t len);
