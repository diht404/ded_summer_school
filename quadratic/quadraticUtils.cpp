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
    int errorCode = 0;

    while (correct != 1 and readCount<5)
    {
        printf("Incorrect number, try again!\n");
        if (skipUnusedSymbols())
        {
            errorCode = 2;
            return errorCode;
        }
        readCount+=1;
        correct = scanf("%lf", param);
    }
    if (readCount==5) errorCode = 1;
    return errorCode;
}

int readEquation(Equation *equation)
{
    assert(equation != nullptr);

    int errorCode = 0;
    errorCode = readVariable("a", &equation->a);
    if (errorCode!=0) return errorCode;
    errorCode = readVariable("b", &equation->b);
    if (errorCode!=0) return errorCode;
    errorCode = readVariable("c", &equation->c);
    return errorCode;
}

int print(const Solution *solution)
{
    int errorCode = 0;
    if (solution == nullptr) return 31;

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