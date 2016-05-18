
//  DynamicArray.c
//  doTest
//
//  Created by Slava Gubar on 3/24/16.
//  Modified by Dima Humeniuk on 5/6/16
//  Copyright © 2016 Slava Gubar. All rights reserved.
//  Copyright © 2016 Dima Humeniuk. All rights reserved.
//

#include "DynamicArray.h"
#include <stdio.h>
#include <stdlib.h>

DynamicIntArray *createDAInt(int aSize)
{
	
	anArray = (DynamicIntArray*)malloc(sizeof(DynamicIntArray));
	anArray->storage = (int*)malloc(aSize*sizeof(int));
	anArray->physicalSize = aSize;
	anArray->logicalSize = 0;
	printf("Allocated %d bytes for the array\n\n", aSize*sizeof(int));
	
	return anArray;
}

void freeDAInt(DynamicIntArray *anArray)
{
	if (anArray == NULL || anArray->storage==NULL)//if the structure is empty...
		return;
	
	free(anArray->storage);

	free(anArray);
}

int valueAtIndex(DynamicIntArray *anArray, int anIndex)
{
	if (anIndex <= 0 || anIndex > anArray->physicalSize - 1)
	{
		printf("Error:index out of the bounds.\n");
		return -1;
	}
	return anArray->storage[anIndex];
}

void setValueAtIndex(DynamicIntArray *anArray, int anValue, int anIndex, int memoryflag)
{
	int NewValueIndex = 0;
	int logicalSizeOLD = anArray->logicalSize;//save current logical size

	if (memoryflag >= 1)//allocate more memory if needed
	{
		while (anIndex > anArray->physicalSize - 1)
		{
			anArray->physicalSize *= 2;
			anArray->storage = realloc(anArray->storage, anArray->physicalSize*sizeof(int));
			printf("allocated %d bytes for the array...\n", anArray->physicalSize*sizeof(int));
		}
		memoryflag = 0;
	}

	if (anIndex <= anArray->logicalSize)//if we don't need to expand the logical size...
	{
		while (anIndex != logicalSizeOLD)
		{
			logicalSizeOLD--;
		}
		NewValueIndex = logicalSizeOLD;
	}
	if (anIndex > anArray->logicalSize)//if we need to expand the logical size...
	{
		
		while (anArray->logicalSize != anIndex)//increase logical size;
		{
			anArray->logicalSize++;
		}
		
		while (anArray->logicalSize > logicalSizeOLD)//fill with zeros all elements between 
		{
			int i = 1;

			if (anIndex != 0)
				anArray->storage[0] = 0;
			anArray->storage[logicalSizeOLD + i] = 0;

			i++;
			logicalSizeOLD++;
		}
		NewValueIndex = anArray->logicalSize;
	}
	
	anArray->storage[NewValueIndex] = anValue;//write the new value to the corresponding index
	
}

void printTheArray(DynamicIntArray *anArray)
{
	int i = 0;
	printf("Your array:\n");
	while (i <= anArray->logicalSize)
	{
		printf(" element[%d]:%d\n",i, anArray->storage[i]);
		i++;
	}
}

void printTheArrayInfo(DynamicIntArray *anArray)
{
	printf("Array physical size: %d\n", anArray->physicalSize);
	printf("Array logical size: %d\n", anArray->logicalSize);
	printf("Array zero element address: %d\n", anArray->storage);
}

int IndexNegativeCheck(int anIndex)
{
	int errorflag = 0;
	if (anIndex < 0)
	{
		printf("Error:index must be a positive value.");
		errorflag++;
	}
	return errorflag;
}

int IndexMemoryCheck(DynamicIntArray *anArray, int anIndex)
{
	int memoryflag = 0;

	if(anIndex > anArray->physicalSize - 1)
	{
		printf("Index out of the bounds...allocating more memory...\n");
		memoryflag++;
	}

	return memoryflag;
}

int SizeCheck(int aSize)
{
	if (aSize <= 0)
	{
		printf("Error: invalid size.\n");
		return 1;
	}
	return -1;
}