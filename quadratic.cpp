#include "quadratic.h"

int main()
{

    Equation equation = {};
    read_eq(&equation);

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

void solve(Equation *equation, Solution *solution)
{
    double a = equation->a;
    double b = equation->b;
    double c = equation->c;

    if (abs(a) < eps)
    {
        // linear equation
        if (abs(b) < eps)
        {
            // equation like c=0
            if (abs(c) < eps)
            {
                solution->rootCount = infSolutions;
            }
            else
            {
                solution->rootCount = noRoots;
            }
        }
        else
        {
            solution->x1 = -c / b;
        }
        return;
    }

    // quadratic equation
    double D = b * b - 4 * a * c;
    if (abs(D) < eps)
    {
        solution->rootCount = oneSolution;
        solution->x1 = -b / (2 * a);
    }
    else if (D < 0)
    {
        solution->rootCount = noRoots;
    }
    else
    {
        solution->rootCount = twoSolutions;
        solution->x1 = (-b - sqrt(D)) / (2 * a);
        solution->x2 = (-b + sqrt(D)) / (2 * a);
    }
}

void print(const Solution *solution)
{
    switch (solution->rootCount)
    {
        case noRoots:printf("No real solutions!\n");
            break;
        case infSolutions:printf("Any number.\n");
            break;
        case oneSolution:printf("x = %lf\n", solution->x1);
            break;
        case twoSolutions:printf("x1 = %lf\n", solution->x1);
            printf("x2 = %lf\n", solution->x2);
            break;
        default:fprintf(stderr, "Error");
            break;
    }
}
