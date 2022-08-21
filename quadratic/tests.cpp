/**
 * @file tests.cpp
 *
 * Unit tests for quadratic equation
*/

#include "testUtils.h"

int main()
{
    Test tests[] =
        {
            {1, 6, 9, -3, NAN, oneSolution},
            {0, 5, 1, -0.2, NAN, oneSolution},
            {0, 0, 1, NAN, NAN, noRoots},
            {0, 0, 0, NAN, NAN, infSolutions},
            {2, 10, 12, -3, -2, twoSolutions},
        };

    runTests(tests, sizeof(tests) / sizeof(Test));

    return 0;
}

bool equalNan(double data, double answer)
{
    if (isnan(answer))
        return isnan(data);
    return equalZero(data-answer);
}

bool equalSolutions(const Solution *solution,
                    const Solution *correctSolution)
{
    assert(solution != nullptr);
    assert(correctSolution != nullptr);

    bool answer = equalNan(solution->x1, correctSolution->x1) and
        equalNan(solution->x2, correctSolution->x2) and
        solution->rootCount == correctSolution->rootCount;
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
    Solution *correctSolution = &test->solution;
    Solution solution = {};
    if (!isnan(correctSolution->x2))
    {
        if (abs(correctSolution->x1 - correctSolution->x2) < eps)
        {
            // if there is two equal answers in the test
            // makes second equals NAN
            correctSolution->x2 = NAN;
        }
        else if (correctSolution->x1 > correctSolution->x2)
        {
            // x1<x2, swap them if test does not know about it
            double tmp = correctSolution->x2;
            correctSolution->x2 = correctSolution->x1;
            correctSolution->x1 = tmp;
        }
    }

    solveQuadratic(equation, &solution);
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
