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
    Equation equation = {};

    int readErrorCode = readEquation(&equation);
    processError(readErrorCode);
    if (readErrorCode!=0) return readErrorCode;

    Solution solution = {};

    int readErrorSolve = solveQuadratic(&equation, &solution);
    processError(readErrorSolve);
    if (readErrorSolve!=0) return readErrorSolve;

    int printErrorCode = print(&solution);
    processError(printErrorCode);

    return printErrorCode;
}
