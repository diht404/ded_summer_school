#include "onegin.h"
// ctype.h isalnum
Text readFile2(FILE *fp)
{
    fseek(fp, 0, SEEK_END);
    long lenOfFile = ftell(fp);
    rewind(fp);

    char *txt = (char *) calloc(lenOfFile, sizeof(char));
    fread(txt, sizeof(char), lenOfFile, fp);

    size_t countLines = 0;
    for (long i = 0; i < lenOfFile; i++)
    {
        if (txt[i] == '\n')
            countLines++;
    }

    Line *lines = (Line *) calloc(countLines, sizeof (Line));

    long position = 0;
    long line_id = 0;
    size_t length = 0;
    for (long i = 0; i < lenOfFile; i++)
    {
        if (position == 0)
        {
            lines[line_id] = {&txt[i], 0};
        }
        lines[line_id].length++;
        position++;
        if (txt[i]=='\n'){
            position=0;
            txt[i] = '\0';
            line_id++;
        }
    }

    return {lines, lenOfFile};
}
//
//Text readFile(FILE *fp) {
//    size_t txt_size = 0;
//    size_t buffer_size = 0;
//    char c = EOF;
//    size_t txt_capacity = 1;
//    char **txt = (char **) calloc(txt_capacity, sizeof(char *));
//    assert(txt != nullptr);
//    char *buffer = (char *) calloc(128, sizeof(char));
//    assert(buffer != nullptr);
//    while ((c = fgetc(fp)) != EOF) {
//        if (c == '\n') {
//            buffer[buffer_size] = '\0';
//            txt[txt_size] = (char *) calloc(buffer_size, sizeof(char));
//            assert(txt[txt_size] != nullptr);
//            strcpy(txt[txt_size], buffer);
//            if (txt_size >= txt_capacity) {
//                txt = (char **) realloc(txt, txt_capacity * 2 * sizeof(char *));
//                txt_capacity *= 2;
//            }
//            //buffer[0] = '\0';
//            buffer_size = 0;
//            txt_size++;
//        } else {
//            buffer[buffer_size] = c;
//            buffer_size++;
//        }
//    }
//    //buffer[buffer_size] = '\0';
//    txt[txt_size] = (char *) calloc(buffer_size, sizeof(char));
//    assert(txt[txt_size] != nullptr);
//    strcpy(txt[txt_size], buffer);
//    txt_size++;
//    return {txt, txt_size};
//}

char *revStr(char *revstr, char *str) {///
    size_t left = 0;
    size_t right = strlen(str) - 1;
    strcpy(revstr, str);
    for (size_t i = left; i < right; i++) {
        char temp = revstr[i];
        revstr[i] = revstr[right];
        revstr[right] = temp;
        right--;
    }
    return revstr;
}

bool compareStr(char *lhs, char *rhs) {///
    size_t i = 0;
    size_t j = 0;
    while (lhs[i] != '\0' or rhs[j] != '\0') {
        if (lhs[i] == ' ' or lhs[i] == '.' or lhs[i] == ',' or lhs[i] == ',' or
            lhs[i] == '!' or lhs[i] == ';' or lhs[i] == '?' or lhs[i] == ':')
            i++;

        if (lhs[j] == ' ' or lhs[j] == '.' or lhs[j] == ',' or lhs[j] == ',' or
            lhs[j] == '!' or lhs[j] == ';' or lhs[j] == '?' or lhs[i] == ':')
            j++;

        if (lhs[i] == '\0')
            return true;

        if (lhs[j] == '\0')
            return false;

        if (lhs[i] < rhs[j])
            return true;

        if (lhs[i] < rhs[j])
            return false;
        i++;
        j++;
    }
    return false;
}

bool compareStrBack(char *lhs, char *rhs) {
    char *revLhs = (char *) calloc(1, 128);
    revStr(revLhs, lhs);
    char *revRhs = (char *) calloc(1, 128);
    revStr(revRhs, rhs);
    return strcmp(revLhs, revRhs) > 0;
}

void bubbleSort(Text *text, bool (*comparator)(char *lhs, char *rhs)) {
    for (int i = 0; i < text->length - 1; i++) {
        for (int j = 0; j < text->length - i - 1; j++) {
            if (comparator(text->lines[j].str, text->lines[j+1].str)) {
                char *tmp = text->lines[j].str;
                text->lines[j].str = text->lines[j+1].str;
                text->lines[j+1].str = tmp;
            }
        }
    }
}

void print(Text *text) {
    for (size_t i = 0; i < text->length; i++) {
        printf("%s\n", text->lines[i].str);
    }
}
