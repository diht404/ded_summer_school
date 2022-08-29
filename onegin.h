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
};

Text readFile(FILE *fp);

int compareStrQ(const void *lhsVoid, const void *rhsVoid);

bool compareStr(const Line *lhs, const Line *rhs);

bool compareStrBack(const Line *lhs, const Line *rhs);

int compareStrBackQ(const void *lhsVoid, const void *rhsVoid);

void bubbleSort(Text *text,
                bool (*comparator)(const Line *lhs,
                                   const Line *rhs) = compareStr);

void print(Text *text);

void printFile(Text *text, const char *filename);
