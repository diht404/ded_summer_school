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
    assert(equation != nullptr);
    assert(solution != nullptr);

    int error = NO_ERRORS;

    double a = equation->a;
    double b = equation->b;
    double c = equation->c;

    if (isnan(a) || isnan(b) || isnan(c))
        return NAN_VALUE;
    if (isinf(a) || isinf(b) || isinf(c))
        return INF_VALUE;

    if (equalZero(a))
    {
        error = solveLinear(equation, solution);
        return error;
    }

    if (equalZero(c))
    {
        Equation new_equation = {0, equation->a, equation->b};
        error = solveLinear(equation, solution);
        solution->rootCount = twoSolutions;
        if (solution->x1>0)
        solution->x2 = solution->x1;
        solution->x1;
        return error;
    }
    // c=0 -linear
    // b=0 - +-
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
    assert(equation != nullptr);
    assert(solution != nullptr);

    int error = NO_ERRORS;

    double b = equation->b;
    double c = equation->c;

    if (isnan(b) || isnan(c))
        return NAN_VALUE;
    if (isinf(b) || isinf(c))
        return INF_VALUE;

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
    return abs(number) < Eps;
}
