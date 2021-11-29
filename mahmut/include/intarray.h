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

#define SENTINEL -1
#define CAPACITY 64

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
bool isValidString(char str[]);

// concatenates two arrays, a and b onto c, such as: a = [1,2, SENTINEL], b = [3, SENTINEL]
// output: --> c = [1,2,3, SENTINEL]
void appendIntArray(intArray a, intArray b, intArray c);

// takes inputs from array a, puts first element in array c, then takes first element in b and puts it in second element of c
// continues above until both lists been exhaustive iterated through
void interleaveIntArray(intArray srs1, intArray srs2, intArray res);

#endif /* _intarray_h */
