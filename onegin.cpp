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

//    printFile(&text, "not_sorted.txt");
//    qsort(text.lines, text.length, sizeof(Line), compareStr);
    qSort(text.lines, text.length, compareStr);
    printFile(&text, "sorted.txt");

//    qsort(text.lines, text.length, sizeof(Line), compareStrBack);
//    printFile(&text, "sorted_back.txt");
//
//    printFile(&text, "not_sorted.txt", false);
    return 0;
}
