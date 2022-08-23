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
    if (solution == nullptr) return NULL_FIRST;
    if (correctSolution == nullptr) return NULL_SECOND;

    *answer = solution->rootCount == correctSolution->rootCount &&
        ((equalNan(solution->x1, correctSolution->x1) &&
            equalNan(solution->x2, correctSolution->x2)) ||
            (equalNan(solution->x1, correctSolution->x2) &&
                equalNan(solution->x2, correctSolution->x1))
        );
    return NO_ERRORS;
}

int printSolutionAndAnswer(const Solution *solution,
                            const Solution *correctSolution)
{
    if (solution == nullptr) return NULL_FIRST;
    if (correctSolution == nullptr) return NULL_SECOND;
    printf("Answer: %d, Expected: %d\n",
           solution->rootCount,
           correctSolution->rootCount);
    printf("Answer: %lg, Expected: %lg\n",
           solution->x1,
           correctSolution->x1);
    printf("Answer: %lg, Expected: %lg\n",
           solution->x2,
           correctSolution->x2);
    return NO_ERRORS;
}

int testSolveQuadratic(const Test *test, Solution *solution, bool *answer)
{
    if (test == nullptr) return NULL_FIRST;
    if (solution == nullptr) return NULL_SECOND;

    const Equation *equation = &test->equation;

    int errorCode = solveQuadratic(equation, solution);
    if (errorCode != NO_ERRORS) return errorCode;

    const Solution *correctSolution = &test->solution;

    errorCode = equalSolutions(solution, correctSolution, answer);
    return errorCode;
}

int runTests(const Test tests[], const size_t len)
{
    size_t failed = 0;
    int error = NO_ERRORS;
    for (size_t i = 0; i < len; i++)
    {
        Solution solution = {};
        bool passed = false;
        error = testSolveQuadratic(&tests[i], &solution, &passed);
        if (error != NO_ERRORS) return error;
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
            error = printSolutionAndAnswer(&solution,
                                   &tests[i].solution);
            failed++;
            if (error != NO_ERRORS) return error;
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
    return error;
}
