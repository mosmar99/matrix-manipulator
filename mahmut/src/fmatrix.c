#include "fmatrix.h"

fMatrix* createMatrix(float value) {
    fMatrix* mat = malloc(sizeof(fMatrix));
    if (mat == NULL)
    {
        if (errno) 
            perror("failed to allocate memory");
        else
            fprintf(stderr, "%s\n", "Error: failed to allocate memory");

        return NULL;
    }

    // populate mat with values here
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            *(*(*mat+i)+j) = value;
        }
    }

    return mat;
}

void printMatrix(fMatrix *mat){

    for(int i=0; i<ROWS; i++){    /* Iterate of each row */
        for(int j=0; j<COLS; j++){  /* In each row, go over each col element  */
            printf("%8.2lf ",*(*(*mat+i)+j)); /* Print each row element */
        }
        printf("\n");
    }
}

void destroyMatrix(fMatrix *mat){
    if(mat != NULL) free(mat), mat = NULL;
}

bool isValidFloatString(char *str)
{
    char cpydStr[SIZE];
    strncpy(cpydStr, str, SIZE);
    size_t size = strlen(cpydStr);
    if ( *cpydStr == ',' || *cpydStr == '.' || cpydStr[size - 1] == ',' || 
        cpydStr[size - 1] == '.'|| strstr(cpydStr, ",,") != NULL) return false;
    char *token = strtok(cpydStr, ",");
    while (token)
    {
        float tmp;
        if (sscanf(token, "%f", &tmp) != 1)
            return false;
        token = strtok(NULL, ",");
    }
    return true;
}

void extractPositiveFloats(fMatrix *mat, char *str) {
    char *token = strtok(str, ",");
    for (size_t i = 0; i < ROWS && token; i++)
    {
        for (size_t j = 0; j < COLS; j++)
        {
            *(*(*mat+i)+j) = atof(token);
            token = strtok(NULL, ",");
        }
    }  
}

bool getMatrix(fMatrix *mat) {
    // prompt user
    char str[SIZE];
    scanf("%127s", str); 
    //check validity of input: "ui,ui,ui"
    if (isValidFloatString(str)) {
        extractPositiveFloats(mat, str);
        return true;
    } else {
        return false;
    }    
}

void matadd(fMatrix *mat1, fMatrix *mat2) {
    for (size_t i = 0; i < ROWS; i++)
    {
        for (size_t j = 0; j < COLS; j++)
        {
            (*mat1)[i][j] += (*mat2)[i][j];
        }    
    }
}

void matmul(fMatrix *m1, fMatrix *m2) {
    fMatrix *rslt = createMatrix(0.0f);
 
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            ((*rslt)[i][j]) = 0;
 
            for (int k = 0; k < ROWS; k++) {
                ((*rslt)[i][j]) += ((*m1)[i][k]) * ((*m2)[k][j]);
            }
        }
    }

    for (size_t i = 0; i < ROWS; i++)
    {
        for (size_t j = 0; j < COLS; j++)
        {
            (*m1)[i][j] = (*rslt)[i][j];
        }    
    }    
}
