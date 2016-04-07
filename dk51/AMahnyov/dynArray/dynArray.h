#ifndef DYNARRAY_H_INCLUDED
#define DYNARRAY_H_INCLUDED
#include <stdio.h>
typedef struct tagSubArray subArray;
typedef struct tagDynArray dynamicArray;

typedef struct tagSubArray{
    int *storage;
    int subSize;
    subArray *nextArray;
}subArray;

typedef struct tagDynArray{
    subArray *firstSub;
    subArray *lastSub;
    int arrSize;
}dynamicArray;

dynamicArray *createDynArray(int aSize);
void freeDynArray(dynamicArray *anArray);

subArray *createSubArray(int aSize);
void freeSubArray(subArray *anArray);

subArray *addSub(dynamicArray *anArray, subArray *aSub);

void writeToDA(dynamicArray *anArray, int index, int value);

int readFromDA(dynamicArray *anArray, int index);
#endif // DYNARRAY_H_INCLUDED
