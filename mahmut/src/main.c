#include "intarray.h"
#include "fmatrix.h"

bool isValidFloatString(char *str) {
    char* token = strtok(str, ",");
    while (token) {
        printf("token: %s\n", token);
    }
    return true;
}


int main(void) {
    isValidFloatString("12312,123,23,551,2,44");

    // ----- PART 1 -----
    // task 1
    // intArray array = {2,6,8,4,5,SENTINEL};
    // printIntArray(array);
    
    // task 2
    // intArray arr = {2,6,8,SENTINEL};
    // printf("%lu\n", getIntArraySize(arr));

    // // task 3
    // intArray a = {0};
    // bool b;
    // printf("Please enter a comma-separated list of positive integers: ");
    // b = getIntArray(a);

    // task 4
    // intArray a = {2,6,8,4,5,SENTINEL}, b = {3,4,6,7,9,SENTINEL}, c;
    // appendIntArray(a,b,c);
    // printIntArray(c);

    // task 5
    // intArray a = {6,7,9,6,SENTINEL}, b = {3,5,SENTINEL}, c;
    // interleaveIntArray(a,b,c);
    // printIntArray(c);
    // return 0;

    // task 6
    // intArray a = {6,7,9,12,3,5,6,9,5,7,10,12,SENTINEL};
    // setSortOrder(ASCENDING); setUniqueness(NONUNIQUE);
    // sortIntArray(a); printIntArray(a);

    // ----- PART 2 -----
    // fMatrix *m = createMatrix(0.0f); 
    // printMatrix(m);
    // destroyMatrix(m);
    // getMatrix(m);

}











