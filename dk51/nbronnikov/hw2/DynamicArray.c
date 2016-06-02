//
//  main.c
//  Dz 2
//
//  Created by Nazar Bronnikiv on 4/7/16.
//  Copyright © 2016 Nazar Bronnikiv. All rights reserved.
//

#include "DynamicArray.h"

#include <malloc.h>
#include <string.h>


DynamicIntArray *createDAInt(int aSize)
{
	DynamicIntArray *aNewArray = (DynamicIntArray *)malloc(sizeof(DynamicIntArray));

	memset(aNewArray, 0, sizeof(DynamicIntArray));
	
	aNewArray->physicalSize = aSize;

	aNewArray->storage = (int *)malloc(aSize * sizeof(int));
	
	memset(aNewArray->storage, 0, aSize * sizeof(int));
	
	return aNewArray;
}

void freeDAInt(DynamicIntArray *anArray)
{
	free(anArray->storage);
	
	free(anArray);
}

int valueAtIndex(DynamicIntArray *anArray, int anIndex)
{
	if (anIndex >= anArray->physicalSize)
	{
		return -1;
	}
	
	return anArray->storage[anIndex];
}

void setValueAtIndex(DynamicIntArray *anArray, int anValue, int anIndex)
{
	if (anIndex > anArray->physicalSize)
	{
		int newSize = (anIndex + 10) * sizeof(int);
		int *newStorage = (int *)malloc(newSize);
		
		memset(newStorage, 0, newSize);
		memcpy(newStorage, anArray->storage, anArray->physicalSize * sizeof(int));
		
		free(anArray->storage);
		
		anArray->storage = newStorage;
		anArray->physicalSize = anIndex + 10;
	}
	
	if (anArray->storage[anIndex] == 0)
	{
		anArray->logicalSize +=1;
	}
	
	anArray->storage[anIndex] = anValue;
}
