/**
 * @file tests.cpp
 *
 * Unit tests for quadratic equation
*/

#include "quadratic.h"

/**
 * @brief Checks if two double numbers that can be NAN is equal.
 * @param data checking double number
 * @param answer correct double number
 * @return are two double numbers equal
 */
bool equalNan(double data, double answer)
{
    if (isnan(answer))
        return isnan(data);
    if (isnan(data))
        return false;
    return abs(data - answer) < eps;
}

/**
 * @brief Check if two Solution structures are equal
 * @param solution checking Solution struct
 * @param correctSolution correct Solution struct
 * @return are two Solution structures equal
 */
bool equalSolutions(const Solution *solution,
                    const Solution *correctSolution)
{
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

/**
 * @brief Test function for test function solve(Equation *equation, Solution *solution)
 * @param equation struct with fields a, b, c
 * @param correctSolution structure for storing correct quadratic equation solution
 * @return does function solve works correct
 */
bool testSolve(Equation *equation, Solution *correctSolution)
{
    Solution solution = {};
    solve(equation, &solution);
    return equalSolutions(&solution, correctSolution);
}

int main()
{
    const int num_test = 5;
    Equation equation[num_test] = {{1, 6, 9},
                                   {0, 5, 1},
                                   {0, 0, 1},
                                   {0, 0, 0},
                                   {2, 10, 12},
    };
    Solution correctSolution[num_test] = {
        {-3, NAN, oneSolution},
        {-0.2, NAN, oneSolution},
        {NAN, NAN, noRoots},
        {NAN, NAN, infSolutions},
        {-3, -2, twoSolutions},
    };
    int failed=0;
    for (int i = 0; i < num_test; i++)
    {
        if (testSolve(&equation[i], &correctSolution[i]))
        {
            printf("Test %d: passed\n", i);
        }
        else
        {
            printf("Test %d: failed\n", i);
            failed+=1;
        }
    }
    printf("Failed tests: %d\n", failed);

    return 0;
}