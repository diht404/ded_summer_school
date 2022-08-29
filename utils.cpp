#include "onegin.h"
// ctype.h isalnum
Text readFile(FILE *fp)
{
    fseek(fp, 0, SEEK_END);
    long lenOfFile = ftell(fp);
    rewind(fp);

    char *txt = (char *) calloc(lenOfFile, sizeof(char));
    fread(txt, sizeof(char), lenOfFile, fp);

    size_t countLines = 1;
    for (long i = 0; i < lenOfFile; i++)
    {
        if (txt[i] == '\n')
            countLines++;
    }

    Line *lines = (Line *) calloc(countLines, sizeof (Line));

    long position = 0;
    long line_id = 0;
    size_t length = 0;
    for (long i = 0; i < lenOfFile; i++)
    {
        if (position == 0)
        {
            lines[line_id] = {&txt[i], 0};
        }
        lines[line_id].length++;
        position++;
        if (txt[i]=='\n'){
            position=0;
            txt[i] = '\0';
            line_id++;
        }
    }
    return {lines, countLines};
}

char *revStr(char *revstr, char *str) {///
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

    while (lhs[i] != '\0' and rhs[j] != '\0') {
        if (lhs[i] < rhs[j])
            return true;

        if (lhs[i] > rhs[j])
            return false;

        i++;
        j++;
    }

    if (lhs[i] == '\0' and rhs[i] == '\0')
        return false;

    if (lhs[i] == '\0' and rhs[i] != '\0')
        return true;

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
            if (comparator(text->lines[j+1].str, text->lines[j].str)) {
                char *tmp = text->lines[j].str;
                text->lines[j].str = text->lines[j+1].str;
                text->lines[j+1].str = tmp;
            }
        }
    }
}

void print(Text *text) {
    for (size_t i = 0; i < text->length; i++) {
        printf("%s\n", text->lines[i].str);
    }
}
