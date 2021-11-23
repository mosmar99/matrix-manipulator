// Module contains useful functions for working with integer arrays that are 
// allocated on the program's stack memory. All elements in the array are positive
// integers, with the exception of one special element with the value -1, which acts
// a SENTINEL (terminator) for the end of the array (compare to \0 for strings)
// Arrays have a constant length. not dynamic. 

// Actual length of an array (#slots in arr)= CAPACITY
// Effective length of an array (#slots used in arr) = size


#ifndef _intarray_h
#define _intarray_h

#define SENTINEL -1
#define CAPACITY 256

typedef int intArray[CAPACITY];

// Comment



#endif /* _intarray_h */
