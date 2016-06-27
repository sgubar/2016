#ifndef DynamicArray_h
#define DynamicArray_h

#include <stdio.h>
typedef struct __dynamicIntArray
{
	int *storage;
	int physicalSize;
	int logicalSize;
}
DynamicIntArray;

DynamicIntArray *createDAInt(int aSize);
void freeDAInt(DynamicIntArray *anArray);

int valueAtIndex(int anIndex,DynamicIntArray *anArray);
void setValueAtIndex(int anValue, int anIndex,DynamicIntArray *anArray);

int infofunc( DynamicIntArray *DynArr);

#endif /* DynamicArray_h */
