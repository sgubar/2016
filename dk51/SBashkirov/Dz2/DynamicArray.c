//
//  DynamicArray.c
//  doTest
//
//  Created by Slava Gubar on 3/24/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "DynamicArray.h"


DynamicIntArray *createDAInt(int aSize)
{
	DynamicIntArray *DynArray=(DynamicIntArray *)malloc(sizeof(DynamicIntArray));;
	DynArray->physicalSize = aSize;
	DynArray->logicalSize = 0;
	DynArray->storage = (int *)malloc(aSize * sizeof(int));
	for (int i=0; i < aSize; i++) DynArray->storage[i] = NULL;
	return DynArray;

}

void freeDAInt(DynamicIntArray *anArray)
{
	free(anArray->storage);
	free(anArray);
    anArray->storage = NULL;
	anArray->logicalSize= anArray->physicalSize = 0;
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
	if (anIndex > anArray->physicalSize) {
		if (anIndex > anArray->physicalSize) anArray->physicalSize= anIndex;
		anArray->storage = realloc(anArray->storage, anArray->physicalSize * sizeof(int));
	}
	if (NULL == anArray->storage[anIndex]) anArray->logicalSize++;
	anArray->storage[anIndex] = anValue;
}