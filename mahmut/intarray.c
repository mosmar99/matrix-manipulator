#include "intarray.h"

void printIntArray(intArray array) {
    unsigned int i = 0;
    while (*(array+i) != SENTINEL) {
        printf("%d ", *(array+i));
        i++;
    }
}