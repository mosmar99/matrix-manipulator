#include "intarray.h"

void printIntArray(const intArray array) {
    printf("[ ");
    int i = 0;
    while (*(array+i) != SENTINEL) {
        printf("%d ", *(array+i));
        i++;
    }
    printf("]\n");
}

size_t getIntArraySize(const intArray array) {
    size_t i = 1;
    while (*(array+i) != SENTINEL) {
        i++;
    }
    return i;
}

bool isValidString(char str[]) {
    int ctr = 0, currInt;
    for(; str[ctr] != '\0'; ctr++) { // loop until null terminator is hit
        currInt = (int) *(str+ctr); // convert curr string to int
        if (ctr % 2 == 0) // the first value should be a number, the one after a comma, split in two cases
        {
            if (currInt < 49 && currInt > 57) // check if currInt is not a number using ASCII, odd numbered index
            {
                return false;
            }
        } else {
            if (currInt != 44) { // check if currInt is not a comma using ASCII, even numbered index
                return false;
            }
        }
    }
    if ( *(str+ctr-1) == ',') // "1,2,3," is left valid by above, check if ',' is before the sentinel, otherwise valid
    {
        return false;
    }
    return true;
}

void extractPositiveInts(intArray array, const char str[]){
    int ctr = 0, arrIdx = 0;
    for(; str[ctr] != '\0'; ctr++) {
        if (ctr % 2 == 0)
        {
            array[arrIdx] = (int) str[ctr] - 48; // convert from string to ASCII then to int values
            arrIdx++;
        }
    }
    array[arrIdx] = SENTINEL; 
}

bool getIntArray(intArray array) {
    // prompt user
    char str[CAPACITY];
    scanf("%s", str); 
    //check validity of input: "ui,ui,ui"
    if (isValidString(str)) {
        extractPositiveInts(array, str);
        printIntArray(array);
    } else {
        array[0] = SENTINEL;
        printIntArray(array);
        return isValidString(str);
    }
}

void appendIntArray(intArray srs1, intArray srs2, intArray res) {
    int ctr = 0;
    for(; *srs1 != SENTINEL && (ctr < (CAPACITY-1)); res++, srs1++, ctr++)  // add first source to output given conds
        *res = *srs1;
    for(; *srs2 != SENTINEL && (ctr < (CAPACITY-1)); res++, srs2++, ctr++) // add second source to output given conds
        *res = *srs2;
    *res = SENTINEL;   
}

// void interleaveIntArray(intArray a, intArray b, intArray c) {

// }