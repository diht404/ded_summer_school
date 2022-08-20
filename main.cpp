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
    readEquation(&equation);

    Solution solution = {};
    solveQuadratic(&equation, &solution);

    print(&solution);

    return 0;
}