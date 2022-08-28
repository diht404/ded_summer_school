#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <cstdio>

struct Text {
    char **txt = nullptr;
    size_t length = 0;
};

char **readFile(FILE *fp, size_t length);

size_t countLines(FILE *fp);

char *revStr(char *revstr, char *str);

bool compareStr(char *lhs, char *rhs);

bool compareStrBack(char *lhs, char *rhs);

void bubbleSort(Text *text);

void bubbleSortBack(Text *text);

void print(Text *text);