//
//  DynamicArray.c
//  
//
//  Created by Ninoshvili on 17.05.2015
//  Copyright © 2016 Ninoshvili. All rights reserved.
//

#include "DynamicArray.h"
#include <stdio.h>
#include <stdlib.h>

DynamicIntArray *createDAInt(int aSize)
{
	DynamicIntArray *array = (DynamicIntArray*)malloc(sizeof(DynamicIntArray)); //create a pointer to this struct in heap
	array->storage = (int*)malloc(aSize*sizeof(int)); //allocate a block of memory by adress of "storage pointer"
	array->physicalSize = aSize; 
	array->logicalSize = 0;

	return array;
}

void freeDAInt(DynamicIntArray *anArray)
{
	if (anArray != NULL) //watching for created array
	{
		free(anArray); //clean allocated in heap memory
		anArray = NULL; //set this adress as 0, as a rezult it's disable for using deallocated memory
	}
}

int valueAtIndex(DynamicIntArray *anArray, int anIndex)
{
	while (anIndex > anArray->physicalSize)
		printf("choose again, but not bigger than %d\n", anArray->physicalSize);

	if (anIndex < anArray->physicalSize)
		return anArray->storage[anIndex];
}

void setValueAtIndex(DynamicIntArray *anArray, int anValue, int anIndex)
{
	if (anArray->physicalSize > anArray->logicalSize && anIndex < anArray->physicalSize)
	{
		anArray->storage[anIndex] = anValue;
		anArray->logicalSize++;
	}
	else
	{
		anArray->storage = (int*)realloc(anArray->storage, 2*anIndex*(sizeof(int))); //increase the needed size to double 

		anArray->storage[anIndex] = anValue; //setValue

		anArray->physicalSize = anIndex * 2;
		anArray->logicalSize++;
	}
}
