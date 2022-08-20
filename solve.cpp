/**
 * @file solve.cpp
 *
 * File for quadratic equation solution functions
 */

#include "quadratic.h"

void solve(Equation *equation, Solution *solution)
{
    double a = equation->a;
    double b = equation->b;
    double c = equation->c;

    if (abs(a) < eps)
    {
        // linear equation
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