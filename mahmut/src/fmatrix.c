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
            *(*(*mat+j)+i) = value;
        }
    }

    return mat;
}

void printMatrix(fMatrix *mat){
    for(int i=0; i<ROWS; i++){    /* Iterate of each row */
        for(int j=0; j<COLS; j++){  /* In each row, go over each col element  */
            printf("%.2lf ",*(*(*mat+j)+i)); /* Print each row element */
        }
        printf("\n");
    }
}

void destroyMatrix(fMatrix *mat){
    if(mat != NULL) free(mat), mat = NULL;
}

// int isfloat (const char *s)
// {
//      char *ep = NULL;
//      double f = strtod (s, &ep);

//      if (!ep  ||  *ep)
//          return false;  // has non-floating digits after number, if any

//      return true;
// }

// bool isValidFloatString(char *str) {
//     char* token = strtok(str, ",");
//     while (token) {
//         printf("token: %s\n", token);
//     }
//     return true;
// }

// void extractPositiveFloats(fMatrix *mat, char *str) {

// }

// bool getMatrix(fMatrix *mat) {
//     // prompt user
//     char str[SIZE];
//     scanf("%127s", str); 
//     //check validity of input: "ui,ui,ui"
//     if (isValidFloatString(str)) {
//         extractPositiveFloats(mat, str);
//     } else {
//         return isValidString(str);
//     }    
// }
