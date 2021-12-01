#ifndef _INTARRAY_H
#define _INTARRAY_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SENTINEL -1
#define CAPACITY 256

enum SortOrder
{
    ASC,
    DEC
};

enum UniqueValues
{
    NO,
    YES
};

typedef int intArray[CAPACITY];

// Prints all the elements in an intArray before SENTINEL
// Function call: printIntArray({1,2,3,SENTINEL})
void printIntArray(const intArray);

// Returns the number of elements in an intArray before SENTINEL
// Function call: getIntArraySize({1,2,3,SENTINEL})
size_t getIntArraySize(const intArray);

// Prompts the user to input a comma-seperated list of positive integers.
// Returns true if a valid list is entered, otherwise false.
// Function call: getIntArray(a)
bool getIntArray(intArray);

// A helper function to getIntArray(). Checks if a proper list is entered
// by the user and returns true if so, otherwise false
// Funciton call: checkCStr({1,2,3,'\0'})
bool checkCStr(const char *);

// A helper function to checkCStr(). Extracts all the positive integers to an intArray from a cstring.
// Function call: extractIntegers({1,2,3}, cstr)
void extractIntegers(intArray, char *);

// Appends first and second intArray to the third intArray
// Function call: appendIntArray(a, b, c)
void appendIntArray(intArray, intArray, intArray);

// intArray c will contain elements from a and b interleaved,
// i.e. c = {a[0], b[0], a[1], b[1], ...}. Fills remaining space with elements from a or b if
// they are not of same size.
// Function call: interleaveIntArray(a, b, c)
void interleaveIntArray(intArray, intArray, intArray);

// Sorts an intArray given the feedback from user.
// Function call: sortIntArray(a)
void sortIntArray(intArray);

// Sets if sorted list should be in ascending or decsending order.
// Function call: setSortOrder(order)
void setSortOrder(enum SortOrder);

// Sets if sorted list should contain duplicates.
// Function call: setUniqueness(unique)
void setUniqueness(enum UniqueValues);

// Helper function to sortIntArray and reverseIntArray. Swaps two ints.
// Function call: swap(&a, &b)
void swap(int *, int *);

// Helper function to sortIntArray, deletes the element at given index and moves rest of
// the elements 1 step to fill the gap, incl. SENTINEL
// Function call: deleteElement(a, ix)
void deleteElement(intArray, size_t);

// Helper function to sortIntArray. Reverses the order of elements in an intArray, excl. SENTINEL.
// Function call: reverseIntArray(a);
void reverseIntArray(intArray);

#endif