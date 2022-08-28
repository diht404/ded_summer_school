#include "onegin.h"

int main() {
    const char *filename = "onegin.txt";
    FILE *fp = fopen(filename, "r");
    if (fp == nullptr) {
        perror("Unable to open file!");
        exit(1);
    }
    // all file in one block
    size_t length = countLines(fp);
    Text text = {readFile(fp, length), length};

    fclose(fp);

    printf("NOT VERY SORTED\n");
    print(&text);

    printf("\n\nSORTED\n");
    bubbleSort(&text);
    print(&text);

    printf("\n\nSORTED BACK\n");
    bubbleSortBack(&text);
    print(&text);

    printf("\n");
    return 0;
}