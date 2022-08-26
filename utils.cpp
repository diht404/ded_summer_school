#include "utils.h"

int my_puts(const char *s)
{
    assert(s != nullptr);

    int i = 0;
    while (s[i])
    {
        if (putchar(s[i]) == EOF) return EOF;
        i++;
    }
    if (putchar('\n') == EOF) return EOF;
    return i + 1;
}
bool test_puts(Test tests[], int length)
{
    bool all_success = true;
    for (int i = 0; i < length; i++)
    {
        const char *s = tests[i].s;
        int answer = my_puts(s);
        int correct = puts(s);
        bool success = answer == correct;
        all_success *= success;

        if (!success)
        {
            printf("Test %d FAILED\n", i);
            printf("String: %s Got: %d Expected: %d\n",
                   s,
                   answer,
                   correct);
        }
    }
    return all_success;
}

const char *my_strchr(const char *cs, char c)
{
    assert(cs != nullptr);

    int i = 0;
    while (cs[i])
    {
        if (cs[i] == c) return &cs[i];
        i++;
    }
    return nullptr;
}
bool test_strchr(Test tests[], int length)
{
    bool all_success = true;
    for (int i = 0; i < length; i++)
    {
        const char *cs = tests[i].cs;
        char c = tests[i].c;

        const char *answer = my_strchr(cs, c);
        const char *correct = strchr(cs, c);

        bool success = answer == correct;
        all_success *= success;

        if (!success)
        {
            printf("Test %d FAILED\n", i);
            printf("String: %s Got: %s Expected: %s\n",
                   cs,
                   answer,
                   correct);
        }
    }
    return all_success;
}

size_t my_strlen(const char *cs)
{
    assert(cs != nullptr);

    size_t i = 0;
    while (cs[i])
    {
        i++;
    }
    return i;
}
bool test_strlen(Test tests[], int length)
{
    bool all_success = true;
    for (int i = 0; i < length; i++)
    {
        const char *cs = tests[i].cs;

        size_t answer = my_strlen(cs);
        size_t correct = strlen(cs);

        bool success = answer == correct;
        all_success *= success;
        if (!success)
        {
            printf("Test %d FAILED\n", i);
            printf("String: %s Got: %zu Expected: %zu\n",
                   cs,
                   answer,
                   correct);
        }

    }
    return all_success;
}

char *my_strcpy(char *s, const char *c)
{
    assert(s != NULL && c != NULL);
    char *temp = s;
    while (*s++ = *c++);
    return temp;
}
bool test_strcpy(Test tests[], int length)
{
    bool all_success = true;
    for (int i = 0; i < length; i++)
    {
        // strcpy will make segfault if size is too small!!!
        char s[100] = "";
        const char *ct = tests[i].ct;

        char *answer = my_strcpy(s, ct);
        char *correct = strcpy(s, ct);

        bool success = !strcmp(answer, correct);
        all_success *= success;
        if (!success)
        {
            printf("Test %d FAILED\n", i);
            printf("String: %s Got: %s Expected: %s\n",
                   s,
                   answer,
                   correct);
        }
    }
    return all_success;
}

char *my_strncpy(char *s, const char *ct, size_t n)
{
    assert(s != nullptr);
    assert(ct != nullptr);

    size_t i = 0;

    for (; i < n && ct[i] != '\0'; i++)
        s[i] = ct[i];
    for (; i < n; i++)
        s[i] = '\0';

    return s;
}
bool test_strncpy(Test tests[], int length)
{
    bool all_success = true;
    for (int i = 0; i < length; i++)
    {
        // strncpy will make segfault if size is too small!!!
        char s[100] = "";
        const char *ct = tests[i].ct;
        size_t n = tests[i].n;

        char *answer = my_strncpy(s, ct, n);
        char *correct = strncpy(s, ct, n);

        bool success = !strcmp(answer, correct);
        all_success *= success;

        if (!success)
        {
            printf("Test %d FAILED\n", i);
            printf("String: %s Got: %s Expected: %s\n",
                   s,
                   answer,
                   correct);
        }
    }
    return all_success;
}

char *my_strcat(char *s, const char *ct)
{
    assert(s != nullptr);
    assert(ct != nullptr);

    size_t length = my_strlen(s);
    size_t i = 0;

    for (; ct[i] != '\0'; i++)
        s[length + i] = ct[i];
    s[length + i] = '\0';

    return s;
}
bool test_strcat(Test tests[], int length)
{
    bool all_success = true;
    for (int i = 0; i < length; i++)
    {
        // strcat will make segfault if size is too small!!!
        char s[100] = "";
        const char *ct = tests[i].ct;

        char *answer = my_strcat(s, ct);
        char *correct = strcat(s, ct);

        bool success = answer == correct;
        all_success *= success;
        if (!success)
        {
            printf("Test %d FAILED\n", i);
            printf("String: %s Got: %s Expected: %s\n",
                   s,
                   answer,
                   correct);
        }
    }
    return all_success;
}

char *my_strncat(char *s, const char *ct, size_t n)
{
    assert(s != nullptr);
    assert(ct != nullptr);

    size_t length = my_strlen(s);
    size_t i;

    for (i = 0; i < n && ct[i] != '\0'; i++)
        s[length + i] = ct[i];
    s[length + i] = '\0';

    return s;
}
bool test_strncat(Test tests[], int length)
{
    bool all_success = true;
    for (int i = 0; i < length; i++)
    {
        // strncat will make segfault if size is too small!!!
        char s[100] = "";
        const char *ct = tests[i].ct;
        size_t n = tests[i].n;

        char *answer = my_strncat(s, ct, n);
        char *correct = strncat(s, ct, n);

        bool success = answer == correct;
        all_success *= success;
        if (!success)
        {
            printf("Test %d FAILED\n", i);
            printf("String: %s Got: %s Expected: %s\n",
                   s,
                   answer,
                   correct);
        }
    }
    return all_success;
}

char *my_gets(char *s)
{
    assert(s != nullptr);

    char c = ' ';
    while (c != '\n' and c != EOF)
    {
        c = getchar();
        if (c != EOF)
        {
            *s = c;
            s++;
        }
        if (c == EOF)
        {
            *s = '\0';
        }
    }
    return s;
}
//bool test_gets(Test tests[], int length)
//{
//    bool all_success = true;
//    for (int i = 0; i < length; i++)
//    {
//        char *s = tests[i].s;
//
//        char *answer = my_gets(s);
//        // WHERE IS gets?!
//        char *correct = gets(s);
//
//        bool success = answer == correct;
//        all_success *= success;
//        if (!success)
//        {
//            printf("Test %d FAILED\n", i);
//            printf("String: %s Got: %s Expected: %s\n",
//                   s,
//                   answer,
//                   correct);
//        }
//    }
//    return all_success;
//}

char *my_fgets(char *s, int size, FILE *stream)
{
    assert(s != nullptr);
    assert(stream != nullptr);
    char c = 0;

    size_t i = 0;
    for (; i < size - 1; i++)
    {
        c = fgetc(stream);
        if (c == EOF) break;
        if (c == '\n')
        {
            *s = c;
            break;
        }
        *s = c;
        s++;
    }
    *s = '\0';
    return s;
}
//bool test_fgets(Test tests[], int length)
//{
//    bool all_success = true;
//
//    char answer_s[100] = "";
//    char correct_s[100] = "";
//
//    int size = 5;
//
//    char *answer = my_fgets(answer_s, size, stdin);
//    char *correct = fgets(correct_s, size, stdin);
//
//    int i = 0;
//    while (answer[i] == correct[i] and
//        answer[i] != '\0' and correct[i] != '\0')
//    {
//        i++;
//    }
//    int len = 0;
//    while (correct[len] != '\0')
//    {
//        i++;
//    }
//
//    bool success = i == len;
//    all_success *= success;
//    if (!success)
//    {
//        printf("Test FAILED\n");
//        printf("Got: %d Expected: %d\n",
//               i,
//               len);
//    }
//    return all_success;
//}

char *my_strdup(const char *s)
{
    assert(s != nullptr);

    char *str = (char *) calloc(my_strlen(s) + 1, sizeof(char));
    my_strcpy(str, s);
    my_strcat(str, "\0");
    return str;
}

char *my_getline(char *s, FILE *stream, char delim)
{

    assert(s != nullptr);
    assert(stream != nullptr);

    char c = 0;
    while (true)
    {
        c = fgetc(stream);
        if (c == EOF or c == '\n' or c == delim)
            break;

        *s++ = c;
    }

    *s = '\0';
    return
        s;
}

void runTests(Test tests[], int length)
{
    bool success = false;

    printf("Testing puts():\n");
    success = test_puts(tests, length);
    printf("Puts() status: %s\n", success ? "PASSED" : "FAILED");

    printf("Testing strchr():\n");
    success = test_strchr(tests, length);
    printf("strchr() status: %s\n", success ? "PASSED" : "FAILED");

    printf("Testing strlen():\n");
    success = test_strlen(tests, length);
    printf("strlen() status: %s\n", success ? "PASSED" : "FAILED");

    printf("Testing strcpy():\n");
    success = test_strcpy(tests, length);
    printf("strcpy() status: %s\n", success ? "PASSED" : "FAILED");

    printf("Testing strncpy():\n");
    success = test_strncpy(tests, length);
    printf("strncpy() status: %s\n", success ? "PASSED" : "FAILED");

    printf("Testing strcat():\n");
    success = test_strcat(tests, length);
    printf("strcat() status: %s\n", success ? "PASSED" : "FAILED");

    printf("Testing strncat():\n");
    success = test_strncat(tests, length);
    printf("strncat() status: %s\n", success ? "PASSED" : "FAILED");

//    printf("Testing gets():\n");
//    success = test_gets(tests, length);
//    printf("gets() status: %s\n", success ? "PASSED" : "FAILED");

//    printf("Testing fgets():\n");
//    success = test_fgets(tests, length);
//    printf("fgets() status: %s\n", success ? "PASSED" : "FAILED");

}
