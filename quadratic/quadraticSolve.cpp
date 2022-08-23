/**
 * @file solve.cpp
 * @author diht404
 * @date 08.20.2022
 *
 * @brief File for functions for solving a quadratic equation
 */

#include "quadratic.h"

int solveQuadratic(const Equation *equation, Solution *solution)
{
    if (equation == nullptr) return 31;
    if (solution == nullptr) return 32;

    int errorCode = 0;

    double a = equation->a;
    double b = equation->b;
    double c = equation->c;

    if (isinf(a)) return 11;
    if (isinf(b)) return 12;
    if (isinf(c)) return 13;

    if (isnan(a)) return 21;
    if (isnan(b)) return 22;
    if (isnan(c)) return 23;

    if (equalZero(a))
    {
        errorCode = solveLinear(equation, solution);
        return errorCode;
    }

    // quadratic equation
    double D = b * b - 4 * a * c;
    if (equalZero(D))
    {
        solution->rootCount = oneSolution;
        solution->x1 = -b / (2 * a);
    }
    else if (D < 0)
    {
        solution->rootCount = noRoots;
    }
    else
    {
        solution->rootCount = twoSolutions;
        solution->x1 = (-b - sqrt(D)) / (2 * a);
        solution->x2 = (-b + sqrt(D)) / (2 * a);
    }
    return errorCode;
}

int solveLinear(const Equation *equation, Solution *solution)
{
    if (equation == nullptr) return 31;
    if (solution == nullptr) return 32;

    int errorCode = 0;

    double b = equation->b;
    double c = equation->c;

    if (isinf(b)) return 12;
    if (isinf(c)) return 13;

    if (isnan(b)) return 22;
    if (isnan(c)) return 23;

    if (equalZero(b))
    {
        // equation like c = 0
        if (equalZero(c))
        {
            solution->rootCount = infSolutions;
        }
        else
        {
            solution->rootCount = noRoots;
        }
    }
    else
    {
        solution->x1 = -c / b;
        solution->rootCount = oneSolution;
    }
    return errorCode;
}

bool equalZero(double number)
{
    return abs(number) < eps;
}
