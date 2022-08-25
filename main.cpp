#include "utils.h"

int main()
{
    Test tests[] = {
                    {.s = "dhrdhd", .cs = "gseg", .ct="", .c = ' ', .n = 0, .stream = stdin},
                    {.s = "", .cs = "gdhrdagdra", .ct="", .c = 'a', .n = 0, .stream = stdin},
                    {.s = "", .cs = "", .ct="", .c = 'a', .n = 0, .stream = stdin},
    };
    runTests(tests, sizeof(tests) / sizeof(Test));
//
//    printf("Str len: %zu\n", my_strlen(s));
//
//    char str[100] ="qwerty";
//    my_strcpy(str, s);
//    printf("Str: %s\n", str);
//
//    char str2[100] = "123456789";
//    my_strncpy(str2, s, 3);
//    printf("Str2: %s\n", str2);
//
//    char str3[100] = "1234";
//    my_strcat(str3, str);
//    printf("Str3: %s\n", str3);
//
//    char str4[100] = "1234";
//    my_strncat(str4, str, 5);
//    printf("Str4: %s\n", str4);
//
//    char str5[100] = "";
//    my_gets(str5);
//    printf("Str5: %s\n", str5);
//
//    char str6[100] = "";
//    my_fgets(str6, 5, stdin);
//    printf("Str6: %s\n", str6);
//
//    char *str7 = my_strdup("segsehsh");
//    printf("Str7: %s\n", str7);
//
//    char str8[100] = "";
//    my_getline(str8, stdin);
//    printf("Str8: %s\n", str8);
//
//    char str9[100] = "";
//    my_getline(str9, stdin, ';');
//    printf("Str9: %s\n", str9);
    return 0;
}
