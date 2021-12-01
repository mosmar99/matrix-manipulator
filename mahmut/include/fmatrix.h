#ifndef _fmatrix_h
#define _fmatrix_h

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>

#define ROWS 3 // rows of matrix
#define COLS 3 // columns of matrix
#define SIZE 128 // used for allocating memory when reading float string 

typedef float fMatrix[ROWS][COLS];

// init 3x3 matrix with value
fMatrix* createMatrix(float value);

// prints 2x2 matrix
void printMatrix(fMatrix *mat);

// frees mallocated matrix memory on heap
void destroyMatrix(fMatrix *mat);

// gets valid input for matrix, returns boolean if successful
bool getMatrix(fMatrix *mat);

// adds matrix_1 and matrix_2 elementwise, stores the res in matrix1
void matadd(fMatrix *mat1, fMatrix *mat2);

// matrix multiply intArray m1 and intArray m2, stores the result in m1
void matmul(fMatrix *m1, fMatrix *m2);

#endif              