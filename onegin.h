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

int compareStrBackQ(const void *lhsVoid, const void *rhsVoid);

void printFile(Text *text, const char *filename, bool sorted = true);
