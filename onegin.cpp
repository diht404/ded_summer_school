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

    qSort(text.lines, text.length, sizeof(Line), compareStr);
    printFile(&text, "sorted.txt");
    printFile(&text, "All_Data.txt");

    qSort(text.lines, text.length, sizeof(Line), compareStrBack);
    printFile(&text, "sorted_back.txt");
    printFile(&text, "All_Data.txt");

    size_t numParts = 3;
    Poem poem = {generatePoem(&text, numParts),
                 numParts,
                 ShakespeareNumLines};

    printPoem(&poem);

    printFile(&text, "not_sorted.txt", false);
    printFile(&text, "All_Data.txt");

    freeAll(&text, &poem);
    return 0;
}
