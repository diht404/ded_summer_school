#include <stdio.h>
#include <stdlib.h>
#include <math.h>


const double eps = 1e-10;

bool check_str(char *a, const char *b);

double read();

void solve(double a, double b, double c);

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
    const int read_size = 100;
    double answer = 0;
    
    char str[read_size];
    printf("Enter a number: ");
    scanf("%s", str);
    
    answer = atof(str);
    if (abs(answer) < eps)
    {
        // check if the string is equal to zero
        if (check_str(str, "0\0") or
            check_str(str, "0.\0") or
            check_str(str, "0.0\0") or
            check_str(str, ".\0"))
            return answer;
        else
        {
            printf("Incorrect number, try again!\n");
            answer = read();
        }
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
        if (D < 0)
        {
            printf("No real solutions!\n");
        }
        else if (D < eps)
        {
            // only one solution
            printf("x = %f\n", -b / (2 * a));
        }
        else
        {
            // two solutions
            printf("x1 = %f \n", (-b + sqrt(D)) / (2 * a));
            printf("x2 = %f \n", (-b - sqrt(D)) / (2 * a));
        }
    }
}
