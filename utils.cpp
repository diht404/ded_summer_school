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
    return {lines, countLines, txt};
}

int compareStr(const void *lhsVoid, const void *rhsVoid)
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
        {
            return -1;
        }
        if (lhs->str[i] > rhs->str[j])
            return 1;

        i++;
        j++;
    }
    while (lhs->str[i] == '.')
    {
        i++;
    }
    while (rhs->str[j] == '.')
    {
        j++;
    }
    if (lhs->str[i] == '\0' and rhs->str[j] == '\0')
        return 0;

    if (lhs->str[i] == '\0' and rhs->str[j] != '\0')
    {
        return -1;
    }
    return 1;
}

int compareStrBack(const void *lhsVoid, const void *rhsVoid)
{
    assert(lhsVoid != nullptr);
    assert(rhsVoid != nullptr);

    const Line *lhs = (const Line *) lhsVoid;
    const Line *rhs = (const Line *) rhsVoid;

    long i = lhs->length - 1;
    long j = rhs->length - 1;

    while (i >= 0 and j >= 0)
    {
        if (lhs->str[i] == '.' or lhs->str[i] == '\0')
        {
            i--;
            continue;
        }
        if (rhs->str[j] == '.' or rhs->str[j] == '\0')
        {
            j--;
            continue;
        }

        if (lhs->str[i] < rhs->str[j])
        {
            return -1;
        }
        if (lhs->str[i] > rhs->str[j])
        {
            return 1;
        }

        i--;
        j--;
    }

    while (lhs->str[i] == '.')
    {
        i--;
    }
    while (rhs->str[j] == '.')
    {
        j--;
    }
    if (i < 0 and j < 0)
    {
        return 0;
    }

    if (i < 0)
    {
        return -1;
    }
    return 1;
}

void printFile(Text *text, const char *filename, bool sorted)
{
    assert(text != nullptr);
    assert(filename != nullptr);

    FILE *fp = fopen(filename, "w");

    if (sorted)
    {
        for (int i = 0; i < text->length; i++)
        {
            fprintf(fp, "%s\n", text->lines[i].str);
        }
    }
    else
    {
        size_t i = 0;
        size_t length = 0;
        while (length < text->length)
        {
            if (text->txt[i] == '\0')
            {
                fprintf(fp, "\n");
                length++;
                i++;
            }
            else
            {
                fprintf(fp, "%c", text->txt[i]);
                i++;
            }
        }
    }
    fclose(fp);
}

void swapLines(Line *lhs, Line *rhs)
{
    assert(lhs != nullptr);
    assert(rhs != nullptr);

    Line tmp = *lhs;
    *lhs = *rhs;
    *rhs = tmp;
}

size_t partition(Line *lines, const size_t l, const size_t r,
                 int (*comp)(const void *, const void *))
{
    assert(lines != nullptr);
    assert(comp != nullptr);

    Line *pivot = &lines[r];
    int greaterLine = l - 1;

    for (int j = l; j < r; j++)
    {
        if (comp(&lines[j], pivot) <= 0)
        {
            swapLines(&lines[++greaterLine], &lines[j]);
        }
    }

    swapLines(&lines[++greaterLine], pivot);

    return greaterLine;
}

void sort(Line *lines, const size_t l, const size_t r,
          int (*comp)(const void *, const void *))
{
    assert(lines != nullptr);
    assert(comp != nullptr);

    if (l < r)
    {
        size_t pivotInd = partition(lines, l, r, comp);
        sort(lines, l, pivotInd - 1, comp);
        sort(lines, pivotInd + 1, r, comp);
    }
}

void qSort(Line *lines, const size_t count,
           int (*comp)(const void *, const void *))
{
    assert(lines != nullptr);
    assert(comp != nullptr);

    sort(lines, 0, count - 1, comp);
}