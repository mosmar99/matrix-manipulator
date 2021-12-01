#include "intarray.h"

static enum SortOrder ORDER = ASC;
static enum UniqueValues UNIQUE = NO;

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
    char str[CAPACITY - 1];
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
    { // if non-number, only ',' is valid  OR  if a ',' is not precessed by a digit
        if ((!isdigit(*str) && *str != ',') || (*str == ',' && !isdigit(*(str - 1))))
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
        a[index] = strtoul(str, &strPtr, 0); // no need to check if strtoul returns 0 since str is already verified
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

void sortIntArray(intArray a)
{
    size_t size = getIntArraySize(a);
    // Bubble sort
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < size - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
            }
        }
    }

    if (UNIQUE)
    {
        for (size_t i = 0; i < size - 1; i++)
        {
            if (a[i] == a[i + 1])
            {
                deleteElement(a, (i--) + 1);
                size--;
            }
        }
    }

    if (ORDER)
    {
        reverseIntArray(a);
    }
}

void setSortOrder(enum SortOrder order)
{
    ORDER = order;
}

void setUniqueness(enum UniqueValues unique)
{
    UNIQUE = unique;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void deleteElement(intArray a, size_t ix)
{
    size_t size = getIntArraySize(a);
    if (ix > size)
    {
        return;
    }

    for (; ix < size; ix++)
    {
        a[ix] = a[ix + 1];
    }
    a[ix] = 0; // not necessary but makes the old SENTINEL to 0
}

void reverseIntArray(intArray a)
{
    size_t size = getIntArraySize(a);
    for (size_t ix1 = 0, ix2 = size - 1; ix1 < size / 2; ix1++, ix2--)
    {
        swap(&a[ix1], &a[ix2]);
    }
}