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

int equalSolutions(const Solution *solution,
                    const Solution *correctSolution, bool *answer)
{
    if (solution == nullptr) return 31;
    if (correctSolution == nullptr) return 32;

    *answer = solution->rootCount == correctSolution->rootCount &&
        ((equalNan(solution->x1, correctSolution->x1) &&
            equalNan(solution->x2, correctSolution->x2)) ||
            (equalNan(solution->x1, correctSolution->x2) &&
                equalNan(solution->x2, correctSolution->x1))
        );
    return 0;
}

int printSolutionAndAnswer(const Solution *solution,
                            const Solution *correctSolution)
{
    if (solution == nullptr) return 31;
    if (correctSolution == nullptr) return 32;
    printf("Answer: %d, Expected: %d\n",
           solution->rootCount,
           correctSolution->rootCount);
    printf("Answer: %lg, Expected: %lg\n",
           solution->x1,
           correctSolution->x1);
    printf("Answer: %lg, Expected: %lg\n",
           solution->x2,
           correctSolution->x2);
    return 0;
}

int testSolveQuadratic(const Test *test, Solution *solution, bool *answer)
{
    if (test == nullptr) return 31;
    if (solution == nullptr) return 32;

    const Equation *equation = &test->equation;

    int errorCode = solveQuadratic(equation, solution);
    if (errorCode != 0) return errorCode;

    const Solution *correctSolution = &test->solution;

    errorCode = equalSolutions(solution, correctSolution, answer);
    return errorCode;
}

int runTests(const Test tests[], const size_t len)
{
    size_t failed = 0;
    int errorCode = 0;
    for (size_t i = 0; i < len; i++)
    {
        Solution solution = {};
        bool passed = false;
        errorCode = testSolveQuadratic(&tests[i], &solution, &passed);
        if (errorCode!=0) return errorCode;
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
            errorCode = printSolutionAndAnswer(&solution,
                                   &tests[i].solution);
            failed++;
            if (errorCode!=0) return errorCode;
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
    return errorCode;
}
