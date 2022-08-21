/**
 * @file testUtils.cpp
 *
 * Implementation of functions for unit tests from testUtils.h
 */

#include "testUtils.h"

bool equalNan(double data, double answer)
{
    if (isnan(answer))
        return isnan(data);
    return equalZero(data - answer);
}

bool equalSolutions(const Solution *solution,
                    const Solution *correctSolution)
{
    assert(solution != nullptr);
    assert(correctSolution != nullptr);

    bool answer = solution->rootCount == correctSolution->rootCount &&
        (equalNan(solution->x1, correctSolution->x1) &&
            equalNan(solution->x2, correctSolution->x2)) ||
        (equalNan(solution->x1, correctSolution->x2) &&
            equalNan(solution->x2, correctSolution->x1));
    if (not answer)
    {
        printf("Answer: %lf, Expected: %lf\n",
               solution->x1,
               correctSolution->x1);
        printf("Answer: %lf, Expected: %lf\n",
               solution->x2,
               correctSolution->x2);
        printf("Answer: %d, Expected: %d\n",
               solution->rootCount,
               correctSolution->rootCount);
    }
    return answer;
}

bool testSolve(Test *test)
{
    assert(test != nullptr);

    Equation *equation = &test->equation;
    Solution solution = {};

    solveQuadratic(equation, &solution);
    Solution *correctSolution = &test->solution;

    return equalSolutions(&solution, correctSolution);
}

void runTests(Test tests[], size_t len)
{
    size_t failed = 0;
    size_t passed = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (testSolve(&tests[i]))
        {
            printf("%sTest №%zu: passed.", ANSI_COLOR_GREEN, i);
            printf("Info about equation: %lf*x^2+%lf*x+%lf=0%s\n",
                   tests[i].equation.a,
                   tests[i].equation.b,
                   tests[i].equation.c, ANSI_COLOR_RESET);
            passed += 1;
        }
        else
        {
            printf("%sTest №%zu: failed.", ANSI_COLOR_RED, i);
            printf("Info about equation: %lf*x^2+%lf*x+%lf=0%s\n",
                   tests[i].equation.a,
                   tests[i].equation.b,
                   tests[i].equation.c,
                   ANSI_COLOR_RESET);
            failed += 1;
        }
    }
    printf("%sPassed tests: %zu/%zu%s\n",
           ANSI_COLOR_GREEN,
           passed,
           passed + failed,
           ANSI_COLOR_RESET);
    if (failed)
        printf("%sFailed tests: %zu/%zu%s\n",
               ANSI_COLOR_RED,
               failed,
               passed + failed,
               ANSI_COLOR_RESET);
}