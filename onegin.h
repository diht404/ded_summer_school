#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <cstdio>
#include <unistd.h>
#include <ctype.h>

/**
 * @brief Struct for storing a string and its' length
 */
struct Line
{
    char *str = nullptr;
    long length = 0;
};

/**
 * @brief Struct for storing array of strings, its' length and pointer
 * to memory block with not sorted text(array of string)
 */
struct Text
{
    Line *lines = nullptr;
    size_t length = 0;
    char *txt;
};

Text readFile(FILE *fp);

/**
 * @brief comparator for strings (operator <)
 *
 * @param lhsVoid first string to compare
 * @param rhsVoid second string to compare
 * @return -1 if the first string is smaller,
 * 0 if is equal and
 * 1 if greater than the second string
 */
int compareStr(const void *lhsVoid, const void *rhsVoid);

/**
 * @brief back side comparator for strings (operator <)
 *
 * @param lhsVoid first string to compare
 * @param rhsVoid second string to compare
 * @return -1 if the first string is smaller,
 * 0 if is equal and
 * 1 if greater than the second string
 */
int compareStrBack(const void *lhsVoid, const void *rhsVoid);

/**
 * @brief print array of string to file
 *
 * @param text array of strings and info
 * @param filename name of file to write
 * @param sorted true(default) if sorted print is required or false if not
 */
void printFile(Text *text, const char *filename, bool sorted = true);

/**
 * @brief swap two lines
 *
 * @param lhsVoid first string to swap
 * @param rhsVoid second string to swap
 */
void swapLines(Line *lhs, Line *rhs);

/**
 * @brief partition implementation for qsort with rightmost pivot
 *
 * @param lines pointer to the array to sort
 * @param l the left border of the segment
 * @param r the right border of the segment
 * @param comp comparator for strings
 */
size_t partition(Line *lines, size_t l, size_t r,
                 int (*comp)(const void *, const void *));

/**
 * @brief qsort implementation
 * @param lines pointer to the array to sort
 * @param l the left border of the segment
 * @param r the right border of the segment
 * @param comp comparator for strings
 */
void sort(Line *lines, size_t l, size_t r,
          int (*comp)(const void *, const void *));

/**
 * @brief qsort with signature similar to qsort from stdlib.h
 * @param lines pointer to the array to sort
 * @param count number of elements in the array
 * @param comp comparator for strings
 */
void qSort(Line *lines, size_t count,
           int (*comp)(const void *, const void *));
