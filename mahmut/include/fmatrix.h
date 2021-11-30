#ifndef _fmatrix_h
#define _fmatrix_h

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>

#define ROWS 3
#define COLS 3
#define ARRSIZE ROWS*COLS
#define SIZE 128

typedef float fMatrix[ROWS][COLS];

// init 3x3 matrix with value
fMatrix* createMatrix(float value);

// prints 2x2 matrix
void printMatrix(fMatrix *mat);

// frees mallocated matrix memory on heap
void destroyMatrix(fMatrix *mat);

// gets valid input for matrix, returns boolean if successful
bool getMatrix(fMatrix *mat);

#endif              