/**
 * @file tests.cpp
 * @author diht404
 * @date 08.20.2022
 *
 * @brief Unit tests for quadratic equation
*/

#include "testUtils.h"

int main()
{
    Test tests[] =
        {
            {
                {
                    .a = 1,
                    .b = 6,
                    .c = 9,
                },
                {
                    .x1 = -3,
                    .x2 = NAN,
                    .rootCount = oneSolution
                }
            },
            {
                {
                    .a = 0,
                    .b = 5,
                    .c = 1,
                },
                {
                    .x1 = -0.2,
                    .x2 = NAN,
                    .rootCount = oneSolution,
                }
            },
            {
                {
                    .a = 0,
                    .b = 0,
                    .c = 1,
                },
                {
                    .x1 = NAN,
                    .x2 = NAN,
                    .rootCount = noRoots,
                }
            },
            {
                {
                    .a = 0,
                    .b = 0,
                    .c = 0,
                },
                {
                    .x1 = NAN,
                    .x2 = NAN,
                    .rootCount = infSolutions,
                }
            },
            {
                {
                    .a = 2,
                    .b = 10,
                    .c = 12
                },
                {
                    .x1 = -2,
                    .x2 = -3,
                    .rootCount = twoSolutions,
                }
            },
        };

    int error = runTests(tests, sizeof(tests) / sizeof(Test));
    if (error != NO_ERRORS) {
        processError(error);
        return EXIT_FAILURE;
    }
    return 0;
}
