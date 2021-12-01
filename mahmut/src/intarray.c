#include "intarray.h"

static enum SortOrder sortOrder = ASCENDING;
static enum Uniqueness uniqueness = NONUNIQUE;

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

bool isValidIntString(char *str) {
    char cpydStr[CAPACITY];
    strncpy(cpydStr, str, CAPACITY);
    size_t size = strlen(cpydStr);
    if ( *cpydStr == ',' || *cpydStr == '.' || cpydStr[size - 1] == ',' || 
        cpydStr[size - 1] == '.'|| strstr(cpydStr, ",,") != NULL) return false;
    char *token = strtok(cpydStr, ",");
    while (token)
    {
        int tmp;
        if (sscanf(token, "%d", &tmp) != 1) return false;
        if (sscanf(token, "%d", &tmp) == 1) {
            int tmp2 = atoi(token);
            if(tmp2 <= 0) return false; }
        token = strtok(NULL, ",");
    }
    return true;    
}

void extractPositiveInts(intArray array, char str[]){
    size_t index = 0;
    char *strPtr = str;
    for (; *strPtr != '\0'; str++, index++)
    {
        array[index] = strtoul(str, &strPtr, 10); // no need to check if strtoul returns 0 since str is already verified
        str = strPtr;
    }
    array[index] = SENTINEL;
}

bool getIntArray(intArray array) {
    // prompt user
    char str[CAPACITY];
    scanf("%63s", str); 
    //check validity of input: "ui,ui,ui"
    if (isValidIntString(str)) {
        extractPositiveInts(array, str);
        printIntArray(array);
    } else {
        array[0] = SENTINEL;
        printIntArray(array);
        return isValidIntString(str);
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

void interleaveIntArray(intArray srs1, intArray srs2, intArray res) {
    bool notTwoSentinel = true, srs1Bool = true, srs2Bool = true;
    int countSentinels = 0;
    for(; notTwoSentinel; srs1++, srs2++, res++) {
        if (*srs1 == SENTINEL && srs1Bool) countSentinels++, srs1Bool = false;
        if (*srs2 == SENTINEL && srs2Bool) countSentinels++, srs2Bool = false;
        if (countSentinels == 2) notTwoSentinel = false;
        if(srs1Bool) {
            *res = *srs1;
        } 
        if(srs2Bool) {
            if(srs1Bool) res++, *res = *srs2;
            else *res = *srs2;
        }
    }
    *(res-1) = SENTINEL; // since we increment the pointer before checking to end loop
}

// Swapping algorithm
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partitioning algorithm
int partition(int *L, int left, int right)
{
    int pivot = left;
    int p_val = L[pivot];

    while (left < right)
    {
        while (L[left] <= p_val)
            left++;
        while (L[right] > p_val)
            right--;
        if (left < right)
            swap(&L[left], &L[right]);
    }
    swap(&L[pivot], &L[right]);
    return right;
}

// Quicksort recursion
void quicksort(int *L, int start, int end)
{
    if (start >= end)
        return;
    //dump_list("PRE-PARTITION", L, start, end);
    int splitPoint = partition(L, start, end);
    //dump_list("POST-PARTITION", L, start, end);
    //printf("Split point: %d\n", splitPoint);
    quicksort(L, start, splitPoint - 1);
    quicksort(L, splitPoint + 1, end);
}

void setSortOrder(enum SortOrder orderChoice) {
    sortOrder = orderChoice;
}

void setUniqueness(enum Uniqueness uniquenessChoice) {
    uniqueness = uniquenessChoice;
}

void deleteDuplicate(intArray arr, int size) {  
    int i, j, k;       // Loop control variables: k = size of new arr, i & j = loop vars
    for(i=0; i<size; i++)
    {
        for(j=i+1; j<size; j++)
        {
            /* If any duplicate found */
            if(arr[i] == arr[j])
            {
                /* Delete the current duplicate element */
                for(k=j; k < size; k++)
                {
                    arr[k] = arr[k + 1];
                }

                /* Decrement size after removing duplicate element */
                size--;

                /* If shifting of elements occur then don't increment j */
                j--;
            }
        }
    }  
    if(sortOrder == ASCENDING) *(arr+k-1) = SENTINEL; 
    else *(arr+k) = SENTINEL; 
}  

void reverseArray(int arr[], int size)
{
    for (int i = 0; i < size/2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size - i];
        arr[size - i] = temp;
    }
}

void sortIntArray(intArray arr) {
    size_t size = getIntArraySize(arr) - 1;
    quicksort(arr, 0, size);

    if(sortOrder) reverseArray(arr, size);
    if(uniqueness) deleteDuplicate(arr, size);
}