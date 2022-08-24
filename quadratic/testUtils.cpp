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

//int equalSolutions(const Solution *solution,
//                   const Solution *correctSolution, int *error /* = nullptr */)
//{
//    assert(solution != nullptr);
//    assert(correctSolution != nullptr);
//
//    if (error) *error = NO_ERRORS;
//
//    return solution->rootCount == correctSolution->rootCount &&
//        ((equalNan(solution->x1, correctSolution->x1) &&
//            equalNan(solution->x2, correctSolution->x2)) ||
//            (equalNan(solution->x1, correctSolution->x2) &&
//                equalNan(solution->x2, correctSolution->x1))
//        );
//}

int equalSolutions(const Solution *solution,
                   const Solution *correctSolution, bool *answer)
{
    assert(solution != nullptr);
    assert(correctSolution != nullptr);
    assert(answer != nullptr);

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
    assert(solution != nullptr);
    assert(correctSolution != nullptr);

    printf("Given root count: %d, Expected: %d\n",
           solution->rootCount,
           correctSolution->rootCount);
    printf("Given x1: %lg, Expected: %lg\n",
           solution->x1,
           correctSolution->x1);
    printf("Given x2: %lg, Expected: %lg\n",
           solution->x2,
           correctSolution->x2);

    return NO_ERRORS;
}

int testSolveQuadratic(const Test *test,
                       Solution *solution,
                       bool *answer)
{
    assert(test != nullptr);
    assert(solution != nullptr);
    assert(answer != nullptr);

    const Equation *equation = &test->equation;

    int error = solveQuadratic(equation, solution);
    if (error != NO_ERRORS)
        return error;

    const Solution *correctSolution = &test->solution;

    error = equalSolutions(solution, correctSolution, answer);
    return error;
}

void printEquation(const Equation *equation)
{
    if (!equalZero(equation->a))
    {
        printf("Info about equation: %lgx^2 + %lgx + %lg = 0\n",
               equation->a,
               equation->b,
               equation->c);
        return;
    }

    if (!equalZero(equation->b))
    {
        printf("Info about equation: %lgx + %lg = 0\n",
               equation->b,
               equation->c);
        return;
    }
    printf("Info about equation: %lg = 0\n",
           equation->c);
}

int runTests(const Test tests[], const size_t length)
{
    size_t failed = 0;
    int error = NO_ERRORS;
    for (size_t i = 0; i < length; i++)
    {
        Solution solution = {};
        bool passed = false;

        error = testSolveQuadratic(&tests[i], &solution, &passed);
        if (error) return error;

        printf("Test №%zu: %s%s%s. ", i,
               passed ? ANSI_COLOR_GREEN : ANSI_COLOR_RED,
               passed ? "PASSED" : "FAILED",
               ANSI_COLOR_RESET);
        printEquation(&(tests[i].equation));
        if (!passed)
        {
            error = printSolutionAndAnswer(&solution,
                                           &tests[i].solution);
            if (error) return error;

            failed++;
        }
    }
    printf("Passed tests: %s%zu/%zu%s\n",
           ANSI_COLOR_GREEN,
           length - failed,
           length,
           ANSI_COLOR_RESET);
    if (failed)
        printf("Failed tests: %s%zu/%zu%s\n",
               ANSI_COLOR_RED,
               failed,
               length,
               ANSI_COLOR_RESET);

    return error;
}
