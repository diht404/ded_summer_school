#include "utils.h"

int main()
{
    Test tests[] = {
                    {.s = "dhrdhd", .cs = "gseg", .ct="", .c = ' ', .n = 0, .stream = stdin},
                    {.s = "", .cs = "gdhrdagdra", .ct="", .c = 'a', .n = 0, .stream = stdin},
                    {.s = "", .cs = "", .ct="", .c = 'a', .n = 0, .stream = stdin},
                    {.s = "dhrdhd", .cs = "gseg", .ct="", .c = ' ', .n = 3, .stream = stdin},
                    {.s = "", .cs = "gdhrdagdra", .ct="", .c = 'a', .n = 100, .stream = stdin},
                    {.s = "", .cs = "", .ct="", .c = 'b', .n = 0, .stream = stdin},
                    {.s = "gsse/n", .cs = "", .ct="", .c = 'b', .n = 0, .stream = stdin},
    };
    runTests(tests, sizeof(tests) / sizeof(Test));

    char str5[100] = "";
    my_gets(str5);
    printf("Str5: %s\n", str5);

    char str6[100] = "";
    my_fgets(str6, 5, stdin);
    printf("Str6: %s\n", str6);

    char *str7 = my_strdup("segsehsh");
    printf("Str7: %s\n", str7);

    char str8[100] = "";
    my_getline(str8, stdin);
    printf("Str8: %s\n", str8);

    char str9[100] = "";
    my_getline(str9, stdin, ';');
    printf("Str9: %s\n", str9);
    return 0;
}
