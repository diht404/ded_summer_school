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
        {
//            printf("i='%ld' '%c' j='%ld' '%c'\n",
//                   i,
//                   lhs->str[i],
//                   j,
//                   rhs->str[j]);
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

//        printf("i='%ld' '%c' j='%ld' '%c'\n",
//               i,
//               lhs->str[i],
//               j,
//               rhs->str[j]);
        return -1;
    }
    return 1;
}

int compareStrBackQ(const void *lhsVoid, const void *rhsVoid)
{
    assert(lhsVoid != nullptr);
    assert(rhsVoid != nullptr);

    const Line *lhs = (const Line *) lhsVoid;
    const Line *rhs = (const Line *) rhsVoid;

    long i = lhs->length-1;
    long j = rhs->length-1;

    while (i >= 0 and j >= 0)
    {
        if (lhs->str[i] == '.' or lhs->str[i]=='\0')
        {
            i--;
            continue;
        }
        if (rhs->str[j] == '.' or rhs->str[j]=='\0')
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
