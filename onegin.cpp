#include "onegin.h"

int main() {
    const char *filename = "onegin.txt";
    FILE *fp = fopen(filename, "r");
    if (fp == nullptr) {
        perror("Unable to open file!");
        exit(1);
    }
    // all file in one block
    // struct<txt, length>
    size_t length = countLines(fp);

    char **txt = readFile(fp, length);
    fclose(fp);

    printf("NOT VERY SORTED\n");
    print(txt, length);

    printf("\n\nSORTED\n");
    bubbleSort(txt, length);
    print(txt, length);

    printf("\n\nSORTED BACK\n");
    bubbleSortBack(txt, length);
    print(txt, length);

    printf("\n");
    return 0;
}