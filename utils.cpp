#include "onegin.h"

    char **readFile(FILE *fp, size_t length) {
    rewind(fp);
    char **txt = (char **) calloc(length, sizeof(char *));
    // cal
    for (size_t i = 0; i < length; i++) {
        txt[i] = (char *) calloc(1, 128);
        // cal
        char *result = fgets(txt[i], 128, fp);
        if (result == NULL) {
            assert(0);
        }
    }
    return txt;
}

size_t countLines(FILE *fp) {
    rewind(fp);
    char str[128];
    size_t i = 0;
    while (fgets(str, sizeof(str), fp) != NULL) {
        i++;
    }
    return i;
}

bool compareStr(char *lhs, char *rhs) {
    return strcmp(lhs, rhs) > 0;
}

char *revStr(char *revstr, char *str) {
    size_t left = 0;
    size_t right = strlen(str) - 1;
    strcpy(revstr, str);
    for (size_t i = left; i < right; i++) {
        char temp = revstr[i];
        revstr[i] = revstr[right];
        revstr[right] = temp;
        right--;
    }
    return revstr;
}

bool compareStrBack(char *lhs, char *rhs) {
    char *revLhs = (char *) calloc(1, 128);
    revStr(revLhs, lhs);
    char *revRhs = (char *) calloc(1, 128);
    revStr(revRhs, rhs);
    return strcmp(revLhs, revRhs) > 0;
}

void bubbleSort(char **txt, size_t length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (compareStr(txt[j], txt[j + 1])) {
                auto tmp = txt[j];
                txt[j] = txt[j + 1];
                txt[j + 1] = tmp;
            }
        }
    }
}

void bubbleSortBack(char **txt, size_t length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (compareStrBack(txt[j], txt[j + 1])) {
                auto tmp = txt[j];
                txt[j] = txt[j + 1];
                txt[j + 1] = tmp;
            }
        }
    }
}

void print(char **txt, size_t length)
{
    for (size_t i = 0; i < length; i++) {
        printf("%s", txt[i]);
    }
}