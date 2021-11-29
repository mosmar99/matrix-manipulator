#include "intarray.h"

void printIntArray(const intArray a)
{
    printf("[");
    for (; *a != SENTINEL; a++)
    {
        printf(" %d ", *a);
    }
    printf("]\n");
}

size_t getIntArraySize(const intArray a)
{
    size_t size = 0;
    for (; *a != SENTINEL; a++)
    {
        size++;
    }
    return size;
}

bool getIntArray(intArray a)
{
    char str[CAPACITY];
    printf("%s", "Please enter a comma-seperated list of positive integers (e.g. 1,2,3): ");
    scanf("%s", str);
    if (checkCStr(str))
    {
        extractIntegers(a, str);
        return true;
    }
    else
    {
        *a = SENTINEL;
        return false;
    }
}

bool checkCStr(const char *str)
{
    if (*str == ',') // checks the first element
    {
        return false;
    }

    for (; *str != '\0'; str++)
    {
        if ((*str == ',' && !isdigit(*(str - 1))) || *str == '-') // if the predecessor of a ',' is not a digit OR if a negative sign is detected
        {
            return false;
        }
    }

    if (*(str - 1) == ',') // checks the last element before SENTINEL
    {
        return false;
    }

    return true;
}

void extractIntegers(intArray a, char *str)
{
    size_t index = 0;
    char *strPtr = str;
    for (; *strPtr != '\0'; str++, index++)
    {
        a[index] = strtoul(str, &strPtr, 0);
        str = strPtr;
    }
    a[index] = SENTINEL;
}

void appendIntArray(intArray a, intArray b, intArray c)
{
    size_t aSize = getIntArraySize(a);
    size_t bSize = getIntArraySize(b);
    size_t aIndex = 0;
    size_t bIndex = 0;

    size_t i = 0;
    for (; i < CAPACITY - 1 && (aIndex < aSize || bIndex < bSize); i++) // first condition ensure truncating is not needed
    {
        if (aIndex < aSize) // first copies all elements from intArray a (excl. SENTINEL) to intArray c
        {
            c[i] = a[aIndex++];
        }
        else if (bIndex < bSize) // then copies all elements from intArray a (excl. SENTINEL) to intArray c
        {
            c[i] = b[bIndex++];
        }
    }
    c[i] = SENTINEL;
}

void interleaveIntArray(intArray a, intArray b, intArray c)
{
    size_t aSize = getIntArraySize(a);
    size_t bSize = getIntArraySize(b);
    size_t aIndex = 0;
    size_t bIndex = 0;

    size_t i = 0;
    for (; i < CAPACITY - 1 && aIndex < aSize && bIndex < bSize; i++) // loop until either intArray a or intArray b is done being copied or reached CAPACITY
    {
        if (i % 2)
        {
            c[i] = b[bIndex++];
        }
        else
        {
            c[i] = a[aIndex++];
        }
    }

    for (; i < CAPACITY - 1 && (aIndex < aSize || bIndex < bSize); i++) // then continue copying from either intArray a or intArray b
    {
        if (aIndex < aSize) // intArray b is smaller than intArray a
        {
            c[i] = a[aIndex++];
        }
        else if (bIndex < bSize) // intArray a is smaller than intArray b
        {
            c[i] = b[bIndex++];
        }
    }
    c[i] = SENTINEL;
}