/**
 * @file testUtils.cpp
 * @author diht404
 * @date 08.20.2022
 *
 * @brief Implementation of functions for unit tests from testUtils.h
 */

#include "testUtils.h"

bool equalNan(const double data, const double answer)
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

    return solution->rootCount == correctSolution->rootCount &&
        ((equalNan(solution->x1, correctSolution->x1) &&
            equalNan(solution->x2, correctSolution->x2)) ||
            (equalNan(solution->x1, correctSolution->x2) &&
                equalNan(solution->x2, correctSolution->x1))
        );
}

void printSolutionAndAnswer(const Solution *solution,
                            const Solution *correctSolution)
{
    printf("Answer: %d, Expected: %d\n",
           solution->rootCount,
           correctSolution->rootCount);
    printf("Answer: %lf, Expected: %lf\n",
           solution->x1,
           correctSolution->x1);
    printf("Answer: %lf, Expected: %lf\n",
           solution->x2,
           correctSolution->x2);
}

bool testSolveQuadratic(const Test *test, Solution *solution)
{
    assert(test != nullptr);

    const Equation *equation = &test->equation;

    solveQuadratic(equation, solution);
    const Solution *correctSolution = &test->solution;

    return equalSolutions(solution, correctSolution);
}

void runTests(const Test tests[], const size_t len)
{
    size_t failed = 0;

    for (size_t i = 0; i < len; i++)
    {
        Solution solution = {};
        bool flag = testSolveQuadratic(&tests[i], &solution);

        if (!flag)
        {
            printSolutionAndAnswer(&solution,
                                   &tests[i].solution);
            failed++;
        }

        printf("%sTest №%zu: %s. ",
               flag ? ANSI_COLOR_GREEN : ANSI_COLOR_RED,
               i,
               flag ? "passed" : "failed");
        printf("Info about equation: %lf*x^2+%lf*x+%lf=0%s\n",
               tests[i].equation.a,
               tests[i].equation.b,
               tests[i].equation.c,
               ANSI_COLOR_RESET);
    }
    printf("%sPassed tests: %zu/%zu%s\n",
           ANSI_COLOR_GREEN,
           len - failed,
           len,
           ANSI_COLOR_RESET);
    if (failed)
        printf("%sFailed tests: %zu/%zu%s\n",
               ANSI_COLOR_RED,
               failed,
               len,
               ANSI_COLOR_RESET);
}
