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
    char symbol = getchar();

    while (symbol != '\n')
    {
        if (symbol == EOF)
            return 1;
        symbol = getchar();
    }

    return 0;
}
int readVariable(const char *name, double *param)
{
    printf("Enter a coefficient %s: ", name);

    int correct = scanf("%lf", param);

    int readCount = 1;
    int errorCode = NO_ERRORS;

    while (correct != 1 and readCount<5)
    {
        printf("Incorrect number, try again!\n");
        if (skipUnusedSymbols())
        {
            errorCode = EOF_ERROR;
            return errorCode;
        }
        readCount+=1;
        correct = scanf("%lf", param);
    }
    if (readCount==5) errorCode = TOO_MANY_ATTEMPTS_TO_READ;
    if (isnan(*param)) errorCode = NAN_VALUE;
    if (isinf(*param)) errorCode = INF_VALUE;
    return errorCode;
}

int readEquation(Equation *equation)
{
    if (equation == nullptr) return NULL_FIRST;

    int error = readVariable("a", &equation->a);
    if (error == NAN_VALUE) return NAN_FIRST;
    if (error == INF_VALUE) return INF_FIRST;
    if (error != NO_ERRORS) return error;

    error = readVariable("b", &equation->b);
    if (error == NAN_VALUE) return NAN_SECOND;
    if (error == INF_VALUE) return INF_SECOND;
    if (error != NO_ERRORS) return error;

    error = readVariable("c", &equation->c);
    if (error == NAN_VALUE) return NAN_THIRD;
    if (error == INF_VALUE) return INF_THIRD;
    if (error != NO_ERRORS) return error;

    return error;
}

int print(const Solution *solution)
{
    int errorCode = NO_ERRORS;
    if (solution == nullptr) return NULL_FIRST;

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
            break;
    }
    return errorCode;
}