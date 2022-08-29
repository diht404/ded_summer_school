#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <cstdio>
#include <unistd.h>

struct Line {
    char *str = nullptr;
    long length = 0;
};

struct Text {
    Line *lines = nullptr;
    size_t length = 0;
};

Text readFile(FILE *fp);

char *revStr(char *revstr, char *str);

bool compareStr(char *lhs, char *rhs);

bool compareStrBack(char *lhs, char *rhs);

void bubbleSort(Text *text, bool (*comparator)(char *lhs, char *rhs) = compareStr);

void print(Text *text);
