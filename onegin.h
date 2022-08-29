#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <cstdio>
#include <unistd.h>
#include <ctype.h>

struct Line {
    char *str = nullptr;
    long length = 0;
};

struct Text {
    Line *lines = nullptr;
    size_t length = 0;
};

Text readFile(FILE *fp);

bool compareStr(Line *lhs, Line *rhs);

bool compareStrBack(Line *lhs, Line *rhs);

void bubbleSort(Text *text, bool (*comparator)(Line *lhs, Line *rhs) = compareStr);

void print(Text *text);
