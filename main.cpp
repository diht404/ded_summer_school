#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void solve(double a, double b, double c);

int main()
{
    double a = -2;
    double b = 5;
    double c = 3;

    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);

    solve(a, b, c);
    return 0;
}


void solve(double a, double b, double c)
{

    if (abs(a) < 1e-10)
    {
        // linear equation
        if (abs(b) < 1e-10)
        {
            // equation like c=0
            if (abs(c) < 1e-10)
            {
                printf("Any number");
            }
            else
            {
                printf("Equation isn\'t correct");
            }
        }
        else
        {
            printf("%f", c / b);
        }
    }
    else
    {
        // quadratic equation
        double D = b * b - 4 * a * c;
        if (D < 0)
        {
            printf("No real solution");
        }
        else if (D < 1e-10)
        {
            // only one solution
            printf("%f", -b / (2 * a));
        }
        else
        {
            printf("x1 = %f \n", (-b + sqrt(D)) / (2 * a));
            printf("x2 = %f", (-b - sqrt(D)) / (2 * a));
        }
    }
}