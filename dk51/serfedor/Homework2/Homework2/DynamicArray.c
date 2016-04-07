//
//  DynamicArray.c
//  Homework2
//
//  Created Sergey Fedorenko on 4/6/16.
//  Copyright © 2016 Sergey Fedorenko. All rights reserved.
//

#include "DynamicArray.h"
#include <stdio.h>
#include <stdlib.h>

DynamicIntArray *createDAInt(int aSize)
{
	DynamicIntArray *DA = (DynamicIntArray*)malloc(aSize*sizeof(DynamicIntArray));
	DA->physicalSize = aSize;
	DA->logicalSize = 0;
	DA->storage = (int *)malloc(aSize*sizeof(int));;
	for (int i = 0; i < aSize; i++) DA->storage[i] = NULL;
	return DA;
}
void freeDAInt(DynamicIntArray *anArray)
{	
	free(anArray->storage);
	free(anArray);
	anArray->storage = NULL;
	anArray->logicalSize = anArray->physicalSize = 0;
}

int valueAtIndex(int anIndex, DynamicIntArray *anArray)
{
	if (anIndex > anArray->physicalSize) 
		return 0;
	int value;
	value = anArray->storage[anIndex];
	return value;
}

void setValueAtIndex(int anValue, int anIndex, DynamicIntArray *anArray)
{
	if (anArray->logicalSize == anArray->physicalSize) {
		anArray->physicalSize *= 2;
		if (anIndex > anArray->physicalSize) anArray->physicalSize = anIndex;
		anArray->storage = (int)realloc(anArray->storage, anArray->physicalSize  *sizeof(int));
	}
	if (NULL == anArray->storage[anIndex]) anArray->logicalSize++;
	anArray->storage[anIndex] = anValue;
}