#include "intarray.h"
#include "fMatrix.h"

void printMenu();
void applyChoice(unsigned short);
void doAppIntArrays();
void doIntlevIntArrays();
void doSortIntarray();
void doMatAdd();
void doMatMul();

int main()
{
    unsigned short choice = 0;
    printMenu();
    while (choice != 7)
    {
        printf("\n?: ");
        fflush(stdin);
        scanf("%1d[1234567]", &choice);
        applyChoice(choice);
    }
}

void printMenu()
{
    puts("== Main Menu ==");
    puts("1. Append two integer arrays.");
    puts("2. Interleave two integer arrays.");
    puts("3. Sort an integer array.");
    puts("4. Add two 3x3 float matrices.");
    puts("5. Multiply two 3x3 float matrices.");
    puts("6. Print Main Menu.");
    puts("7. Quit.");
}

void applyChoice(unsigned short choice)
{
    switch (choice)
    {
    case 1:
        doAppIntArrays();
        break;
    case 2:
        doIntlevIntArrays();
        break;
    case 3:
        doSortIntarray();
        break;
    case 4:
        doMatAdd();
        break;
    case 5:
        doMatMul();
        break;
    case 6:
        printMenu();
        break;
    default:
        puts("Error: invalid choice");
        break;
    }
}

void doAppIntArrays()
{
    intArray srs1, srs2, res;
    printf("Enter first array: ");
    getIntArray(srs1);
    printf("Enter second array: ");
    getIntArray(srs2);
    printf("Result:\n");
    appendIntArray(srs1, srs2, res);
    printIntArray(res);
}

void doIntlevIntArrays()
{
    intArray srs1, srs2, res;
    printf("Enter first array: ");
    getIntArray(srs1);
    printf("Enter second array: ");
    getIntArray(srs2);
    printf("Result:\n");
    interleaveIntArray(srs1, srs2, res);
    printIntArray(res);
}

void doSortIntarray()
{
    intArray arr;
    unsigned int order, unique;
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

void doMatAdd()
{
    fMatrix *m1 = createMatrix(0.0f), *m2 = createMatrix(0.0f);
    printf("Please enter a comma-separated list of 9 floats: ");
    getMatrix(m1);
    printf("Please enter a comma-separated list of 9 floats: ");
    getMatrix(m2);
    matadd(m1, m2);
    printf("Result:\n");
    printMatrix(m1);
    destroyMatrix(m1);
    destroyMatrix(m2);
}

void doMatMul()
{
    fMatrix *m1 = createMatrix(0.0f), *m2 = createMatrix(0.0f);
    printf("Please enter a comma-separated list of 9 floats: ");
    getMatrix(m1);
    printf("Please enter a comma-separated list of 9 floats: ");
    getMatrix(m2);
    matmul(m1, m2);
    printf("Result:\n");
    printMatrix(m1);
    destroyMatrix(m1);
    destroyMatrix(m2);
}
