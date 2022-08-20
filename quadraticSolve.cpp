/**
 * @file solve.cpp
 * @author diht404
 * @date 08.20.2022
 *
 * @brief File for functions for solving a quadratic equation
 */

#include "quadratic.h"

void solveQuadratic(Equation *equation, Solution *solution)
{
    assert(equation != nullptr);
    assert(solution != nullptr);
    double a = equation->a;
    double b = equation->b;
    double c = equation->c;

    if (abs(a) < eps)
    {
        solveLinear(equation, solution);
        return;
    }

    // quadratic equation
    double D = b * b - 4 * a * c;
    if (abs(D) < eps)
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
}

void solveLinear(Equation *equation, Solution *solution)
{
    assert(equation != nullptr);
    assert(solution != nullptr);
    double a = equation->a;
    double b = equation->b;
    double c = equation->c;
    if (abs(b) < eps)
    {
        // equation like c=0
        if (abs(c) < eps)
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
}