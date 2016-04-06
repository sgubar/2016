//
//  DynamicArray.c
//  Homework2
//
//  Created Sergey Fedorenko on 4/6/16.
//  Copyright © 2016 Sergey Fedorenko. All rights reserved.
//

#include "DynamicArray.h"
#include <stdio.h>

DynamicIntArray *createDAInt(int aSize)
{
	DynamicIntArray *DA = (DynamicIntArray*)malloc(aSize*sizeof(int));
	DA->physicalSize = aSize;
	DA->logicalSize = 0;
	DA->storage = NULL;

	return DA;
}
void freeDAInt(DynamicIntArray *anArray)
{
	free(anArray->storage);
	anArray->storage = NULL;
	anArray->logicalSize = anArray->physicalSize = 0;
}

int valueAtIndex(int anIndex);
void setValueAtIndex(int anValue, int anIndex, DynamicIntArray *anArray)
{
	if (anArray->logicalSize == anArray->physicalSize) {
		anArray->physicalSize *= 2;
		anArray->storage = (int *)realloc(anArray->storage, anArray->physicalSize * sizeof(int));
	}
	anArray->storage[anArray->physicalSize++] = anValue;
}