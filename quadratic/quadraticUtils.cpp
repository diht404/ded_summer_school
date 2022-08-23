/**
 * @file quadratic.cpp
 * @author diht404
 * @date 08.20.2022
 *
 * @brief Utils file for UI of quadratic equation solution
 */

#include "quadratic.h"

int skipUnusedSymbols()
{
    int symbol = getchar();

    while (symbol != '\n')
    {
        if (symbol == EOF)
            return EOF_ERROR;
        symbol = getchar();
    }

    return 0;
}
int readVariable(const char *name, double *param)
{
    assert(name  != nullptr);
    assert(param != nullptr);

    printf("Enter a coefficient %s:\n", name);

    int correct = scanf("%lf", param);
    if (!isfinite(*param)) correct = 0;
    int readCount = 1;
    int error = NO_ERRORS;

    while (correct != 1 && readCount < 5)
    {
        printf("Incorrect number, try again!\n");
        error = skipUnusedSymbols();
        if (error) return error;

        readCount += 1;
        correct = scanf("%lf", param);
        if (!isfinite(*param)) correct = 0;
    }

    if (readCount == 5) error = TOO_MANY_ATTEMPTS_TO_READ;

    return error;
}

int readEquation(Equation *equation)
{
    assert(equation != nullptr);

    int error = readVariable("a", &equation->a);
    if (error) return error;

    error = readVariable("b", &equation->b);
    if (error) return error;

    error = readVariable("c", &equation->c);
    if (error) return error;

    return error;
}

int print(const Solution *solution)
{
    assert(solution != nullptr);

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
            return UNKNOWN_ROOT_COUNT;
    }

    return 0;
}