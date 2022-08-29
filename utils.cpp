#include "onegin.h"

Text readFile(FILE *fp)
{

    assert(fp != nullptr);

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

int compareStrQ(const void *lhsVoid, const void *rhsVoid)
{
    assert(lhsVoid != nullptr);
    assert(rhsVoid != nullptr);

    const Line *lhs = (const Line *) lhsVoid;
    const Line *rhs = (const Line *) rhsVoid;

    long i = 0;
    long j = 0;

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
            return -1;

        if (lhs->str[i] > rhs->str[j])
            return 1;

        i++;
        j++;
    }

    if (lhs->str[i] == '\0' and rhs->str[j] == '\0')
        return 0;

    if (lhs->str[i] == '\0' and rhs->str[j] != '\0')
        return -1;

    return 1;
}

bool compareStr(const Line *lhs, const Line *rhs)
{
    assert(lhs != nullptr);
    assert(rhs != nullptr);

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

int compareStrBackQ(const void *lhsVoid, const void *rhsVoid)
{
    assert(lhsVoid != nullptr);
    assert(rhsVoid != nullptr);

    const Line *lhs = (const Line *) lhsVoid;
    const Line *rhs = (const Line *) rhsVoid;

    long i = lhs->length;
    long j = lhs->length;

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
            return -1;

        if (lhs->str[i] > rhs->str[j])
            return 1;

        i--;
        j--;
    }

    if (i < 0 and j < 0)
        return 0;

    if (i < 0 and j >= 0)
        return -1;

    return 1;
}

bool compareStrBack(const Line *lhs, const Line *rhs)
{
    assert(lhs != nullptr);
    assert(rhs != nullptr);

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

void bubbleSort(Text *text,
                bool (*comparator)(const Line *lhs, const Line *rhs))
{
    assert(text != nullptr);
    assert(comparator != nullptr);

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
    assert(text != nullptr);

    for (size_t i = 0; i < text->length; i++)
    {
        printf("%s\n", text->lines[i].str);
    }
}

void printFile(Text *text, const char *filename)
{
    assert(text != nullptr);
    assert(filename != nullptr);

    FILE *fp = fopen(filename, "w");
    for (int i = 0; i < text->length; i++)
    {
        fprintf(fp, "%s\n", text->lines[i].str);
    }
    fclose(fp);
}
