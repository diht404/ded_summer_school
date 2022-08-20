/**
 * @file quadratic.h
 * @author diht404
 * @date 08.20.2022
 * @brief quadratic equation header
 *
 * This files contains all functions and structures, related to
 * quadratic equation solution
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief structure for storing coefficients of a quadratic equation
 *
 * @param a first coefficient of a quadratic equation
 * @param b second coefficient of a quadratic equation
 * @param c third coefficient of a quadratic equation
 */
struct Equation
{
    double a = NAN;
    double b = NAN;
    double c = NAN;
};

/**
 * @brief Enumeration of the number of roots of a quadratic equation
 *
 * @param noRoots case if equation doesn't have roots
 * @param oneSolution case if equation has only one root
 * @param twoSolutions case if equation has two roots
 * @param infSolutions case if equation has any number as root
 */
enum RootCount
{
    noRoots = 0,
    oneSolution = 1,
    twoSolutions = 2,
    infSolutions = 3,
};

/**
 * @brief structure for storing quadratic equation solution  and
 * enum data about count of roots
 *
 * @param x1 first solution
 * @param x2 first solution
 * @param rootCount count of solutions
 */
struct Solution
{
    double x1 = NAN;
    double x2 = NAN;
    RootCount rootCount = noRoots;
};

const double eps =
    1e-10; ///< the constant of of the accuracy of solving the equation

/**
 * @brief Skips symbols from print from UI
 *
 * Deletes characters that were printed by the UI helper prompt
 * @return void
 */
void skipUnusedSymbols();

/**
 * @brief reads one number
 *
 * Reads float number from console
 * if gets not number, print error and try again
 * @return double number read
 */
double read();

/**
 * @brief reads quadratic equation coefficients to struct
 *
 * reads quadratic equation coefficients to struct,
 * which contain fields: a, b, c
 *
 * @param equation struct with fields a, b, c
 * @return void
 */
void readEquation(Equation *equation);

/**
 * @brief Solves quadratic equation and print answer.
 *
 * @param equation struct with fields a, b, c
 * @param solution structure for storing quadratic equation solution and
 * enum data about count of roots
 * @return void
 */
void solveQuadratic(Equation *equation, Solution *solution);

/**
 * @brief Solves quadratic equation and print answer.
 *
 * @param equation struct with fields a, b, c
 * @param solution structure for storing quadratic equation solution and
 * enum data about count of roots
 * @return void
 */
void solveQuadratic(Equation *equation, Solution *solution);

/**
 * @brief Solves linear equation and print answer.
 *
 * @param equation struct with fields a, b, c
 * @param solution structure for storing linear equation solution and
 * enum data about count of roots
 * @return void
 */
void solveLinear(Equation *equation, Solution *solution);

/**
 * @brief Prints quadratic equation solutions
 *
 * @param solution structure for storing quadratic equation solution and
 * enum data about count of roots
 * @return void
 */
void print(const Solution *solution);