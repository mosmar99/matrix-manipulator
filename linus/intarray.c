#include "intarray.h"

void printIntArray(const intArray a)
{
    printf("[ ");
    for (; *a != SENTINEL; a++)
    {
        printf("%d ", *a);
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
    size_t t = CAPACITY; // used to prohibit user from entering a list of greater size than CAPACITY
    printf("%s", "Please enter a comma-seperated list of positive integers (e.g. 1,2,3): ");
    scanf("%ts", str);
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