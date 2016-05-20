#ifndef DArray_h
#define DArray_h

#include <stdio.h>

typedef struct __DynamicArray
{
	int *storage;
	int physicalSize;
	int logicalSize;
    short store;
    DynamicArray.store=0;//flag of storage validity

}DynamicArray;

DynamicArray *CreateArr(int aSize);
void SetFree(DynamicArray *InArr);

int IndexVal(int anIndex,DynamicArray *InArr);
void setIndexVal(int anValue, int anIndex,DynamicArray *InArr);


int infofunc(DynamicArray *InArr);
#endif /* DArray_h */
