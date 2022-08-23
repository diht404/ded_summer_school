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
        case INF_VALUE:
            fprintf(stderr, "Infinite value occurred.\n");
            break;
        case INF_FIRST:
            fprintf(stderr, "Infinite 'a' coefficient.\n");
            break;
        case INF_SECOND:
            fprintf(stderr, "Infinite 'b' coefficient.\n");
            break;
        case INF_THIRD:
            fprintf(stderr, "Infinite 'c' coefficient.\n");
            break;
        case NAN_VALUE:
            fprintf(stderr, "NAN value occurred.\n");
            break;
        case NAN_FIRST:
            fprintf(stderr, "NAN 'a' coefficient.\n");
            break;
        case NAN_SECOND:
            fprintf(stderr, "NAN 'b' coefficient.\n");
            break;
        case NAN_THIRD:
            fprintf(stderr, "NAN 'c' coefficient.\n");
            break;
        case NULL_FIRST:
            fprintf(stderr, "First argument is nullptr.\n");
            break;
        case NULL_SECOND:
            fprintf(stderr, "Second argument is nullptr.\n");
            break;
        default:
            fprintf(stderr, "Unknown error code: %d.\n",
                    errorCode);
            break;
    }
}