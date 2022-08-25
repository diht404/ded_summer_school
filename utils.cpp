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
        const char *s = tests[i].s;
        const char *answer = my_strchr(tests[i].cs, tests[i].c);
        const char *correct = strchr(tests[i].cs, tests[i].c);
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

char *my_strcpy(char *s, const char *ct)
{
    assert(s != nullptr);
    assert(ct != nullptr);

    while (*ct != '\0')
    {
        *s = *ct;
        s++;
        ct++;
    }
    *s = '\0';
    return s;
}
//bool test_strcpy(Test tests[], int length)
//{
//
//}

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

char *my_fgets(char *s, int size, FILE *stream)
{
    assert(s != nullptr);
    assert(stream != nullptr);
    char c = ' ';

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

char *my_strdup(const char *s)
{
    assert(s != nullptr);

    char *str = (char *) malloc(my_strlen(s) + 1);
    my_strcpy(str, s);
    my_strcat(str, "\0");
    return str;
}

char *my_getline(char *s, FILE *stream, char delim)
{

    assert(s != nullptr);
    assert(stream != nullptr);

    char c = ' ';
    while (true)
    {
        c = fgetc(stream);
        if (c == EOF or c == '\n' or c == delim) break;
        *
            s = c;
        s++;
    }
    *
        s = '\0';
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
    printf("Puts() status: %s\n", success ? "PASSED" : "FAILED");

    printf("Testing strlen():\n");
    success = test_strlen(tests, length);
    printf("Puts() status: %s\n", success ? "PASSED" : "FAILED");
}
