#include "intarray.h"

void printIntArray(intArray array);

int main(void) {
    intArray array = {2,6,8,4,5,SENTINEL};
    printIntArray(array);
    return 0;
}