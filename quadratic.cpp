#include "quadratic.h"

int main()
{
    double a = read();
    double b = read();
    double c = read();

    solve(a, b, c);
    return 0;
}

bool check_str(char *a, const char *b)
/*
 * Check if strings are equal
 */
{
    int i = 0;
    while (b[i] != '\0')
    {
        if (a[i] != b[i])
            return false;
        i += 1;
    }
    return true;
}

double read()
/*
 * Read float number from console
 * if gets not number, print error and try again
 */
{
    double answer = 0;
    printf("Enter a number: ");
    bool correct = scanf("%lf", &answer);

    if (!correct)
    {
        printf("Incorrect number, try again!\n");
        answer = read();
    }
    return answer;
}

void solve(double a, double b, double c)
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
                printf("Any number.\n");
            }
            else
            {
                printf("Equation isn\'t correct!\n");
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
        if (abs(D)<eps)
        {
            // only one solution
            printf("x = %f\n", -b / (2 * a));
        }
        else if (D < 0)
        {
            printf("No real solutions!\n");
        }
        else
        {
            // two solutions
            printf("x1 = %f \n", (-b + sqrt(D)) / (2 * a));
            printf("x2 = %f \n", (-b - sqrt(D)) / (2 * a));
        }
    }
}
