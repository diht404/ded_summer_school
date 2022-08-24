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
    readEquation(&equation, &error);
    if (error)
    {
        processError(error);
        return EXIT_FAILURE;
    }
    Solution solution = {};
    solveQuadratic(&equation, &solution, &error);
    if (error) {
        processError(error);
        return EXIT_FAILURE;
    }

    print(&solution, &error);
    if (error) {
        processError(error);
        return EXIT_FAILURE;
    }

    return 0;
}
