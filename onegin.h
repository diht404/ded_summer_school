#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <cstdio>


char **readFile(FILE *fp, size_t length);

size_t countLines(FILE *fp);

char *revStr(char *revstr, char *str);

bool compareStr(char *lhs, char *rhs);

bool compareStrBack(char *lhs, char *rhs);

void bubbleSort(char **txt, size_t length);

void bubbleSortBack(char **txt, size_t length);

void print(char **txt, size_t length);