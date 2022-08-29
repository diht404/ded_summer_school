#include "onegin.h"

// 1) fseek + ftell + rewind
// 2) calloc + fread
// 3) 1st -> count lines + calloc
// 4) 2st ->
int main() {
    const char *filename = "onegin.txt";
    FILE *fp = fopen(filename, "r");
    if (fp == nullptr) {
        perror("Unable to open file!");
        exit(1);
    }

    Text text = readFile(fp);
    fclose(fp);

    printFile(&text, "not_sorted.txt");

    qsort(text.lines, text.length, sizeof(Line), compareStrQ);
//    bubbleSort(&text, compareStr);
    printFile(&text, "sorted.txt");

    qsort(text.lines, text.length, sizeof(Line), compareStrBackQ);
//    bubbleSort(&text, compareStrBack);
    printFile(&text, "sorted_back.txt");

    return 0;
}
