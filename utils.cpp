#include "onegin.h"

Text readFile2(FILE *fp) {
    size_t arr_size = 0;
    size_t buffer_size = 0;
    char c = EOF;
    size_t arr_capacity = 1;
    char **txt = (char **) calloc(arr_capacity, sizeof(char *));
    char *buffer = (char *) calloc(1, 128);
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') {
            buffer[buffer_size] = '\0';
            txt[arr_size] = (char *) calloc(buffer_size, sizeof(char));
            strcpy(txt[arr_size], buffer);
            if (arr_size >= arr_capacity) {
                txt = (char **) realloc(txt, arr_capacity * 2 * sizeof(char *));
                arr_capacity *= 2;
            }
            buffer[0] = '\0';
            buffer_size = 0;
            arr_size++;
        } else {
            buffer[buffer_size] = c;
            buffer_size++;
        }
    }
    free(buffer);
    return {txt, arr_size};
//    }
//    text->txt = txt;
//    text->length = arr_capacity;
//    c = fgetc(fp);
//    char **txt = (char **) calloc(buffer_size, sizeof(char *));
//    for (size_t arr_size = 0; arr_size < buffer_size; arr_size++) {
//        if (arr_size >= buffer_size)
//            txt = (char **) realloc(txt, 2 * buffer_size * sizeof(char *));
//        txt[arr_size] = (char *) calloc(1, 128);
//        char *result = fgets(txt[arr_size], 128, fp);
//        if (result == NULL) {
//            assert(0);
//        }
//    }
//    text->txt = txt;
//    text->buffer_size = arr_size;
}

char **readFile(FILE *fp, size_t length) {
    rewind(fp);
    char **txt = (char **) calloc(length, sizeof(char *));
    for (size_t i = 0; i < length; i++) {
        txt[i] = (char *) calloc(1, 128);
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

bool compareStr(char *lhs, char *rhs) {
    size_t i = 0;
    size_t j = 0;
    while (lhs[i] != '\0' or rhs[j] != '\0') {
        if (lhs[i] == ' ' or lhs[i] == '.' or lhs[i] == ',' or lhs[i] == ',' or
            lhs[i] == '!' or lhs[i] == ';' or lhs[i] == '?' or lhs[i] == ':')
            i++;

        if (lhs[j] == ' ' or lhs[j] == '.' or lhs[j] == ',' or lhs[j] == ',' or
            lhs[j] == '!' or lhs[j] == ';' or lhs[j] == '?' or lhs[i] == ':')
            j++;

        if (lhs[i] == '\0')
            return true;

        if (lhs[j] == '\0')
            return false;

        if (lhs[i] < rhs[j])
            return true;

        if (lhs[i] < rhs[j])
            return false;
        i++;
        j++;
    }
    return false;
}

bool compareStrBack(char *lhs, char *rhs) {
    char *revLhs = (char *) calloc(1, 128);
    revStr(revLhs, lhs);
    char *revRhs = (char *) calloc(1, 128);
    revStr(revRhs, rhs);
    return strcmp(revLhs, revRhs) > 0;
}

void bubbleSort(Text *text, bool (*comparator)(char *lhs, char *rhs)) {
    for (int i = 0; i < text->length - 1; i++) {
        for (int j = 0; j < text->length - i - 1; j++) {
            if (comparator(text->txt[j], text->txt[j + 1])) {
                char *tmp = text->txt[j];
                text->txt[j] = text->txt[j + 1];
                text->txt[j + 1] = tmp;
            }
        }
    }
}

void print(Text *text) {
    for (size_t i = 0; i < text->length; i++) {
        printf("%s\n", text->txt[i]);
    }
}

void textFree(Text *text) {
    for (size_t i = 0; i < text->length; i++) {
        free(text->txt[i]);
    }
    free(text->txt);
}
