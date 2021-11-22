#include "intarray.h"
#include <stdio.h>

void printIntArray(intArray array) {
    int i = 0;
    while (*(array+i) == SENTINEL) {
        printf("%d ", *(array+i));
        i++;
    }
}