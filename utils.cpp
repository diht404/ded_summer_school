#include "onegin.h"

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

    Line *lines = (Line *) calloc(countLines, sizeof(Line));

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
        if (txt[i] == '\n')
        {
            lines[line_id].length = position;
            position = 0;
            txt[i] = '\0';
            line_id++;
        }
    }
    return {lines, countLines};
}

char *revStr(char *revstr, char *str)
{///
    size_t left = 0;
    size_t right = strlen(str) - 1;
    strcpy(revstr, str);
    for (size_t i = left; i < right; i++)
    {
        char temp = revstr[i];
        revstr[i] = revstr[right];
        revstr[right] = temp;
        right--;
    }
    return revstr;
}

bool compareStr(Line *lhs, Line *rhs)
{
    size_t i = 0;
    size_t j = 0;

    while (lhs->str[i] != '\0' and rhs->str[j] != '\0')
    {
        if (lhs->str[i] == '.')
        {
            i++;
            continue;
        }
        if (rhs->str[j] == '.')
        {
            j++;
            continue;
        }

        if (lhs->str[i] < rhs->str[j])
            return true;

        if (lhs->str[i] > rhs->str[j])
            return false;

        i++;
        j++;
    }

    if (lhs->str[i] == '\0' and rhs->str[j] == '\0')
        return false;

    if (lhs->str[i] == '\0' and rhs->str[j] != '\0')
        return true;

    return false;
}

bool compareStrBack(Line *lhs, Line *rhs)
{
    int i = lhs->length;
    int j = lhs->length;

    while (i > 0 and j > 0)
    {
        if (lhs->str[i] == '.')
        {
            i--;
            continue;
        }
        if (rhs->str[j] == '.')
        {
            j--;
            continue;
        }

        if (lhs->str[i] < rhs->str[j])
            return true;

        if (lhs->str[i] > rhs->str[j])
            return false;

        i--;
        j--;
    }

    if (i < 0 and j < 0)
        return false;

    if (i < 0 and j >= 0)
        return true;

    return false;
}

void bubbleSort(Text *text, bool (*comparator)(Line *lhs, Line *rhs))
{
    for (int i = 0; i < text->length - 1; i++)
    {
        for (int j = 0; j < text->length - i - 1; j++)
        {
            if (comparator(&(text->lines[j + 1]), &(text->lines[j])))
            {
                Line tmp = text->lines[j];
                text->lines[j] = text->lines[j + 1];
                text->lines[j + 1] = tmp;
            }
        }
    }
}

void print(Text *text)
{
    for (size_t i = 0; i < text->length; i++)
    {
        printf("%s ,  %d \n",
               text->lines[i].str,
               text->lines[i].length);
    }
}
