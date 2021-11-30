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

bool getMatrix(fMatrix *);

// A helper function to getMatrix(). Checks if a proper list is entered
// by the user and returns true if so, otherwise false
// Funciton call: checkCStr(str)
bool checkCStrMatrix(char *);

// Helper function to checkCStrMatrix(). Checks each token.
// Function call: checkCStrMatrixSubstr(cstr)
bool checkCStrMatrixSubstr(const char *);

// Helper funktion to getMatrix(). Extracts all floats from a cstr to an fMatrix.
// Function call: extractFloats(&matrix, cstr);
void extractFloats(fMatrix *, char *);

#endif