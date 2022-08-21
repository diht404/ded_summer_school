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

double readVariable(const char *name)
{
    printf("Enter a coefficient %s: ", name);

    double answer = NAN;
    int correct = scanf("%lf", &answer);

    while (correct != 1)
    {
        printf("Incorrect number, try again!\n");
        if (skipUnusedSymbols())
        {
            fprintf(stderr,"EOF occurred.\n");
            return NAN;
        }
        correct = scanf("%lf", &answer);
    }

    return answer;
}

void readEquation(Equation *equation)
{
    assert(equation != nullptr);

    equation->a = readVariable("a");
    equation->b = readVariable("b");
    equation->c = readVariable("c");
}

void print(const Solution *solution)
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
            break;
    }
}
