#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Equation
{
    double a = NAN;
    double b = NAN;
    double c = NAN;
};

enum RootCount
{
    noRoots      = 0,
    oneSolution  = 1,
    twoSolutions = 2,
    infSolutions = 3,
};

struct Solution
{
    double x1 = NAN;
    double x2 = NAN;
    RootCount rootCount = noRoots;;
};

const double eps = 1e-10;

/*
 * Read float number from console
 * if gets not number, print error and try again
 */
double read();

/*
 * read equation coefficients to struct
 */
void read_eq(Equation *equation);

/*
 * Solves quadratic equation and print answer.
 */
void solve(Equation *equation, Solution *solution);

/*
 * Prints quadratic equation solutions
 */
void print(const Solution *solution);