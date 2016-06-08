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
	for (int i = 0; i < aSize; i++) DA->storage[i] = 0;
	return DA;
}
void freeDAInt(DynamicIntArray *anArray )
{	
	if (anArray != NULL)
	{
		if (anArray->storage != NULL)
		{
			free(anArray->storage);
			free(anArray);
		}
	}
	return 0;
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
	if (anIndex > anArray->physicalSize)
	{
		anArray->storage = (int *)realloc(anArray->storage, (anIndex + 1) * sizeof(int));
		for (int i = anArray->physicalSize; i < anIndex + 1; i++) anArray->storage[i] = 0;
		anArray->physicalSize = anIndex + 1;
	}
	if (0 == anArray->storage[anIndex]) anArray->logicalSize += 1;
	anArray->storage[anIndex] = anValue;
}