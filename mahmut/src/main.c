#include "intarray.h"
#include "fmatrix.h"

void mainMenu() {
    char s0[64] = "\n== Main Menu ==";
    char s1[64] = "1. Append two integer arrays.";
    char s2[64] = "2. Interleave two integer arrays.";
    char s3[64] = "3. Sort an integer array.";
    char s4[64] = "4. Add two 3x3 float matrices.";
    char s5[64] = "5. Multiply two 3x3 float matrices.";
    char s6[64] = "6. Print Main Menu";
    char s7[64] = "7. Quit";
    char sChoice[64] = "?: ";
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n%s", s0, s1, s2, s3, s4, s5, s6, s7, sChoice);
}

void appArrs() {
    intArray srs1, srs2, res;
    printf("Enter first array: ");
    getIntArray(srs1);
    printf("Enter second array: ");
    getIntArray(srs2);
    printf("Result:\n");
    appendIntArray(srs1, srs2, res);
    printIntArray(res);
}

void interleave() {
    intArray srs1, srs2, res;
    printf("Enter first array: ");
    getIntArray(srs1);
    printf("Enter second array: ");
    getIntArray(srs2);
    printf("Result:\n");
    interleaveIntArray(srs1, srs2, res);
    printIntArray(res);
}

void sortArr() {
    intArray arr; unsigned int order, unique;
    printf("Enter array: ");
    getIntArray(arr);
    printf("Enter Sort order (%d) ASC, (%d) DESC: ", 0, 1);
    scanf("%u", &order);
    setSortOrder(order);
    printf("Unique values (%d) No, (%d) Yes: ", 0, 1);
    scanf("%u", &unique);
    setUniqueness(unique);
    sortIntArray(arr);
    printIntArray(arr);
}

void addFloatMat() {
    fMatrix *m1 = createMatrix(0.0f), *m2 = createMatrix(0.0f);
    printf("Please enter a comma-separated list of 9 floats: ");
    getMatrix(m1);
    printf("Please enter a comma-separated list of 9 floats: ");
    getMatrix(m2);
    matadd(m1,m2);
    printf("Result:\n");
    printMatrix(m1);
    destroyMatrix(m1); destroyMatrix(m2);
}

void matrixMult() {
    fMatrix *m1 = createMatrix(0.0f), *m2 = createMatrix(0.0f);
    printf("Please enter a comma-separated list of 9 floats: ");
    getMatrix(m1);
    printf("Please enter a comma-separated list of 9 floats: ");
    getMatrix(m2);
    matmul(m1,m2);
    printf("Result:\n");
    printMatrix(m1);
    destroyMatrix(m1); destroyMatrix(m2);
}

void applyChoice(unsigned int choice) {
    switch (choice)
    {
    case 1:
        appArrs();
        mainMenu();
        break;
    case 2:
        interleave();
        mainMenu();
        break;
    case 3:
        sortArr();
        mainMenu();
        break;
    case 4:
        addFloatMat();
        mainMenu();
        break;
    case 5:
        matrixMult();
        mainMenu();
        break;
    case 6:
        mainMenu();
        break;
    }
}

int main(void) {
    
    mainMenu();
    unsigned int choice = 0; 
    while( choice != 7 ) {
        scanf("%d", &choice);
        if (
        choice == 1 || choice == 2 || choice == 3 || choice == 4 ||
        choice == 5 || choice == 5 || choice == 6) {applyChoice(choice);}
    }
}












