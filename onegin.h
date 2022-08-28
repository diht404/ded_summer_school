#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <cstdio>
#include <unistd.h>

struct Text {
    char **txt = nullptr;
    size_t length = 0;
};


Text readFile2(FILE *fp);

char **readFile(FILE *fp, size_t length);

size_t countLines(FILE *fp);

char *revStr(char *revstr, char *str);

bool compareStr(char *lhs, char *rhs);

bool compareStr2(char *lhs, char *rhs);

bool compareStrBack(char *lhs, char *rhs);

void bubbleSort(Text *text, bool (*comparator)(char *lhs, char *rhs) = compareStr);

void print(Text *text);

void textFree(Text *text);
