#include "intarray.h"
#include <stdio.h>

void printIntArray(intArray array) {
    int i = 0;
    while (*(array+i) != SENTINEL) {
        printf("%d ", *(array+i));
        i++;
    }
}

int getIntArraySize(intArray array) {
    int i = 1;
    while (*(array+i) != SENTINEL) {
        i++;
    }
    return i;
}