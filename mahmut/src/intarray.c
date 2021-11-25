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
    scanf("%s", &str); 
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

void appendIntArray(intArray a, intArray b, intArray c) {
    size_t aInC = getIntArraySize(c) - getIntArraySize(a), abInC = getIntArraySize(c) - getIntArraySize(a) - getIntArraySize(b);
    int ctrA = 0, ctrB = 0, ctrC = 0;
    if(abInC > 0) {
        concatArrays(c, a);
    } else { // else add as much as possible
        for(; a[ctrA] != SENTINEL && ctrA < CAPACITY; ctrA++, ctrC++) {
            c[ctrC] = a[ctrA];
        }
    }
    if (abInC > 0) {
        concatArrays(c,b);
    } 
    else if (abInC == 0) {
        fprintf( stderr, "A and B are empty"); 
    } 
    else { // else add as much as possible
        for(; b[ctrB] != SENTINEL || (sizeof(a) + ctrB) < CAPACITY; ctrB++, ctrC++) {
            c[ctrC] = b[ctrB];
        }
    }
}