/**
 * @file utils.cpp
 * @author diht404
 * @date 08.23.2022
 *
 * @brief Implementation of utils for main and tests
 *
 * This file contains all utils functions for main and tests
 */

#include "quadratic.h"

void processError(int errorCode)
{
    switch (errorCode)
    {
        case 0:
            break;
        case 1:
            fprintf(stderr, "Too many attempts to read equation.\n");
            break;
        case 2:
            fprintf(stderr, "EOF occurred.\n");
            break;
        case 11:
            fprintf(stderr, "Inf first coefficient\n");
            break;
        case 12:
            fprintf(stderr, "Inf second coefficient\n");
            break;
        case 13:
            fprintf(stderr, "Inf third coefficient\n");
            break;
        case 21:
            fprintf(stderr, "NAN first coefficient\n");
            break;
        case 22:
            fprintf(stderr, "NAN second coefficient\n");
            break;
        case 23:
            fprintf(stderr, "NAN third coefficient\n");
            break;
        case 31:
            fprintf(stderr, "First argument if nullptr\n");
            break;
        case 32:
            fprintf(stderr, "Second argument if nullptr\n");
            break;
        default:
            fprintf(stderr, "Unknown error code: %d\n",
                    errorCode);
            break;
    }
}