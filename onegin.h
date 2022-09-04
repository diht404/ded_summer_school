#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <cstdio>
#include <unistd.h>
#include <ctype.h>

struct Line
{
    char *str = nullptr;
    long length = 0;
};

struct Text
{
    Line *lines = nullptr;
    size_t length = 0;
    char * txt;
};

Text readFile(FILE *fp);

int compareStr(const void *lhsVoid, const void *rhsVoid);

int compareStrBack(const void *lhsVoid, const void *rhsVoid);

void printFile(Text *text, const char *filename, bool sorted = true);

void swapLines(Line *lhs, Line *rhs);

size_t partition(Line *lines, size_t l, size_t r,
                 int (*comp)(const void *, const void *));

void sort(Line *lines, size_t l, size_t r,
          int (*comp)(const void *, const void *));

/**
 * @brief qsort implementaion
 * @param lines pointer to the array to sort
 * @param count number of elements in the array
 * @param comp comparator
 */
void qSort(Line *lines, size_t count,
           int (*comp)(const void *, const void *));