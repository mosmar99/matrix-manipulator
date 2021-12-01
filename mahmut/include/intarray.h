// Module contains useful functions for working with integer arrays that are 
// allocated on the program's stack memory. All elements in the array are positive
// integers, with the exception of one special element with the value -1, which acts
// a SENTINEL (terminator) for the end of the array (compare to \0 for strings)
// Arrays have a constant length. not dynamic. 

// Actual length of an array (#slots in arr)= CAPACITY
// Effective length of an array (#slots used in arr) = size


#ifndef _intarray_h
#define _intarray_h

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SENTINEL -1 // used for terminating int arrays, compare with '\0' for string inputs
#define CAPACITY 64 // maximum slots allocated for intArray

// used as option in sorting algorithm (quicksort), defualt sorts int array in ascending order, with option for descending order
enum SortOrder {
    ASCENDING,
    DESCENDING
};

// used as option in sorting algorithm (quicksort), defualt allows nonunique elements with options for deletion
enum Uniqueness {
    NONUNIQUE,
    UNIQUE
};

// an integer array capable of storing 64 slots
typedef int intArray[CAPACITY];

// inputs: 1D-array, outputs: prints the array to stdin in format [ el1 el2 .. eln ]'
// EX: [2,6,8,4,5,SENTINEL] -> [ 2 6 8 4 5 ]
void printIntArray(const intArray array);

// inputs: 1D-array, outputs: gets the effective size of the array, terminated with SENTINEL
// EX: -> [2,6,8,SENTINEL] -> 3
size_t getIntArraySize(const intArray array);

// checks if valid input, i.e. comma seperated integers
// EX1: "1,2,3" -> [1,2,3] | EX2: ",,1,2" -> [ ]
bool getIntArray(intArray array);

// checks if entered string is on format "ui,ui,ui"
// EX1: "1,2,3" -> true | EX2: ",,1,2" -> false
bool isValidIntString(char str[]);

// concatenates two arrays, a and b onto c, such as: a = [1,2, SENTINEL], b = [3, SENTINEL]
// output: --> c = [1,2,3, SENTINEL]
void appendIntArray(intArray a, intArray b, intArray c);

// takes inputs from array a, puts first element in array c, then takes first element in b and puts it in second element of c
// continues above until both lists been exhaustive iterated through
void interleaveIntArray(intArray srs1, intArray srs2, intArray res);

// --- quicksort functions ---
// swaps the values of two ints, say a = 1, b = 2, swap(a, b)
// -> a = 2, b = 1
void swap(int *a, int *b);

// first, pick a pivot element, rearrange the other elements with respect to the pivot, put the pivot back
// two unsorted sublists remain, they are the ones partitioned by partition
int partition(int *L, int left, int right);
void quicksort(int *L, int start, int end);
// end of quicksort functions

// sets whether the array should be sorted by ASCENDING (0) or DESCENDING (1)
// ASCENDING is defualt
void setSortOrder(enum SortOrder orderChoice);

// sets whether the array elements should be NONUNIQUE (0) or UNIQUE (1)
// NONUNIQUE is defualt
void setUniqueness(enum Uniqueness uniquenessChoice);

// deletes duplicated elements in array
// EX: [1,2,2,3] -> [1,2,3]
void deleteDuplicate (intArray arr, int size);

// sorts an array using quicksort algorithm with optional specificers with respect to ORDER and UNIQUENESS
void sortIntArray(intArray arr);

#endif /* _intarray_h */
