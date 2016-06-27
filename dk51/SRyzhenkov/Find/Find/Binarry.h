#pragma once

typedef struct __ordArray
{
	int *storage;
	unsigned size;
	unsigned maxSize;
}ordArray, *ordArrayPtr;


ordArrayPtr binarycreate(unsigned aSize);
void binarydestroy(ordArrayPtr anArray);

unsigned binaryinsert(ordArrayPtr anArray, int aValue);
unsigned binarydelete(ordArrayPtr anArray, int aValue);
unsigned binarysize(ordArrayPtr);
unsigned binaryfind(ordArrayPtr anArray, int aValue);
void binaryprint(ordArrayPtr anArray);
