/**
 * @file quadratic.cpp
 * @author diht404
 * @date 08.20.2022
 *
 * @brief The main file for solving quadratic equations
 */

#include "quadratic.h"

/**
 * @brief main function for quadratic equation solution
 * @return 0
 */
int main()
{
    int error = NO_ERRORS;

    Equation equation = {};
    error = readEquation(&equation);
    if (error)
    {
        processError(error);
        return EXIT_FAILURE;
    }

    Solution solution = {};
    error = solveQuadratic(&equation, &solution);
    if (error)
    {
        processError(error);
        return EXIT_FAILURE;
    }

    error = print(&solution);
    if (error)
    {
        processError(error);
        return EXIT_FAILURE;
    }

    return 0;
}
