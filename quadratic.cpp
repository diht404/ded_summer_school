#include "quadratic.h"

int main()
{
    double a = read();
    double b = read();
    double c = read();
    Solution solution = {};

    solve(a, b, c, &solution);

    print(&solution);
    return 0;
}

double read()
/*
 * Read float number from console
 * if gets not number, print error and try again
 */
{
    double answer = NAN;
    printf("Enter a number: ");
    bool correct = scanf("%lf", &answer);

    if (!correct)
    {
        printf("Incorrect number, try again!\n");
        answer = read();
    }
    return answer;
}

void solve(double a, double b, double c, Solution *solution)
/*
 * Solves quadratic equation and print answer.
 */
{
    if (abs(a) < eps)
    {
        // linear equation
        if (abs(b) < eps)
        {
            // equation like c=0
            if (abs(c) < eps)
            {
                solution->any_number = true;
            }
            else
            {
                solution->not_correct=true;
            }
        }
        else
        {
            solution->x1 = - c / b;
        }
    }
    else
    {
        // quadratic equation
        double D = b * b - 4 * a * c;
        if (abs(D) < eps)
        {
            // only one solution
            solution->x1 = -b / (2 * a);
        }
        else if (D < 0)
        {
            solution->no_solution = true;
        }
        else
        {
            // two solutions
            solution->x1 = (-b - sqrt(D)) / (2 * a);
            solution->x2 = (-b + sqrt(D)) / (2 * a);
        }
    }
}

void print(const Solution *solution)
/*
 * Prints quadratic equation solutions
 */
{
    if (solution->not_correct) printf("Equation isn\'t correct!\n");
    else if (solution->no_solution) printf("No real solutions!\n");
    else if (solution->any_number) printf("Any number.\n");
    else if (isnan(solution->x2)) printf("x = %f\n", solution->x1);
    else
    {
        printf("x1 = %f\n", solution->x1);
        printf("x2 = %f\n", solution->x2);
    }
}
