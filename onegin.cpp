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

    Text text = readFile2(fp);

    fclose(fp);
    printf("%d\n", text.length);
    printf("NOT SORTED\n");
    print(&text);                /// -> file
//
//    printf("\n\nSORTED\n");
//    bubbleSort(&text, compareStr);
//    print(&text);
//
//    printf("\n\nSORTED BACK\n");
//    bubbleSort(&text, compareStrBack);
//    print(&text);
//
//    printf("\n");

    return 0;
}
