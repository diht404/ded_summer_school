#include "onegin.h"

int main() {
//    printf("%d", compareStr2("aa", "aa"));
    const char *filename = "onegin.txt";
    FILE *fp = fopen(filename, "r");
    if (fp == nullptr) {
        perror("Unable to open file!");
        exit(1);
    }
    // all file in one block
    //size_t length = countLines(fp);
    //Text text = {readFile(fp, length), length};

    Text text = readFile2(fp);

    fclose(fp);

    printf("NOT SORTED\n");
    print(&text);

    printf("\n\nSORTED\n");
    bubbleSort(&text, compareStr);
    print(&text);

    printf("\n\nSORTED BACK\n");
    bubbleSort(&text, compareStrBack);
    print(&text);

    printf("\n");

    return 0;
}
