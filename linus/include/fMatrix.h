#ifndef _FMATRIX_H
#define _FMATRIX_H

#define SIZE 256
#define ROWS 3
#define COLS 3

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

typedef float fMatrix[ROWS][COLS];

// Create an fMatrix with all elements initialized to the value of the argument.
// Function call: fMatrix *matrix = createMatrix(value)
fMatrix *createMatrix(const float);

// Free the memory occupied by an fMatrix. Pointer becomes NULL.
// Function call: free(matrix)
void destroyMatrix(fMatrix *);

// Prints all 9 elements in an fMatrix in a 3x3 grid.
// Function call: printMatrix(matrix)
void printMatrix(const fMatrix const *);

// Prompts the user to input a comma-seperated list of exactly 9 floats.
// Returns true if a valid list is entered, otherwise false.
// Function call: getMatrix(matrix);
bool getMatrix(fMatrix *);

// A helper function to getMatrix(). Checks if a proper list is entered
// by the user and returns true if so, otherwise false
// Funciton call: checkCStr(str)
bool checkCStrMatrix(char *);

// Helper function to checkCStrMatrix(). Checks each token.
// Function call: checkCStrMatrixSubstr(cstr)
bool checkCStrMatrixToken(const char *);

// Helper funktion to getMatrix(). Extracts all floats from a cstr to an fMatrix.
// Function call: extractFloats(&matrix, cstr);
void extractFloats(fMatrix *, char *);

// Helper function to getMatrix(). Copies a string to another (both located on stack. strcpy() ==> ROM ==> Segmentation fault)
// dest and src MUST be of same length and dest static initialized as per char dest[size] = {0}
// Not intended to be used outside of this exact use case as described above.
// Function call: copyStr(dest, src)
void copyStr(char *, char *);

// Adds two fMatrix and stores result in first parameter.
// Function call: matadd(a, b)
void matadd(fMatrix *, fMatrix *);

// Matrix multipication. Stores result in first parameter.
// Function call: matmul(a, b)
void matmul(fMatrix *, fMatrix *);

// Helper function to matmul(). Returns sum of products in a row and col.
// Function call: rowColAdd(a, b, rowA, colB)
float rowColAdd(const fMatrix const *, const fMatrix const *, const size_t, const size_t);

#endif