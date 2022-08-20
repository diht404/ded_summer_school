/**
 * @file quadratic.cpp
 *
 * Main file for quadratic equation solution
 */

#include "quadratic.h"

/**
 * @brief main function for quadratic equation solution
 * @return 0
 */
int main()
{

    Equation equation = {};
    readEquation(&equation);

    Solution solution = {};
    solve(&equation, &solution);

    print(&solution);

    return 0;
}

void skipUnusedSymbols()
{
    while (getchar() != '\n')
        continue;
}

double read()
{
    printf("Enter a number: ");

    double answer = NAN;
    int correct = scanf("%lf", &answer);

    while (correct != 1)
    {
        printf("Incorrect number, try again!\n");
        skipUnusedSymbols();
        correct = scanf("%lf", &answer);
    }

    return answer;
}

void readEquation(Equation *equation)
{
    equation->a = read();
    equation->b = read();
    equation->c = read();
}

void print(const Solution *solution)
{
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
            fprintf(stderr, "Error");
            break;
    }
}
