/**
 * @file quadratic.cpp
 * @author diht404
 * @date 08.20.2022
 *
 * @brief Utils file for UI of quadratic equation solution
 */

#include "quadratic.h"

/**
 * @brief Skips symbols from print from UI
 * @param error error code: nullptr if don't process errors or pointer if need to process errors
 *
 * Deletes characters that were printed by the UI helper prompt
 * @return void
 */
static void skipUnusedSymbols(int *error = nullptr);

/**
 * @brief reads one number
 * Reads float number from console
 * if gets not number, print error and try again
 *
 * @param name name of argument
 * @param error error code: nullptr if don't process errors or pointer if need to process errors
 * @return int error code
 */
static double readVariable(const char *name, int *error = nullptr);

static void skipUnusedSymbols(int *error)
{
    int symbol = getchar();

    if (error) *error = NO_ERRORS;

    while (symbol != '\n')
    {
        if (symbol == EOF)
        {
            *error = EOF_ERROR;
            return;
        }
        symbol = getchar();
    }
}

double readVariable(const char *name, int *error)
{
    assert(name != nullptr);

    double param=NAN;

    if (error) *error = NO_ERRORS;

    printf("Enter a coefficient %s:\n", name);

    int correct = scanf("%lf", &param);
    if (!isfinite(param)) correct = 0;
    int readCount = 1;

    while (correct != 1 && readCount < 5)
    {
        printf("Incorrect number, try again!\n");
        skipUnusedSymbols(error);
        if (*error) return param;

        readCount += 1;
        correct = scanf("%lf", &param);
        if (!isfinite(param)) correct = 0;
    }

    if (readCount == 5) *error = TOO_MANY_ATTEMPTS_TO_READ;
    return param;
}

void readEquation(Equation *equation, int *error)
{
    assert(equation != nullptr);

    if (error) *error = NO_ERRORS;

    equation->a = readVariable("a", error);
    if (*error) return;

    equation->b = readVariable("b", error);
    if (*error) return;

    equation->c = readVariable("c", error);
}

void print(const Solution *solution, int *error)
{
    assert(solution != nullptr);

    if (error) *error = NO_ERRORS;

    switch (solution->rootCount)
    {
        case noRoots:
            printf("No real solutions!\n");
            break;
        case infSolutions:
            printf("Any number.\n");
            break;
        case oneSolution:
            printf("x = %lf\n", solution->x1);
            break;
        case twoSolutions:
            printf("x1 = %lf\n", solution->x1);
            printf("x2 = %lf\n", solution->x2);
            break;
        default:
            fprintf(stderr,
                    "Error, Unknown root count %d:\n",
                    solution->rootCount);
            *error = UNKNOWN_ROOT_COUNT;
    }
}