#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <cstdio>

struct Test
{
    char *s;
    const char *cs = "0987654321";
    const char *ct = "0987654321";
    char c = ' ';
    size_t n = 0;
    FILE *stream = stdin;
};

/**
 * @brief Puts string to stdin
 * @param s contain string to put in stdin
 * @return 1 if success, EOF if EOF occurred
 */
int my_puts(const char *s);
bool test_puts(Test test);

/**
 * @brief returns a pointer to the first occurrence of the character c
 * in the string s.
 * @param cs - string for search
 * @param c - character for search
 * @return a pointer to the first occurrence of the character c
 */
const char *my_strchr(const char *cs, char c);
bool test_strchr(Test tests[], int length);

/**
 * @brief Count len of string
 * @param cs - string to count len
 * @return len of string
 */
size_t my_strlen(const char *cs);
bool test_strlen(Test tests[], int length);

/**
 * @brief copy from ct to s
 *
 * function copies the string pointed to by ct, including
 * the terminating null byte ('\0'), to the buffer pointed to by s.
 * The strings may not overlap, and the destination string s must be
 * large enough to receive the copy.
 * @param s - string for copy to
 * @param ct - string for copy from
 * @return pointer to s
 */
char *my_strcpy(char *s, const char *ct);
bool test_strcpy(Test tests[], int length);

/**
 * @brief function is similar to my_strcpy,
 * except that at most n bytes of src are copied.
 * @param s - string for copy to
 * @param ct - string for copy from
 * @return pointer to s
 */
char *my_strncpy(char *s, const char *ct, size_t n);
bool test_strncpy(Test tests[], int length);


/**
 * @brief concatenate s and ct and write to s
 * function appends the src string to the dest string,
 * over‐writing the terminating null byte ('\0') at the end of dest,
 * and then adds a terminating null byte. The strings may not overlap,
 * and the dest string must have enough space for the result.
 * @param s - first element for concatenation
 * @param ct - second element for concatenation
 * @return pointer to s
 */
char *my_strcat(char *s, const char *ct);
bool test_strcat(Test tests[], int length);


/**
 * @brief concatenate s and ct and write to s
 * The my_strncat() function is similar, except that:
 * it will use at most n bytes from s; and
 * s does not need to be null-terminated if it contains n or more bytes.
 * @param s - first element for concatenation
 * @param ct - second element for concatenation
 * @param n - max len of s
 * @return pointer to s
 */
char *my_strncat(char *s, const char *ct, size_t n);
bool test_strncat(Test tests[], int length);


/**
 * @brief reads a line from stdio to buffer
 * Reads a line from stdin into the buffer pointed to by s until
 * either a terminating newline or EOF, which it replaces with a null byte
 * ('\0'). No check for buffer overrun is performed (see BUGS below).
 * @param s -
 * @return
 */
char *my_gets(char *s);
bool test_gets(Test tests[], int length);


/**
 * @brief reads line from FILE
 * Reads in at most one less than size characters from stream and
 * stores them into the buffer pointed to by s. Reading stops after an
 * EOF or a newline. If a newline is read, it is stored into the buffer.
 * A terminating null byte ('\0') is stored after the last character in
 * the buffer.

 * @param s - pointer to string to place
 * @param size - max size of line
 * @param stream - FILE to read from
 * @return pointer to string to s
 */
char *my_fgets(char *s, int size, FILE *stream);
bool test_fgets(Test tests[], int length);

/**
 * @brief Allocate memory for string
 * @param s - pointer on string for storing data
 * @return pointer to s
 */
char *my_strdup(const char *s);
bool test_strdup(Test tests[], int length);


/**
 * gets line from FILE
 * @param s - pointer to string
 * @param stream - FILE to read from
 * @param delim - delimiter to read until
 * @return pointer to s
 */
char *my_getline(char *s, FILE *stream, char delim=EOF);
bool test_getline(Test tests[], int length);


/**
 * @brief Tests program
 * @param tests array of test data
 * @param length number of tests
 * @return error code
 */
void runTests(Test tests[], int length);

