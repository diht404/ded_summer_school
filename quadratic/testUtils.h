/**
 * @file testUtils.h
 * @author diht404
 * @date 08.20.2022
 *
 * @brief Utils file for unit tests
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
 * @param answer are two Solution structures equal
 * @return error code
 */
int equalSolutions(const Solution *solution,
                   const Solution *correctSolution, bool *answer);

/**
 * @brief Test function for test function solve(Equation *equation, Solution *solution)
 * @param Test struct with fields Equation equation and Solution correctSolution
 * @param answer variable for passed/failed does function works correct
 * @return error code
 */
int testSolveQuadratic(const Test *test,
                       Solution *solution,
                       bool *answer);

/**
 * @brief prints solution and correct answer
 * @param solution checking Solution struct
 * @param correctSolution correct Solution struct
 * @return error code
 */
int printSolutionAndAnswer(const Solution *solution,
                           const Solution *correctSolution);

/**
 * @brief Tests program
 * @param tests array of test data
 * @param length number of tests
 * @return error code
 */
int runTests(const Test tests[], size_t length);
