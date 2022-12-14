/**
 * @file quadratic.h
 * @author diht404
 * @date 08.20.2022
 *
 * @brief quadratic equation header
 *
 * This files contains all functions and structures, related to
 * quadratic equation solution
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

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
 * @brief Enumeration of the error codes
 *
 * @param noRoots case if equation doesn't have roots
 * @param oneSolution case if equation has only one root
 * @param twoSolutions case if equation has two roots
 * @param infSolutions case if equation has any number as root
 */
enum ErrorCodes
{
    NO_ERRORS = 0,
    TOO_MANY_ATTEMPTS_TO_READ = 1,
    EOF_ERROR = 2,
    UNKNOWN_ROOT_COUNT = 3,
    INF_VALUE = 4,
    NAN_VALUE = 5,
};

/**
 * @brief structure for storing quadratic equation solution  and
 * enum data about count of roots
 *
 * @param x1 first solution
 * @param x2 second solution
 * @param rootCount count of solutions
 */
struct Solution
{
    double x1 = NAN;
    double x2 = NAN;
    RootCount rootCount = noRoots;
};

const double Eps =
    1e-10; ///< the constant of of the accuracy of solving the equation
const char ANSI_COLOR_RED[] = "\x1b[31m"; ///< red colour for output
const char ANSI_COLOR_GREEN[] = "\x1b[32m"; ///< green colour for output
const char ANSI_COLOR_RESET[] = "\x1b[0m";  ///< colour reset for output


/**
 * @brief checks if double is near equal to zero
 *
 * @param number checking double number
 * @return is number is a zero
 */
bool equalZero(double number);

/**
 * @brief Solves quadratic equation and print answer.
 *
 * @param equation struct with fields a, b, c
 * @param solution structure for storing quadratic equation solution and
 * enum data about count of roots
 * @return error code
 */
int solveQuadratic(const Equation *equation, Solution *solution);

/**
 * @brief Solves linear equation and print answer.
 *
 * @param equation struct with fields a, b, c
 * @param solution structure for storing linear equation solution and
 * enum data about count of roots
 * @return error code
 */
int solveLinear(const Equation *equation, Solution *solution);

/**
 * @brief Processes error by code
 * @param errorCode
 */
void processError(int errorCode);

/**
 * @brief Prints quadratic equation solutions
 *
 * @param solution structure for storing quadratic equation solution and
 * enum data about count of roots
 * @return error code
 */
int print(const Solution *solution);

/**
 * @brief reads quadratic equation coefficients to struct
 *
 * reads quadratic equation coefficients to struct,
 * which contain fields: a, b, c
 *
 * @param equation struct with fields a, b, c
 * @return void
 */
int readEquation(Equation *equation);