#include <stdio.h>
#include <stdlib.h>
#include "DynamicArray.h"


DynamicIntArray *createDAInt(int aSize)
{
	DynamicIntArray *DynArray = (DynamicIntArray *)malloc(sizeof(DynamicIntArray));;
	DynArray->physicalSize = aSize;
	DynArray->logicalSize = 0;
	DynArray->storage = (int *)malloc(aSize * sizeof(int));
	for (int i = 0; i < aSize; i++) {
		DynArray->storage[i] = 0;
	}
	return DynArray;

}

void freeDAInt(DynamicIntArray *anArray)
{
	free(anArray->storage);
	free(anArray);
}

int valueAtIndex(int anIndex, DynamicIntArray *anArray)
{
	if (anIndex > anArray->physicalSize) return 0;
	int value;
	value = anArray->storage[anIndex];
	return value;
}


void setValueAtIndex(int anValue, int anIndex, DynamicIntArray *anArray)
{
	if (anIndex > anArray->physicalSize)
	{
		anArray->storage = (int *)realloc(anArray->storage, (anIndex + 1) * sizeof(int));
		for (int i = anArray->physicalSize; i < anIndex + 1; i++) {
			anArray->storage[i] = 0;
		}
		anArray->physicalSize = anIndex + 1;
	}
	if (anArray->storage[anIndex] == 0) anArray->logicalSize += 1;
	anArray->storage[anIndex] = anValue;
}

void printDAsize(DynamicIntArray *anArray) {
	printf("Physical size = %d\n Logical size = %d \n", anArray->physicalSize, anArray->logicalSize);
}