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
bool equalSolutions(const Solution *solution,
                   const Solution *correctSolution,
                   int *error = nullptr);

/**
 * @brief Test function for test function solve(Equation *equation, Solution *solution)
 * @param Test struct with fields Equation equation and Solution correctSolution
 * @param error error code: nullptr if don't process errors or pointer if need to process errors
 * @return does function works correct
 */
bool testSolveQuadratic(const Test *test, Solution *solution, int *error = nullptr);

/**
 * @brief prints solution and correct answer
 * @param solution checking Solution struct
 * @param correctSolution correct Solution struct
 * @param error error code: nullptr if don't process errors or pointer if need to process errors
 * @return void
 */
void printSolutionAndAnswer(const Solution *solution,
                            const Solution *correctSolution,
                            int *error = nullptr);

/**
 * @brief Tests program
 * @param tests array of test data
 * @param length number of tests
 * @param error error code: nullptr if don't process errors or pointer if need to process errors
 *
 * @return void
 */
void runTests(const Test tests[], size_t length, int *error = nullptr);

/**
 * @brief prints given equation
 * @param equation equation for print
 * @param error error code: nullptr if don't process errors or pointer if need to process errors
 *
 * @return void
 */
void printEquation(const Equation *equation, int *error = nullptr);

