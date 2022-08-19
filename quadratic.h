#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Solution
{
    double x1 = NAN;
    double x2 = NAN;
    bool any_number = false;
    bool not_correct = false;
    bool no_solution = false;
};

const double eps = 1e-10;

double read();

void solve(double a, double b, double c, Solution *solution);

void print(const Solution *solution);