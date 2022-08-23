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
    if (equation == nullptr) return NULL_FIRST;
    if (solution == nullptr) return NULL_SECOND;

    int error = NO_ERRORS;

    double a = equation->a;
    double b = equation->b;
    double c = equation->c;

    if (isinf(a)) return INF_FIRST;
    if (isinf(b)) return INF_SECOND;
    if (isinf(c)) return INF_THIRD;

    if (isnan(a)) return INF_FIRST;
    if (isnan(b)) return INF_SECOND;
    if (isnan(c)) return INF_THIRD;

    if (equalZero(a))
    {
        error = solveLinear(equation, solution);
        return error;
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
    return error;
}

int solveLinear(const Equation *equation, Solution *solution)
{
    if (equation == nullptr) return NULL_FIRST;
    if (solution == nullptr) return NULL_SECOND;

    int error = NO_ERRORS;

    double b = equation->b;
    double c = equation->c;

    if (isinf(b)) return INF_SECOND;
    if (isinf(c)) return INF_THIRD;

    if (isnan(b)) return NAN_SECOND;
    if (isnan(c)) return NAN_THIRD;

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
    return error;
}

bool equalZero(double number)
{
    return abs(number) < eps;
}
