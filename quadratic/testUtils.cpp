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
    printf("Answer: %lg, Expected: %lg\n",
           solution->x1,
           correctSolution->x1);
    printf("Answer: %lg, Expected: %lg\n",
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
        bool passed = testSolveQuadratic(&tests[i], &solution);

        printf("Test №%zu: %s%s%s. ", i,
               passed ? ANSI_COLOR_GREEN : ANSI_COLOR_RED,
               passed ? "PASSED" : "FAILED",
               ANSI_COLOR_RESET);

        printf("Info about equation: %lgx^2 + %lgx + %lg = 0\n",
               tests[i].equation.a,
               tests[i].equation.b,
               tests[i].equation.c);

        if (!passed)
        {
            printSolutionAndAnswer(&solution,
                                   &tests[i].solution);
            failed++;
        }
    }
    printf("Passed tests: %s%zu/%zu%s\n",
           ANSI_COLOR_GREEN,
           len - failed,
           len,
           ANSI_COLOR_RESET);
    if (failed)
        printf("Failed tests: %s%zu/%zu%s\n",
               ANSI_COLOR_RED,
               failed,
               len,
               ANSI_COLOR_RESET);
}
