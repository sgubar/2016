#ifndef DynamicArray_h
#define DynamicArray_h

#include <stdio.h>

typedef struct __dynamicIntArray
{
	int *storage;
	int physicalSize;
	int logicalSize;
}DynamicIntArray;

DynamicIntArray *anArray;
DynamicIntArray *createDAInt(int aSize);
void freeDAInt(DynamicIntArray *anArray);

int valueAtIndex(DynamicIntArray *anArray, int anIndex);
void setValueAtIndex(DynamicIntArray *anArray, int anValue, int anIndex, int memoryflag);

void printTheArray(DynamicIntArray *anArray);
void printTheArrayInfo(DynamicIntArray *anArray);
int IndexNegativeCheck(int anIndex);
int IndexMemoryCheck(DynamicIntArray *anArray, int anIndex);
int SizeCheck(int aSize);

#endif /* DynamicArray_h */