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
        case NO_ERRORS:
            break;
        case TOO_MANY_ATTEMPTS_TO_READ:
            fprintf(stderr, "Too many attempts to read equation.\n");
            break;
        case EOF_ERROR:
            fprintf(stderr, "EOF occurred.\n");
            break;
//        case NULL_FIRST:
//            fprintf(stderr, "First argument is nullptr.\n");
//            break;
//        case NULL_SECOND:
//            fprintf(stderr, "Second argument is nullptr.\n");
//            break;
        default:
            fprintf(stderr, "Unknown error code: %d.\n",
                    errorCode);
            break;
    }
}