#include "onegin.h"

int main()
{
    const char *filename = "onegin.txt";
    FILE *fp = fopen(filename, "r");
    if (fp == nullptr)
    {
        perror("Unable to open file!");
        exit(1);
    }

    Text text = readFile(fp);
    fclose(fp);

    printFile(&text, "not_sorted.txt");
    qsort(text.lines, text.length, sizeof(Line), compareStrQ);
    printFile(&text, "sorted.txt");

    qsort(text.lines, text.length, sizeof(Line), compareStrBackQ);
//    bubbleSort(&text, compareStrBack);
    printFile(&text, "sorted_back.txt");
    char l[] = "a";
    char r[] = ".";
    Line lhs = {l, strlen(l)};
    Line rhs = {r, strlen(r)};
//    printf("%d\n", "a"<".");
//    printf("%d\n", compareStrBackQ(&lhs, &rhs));
    return 0;
}
