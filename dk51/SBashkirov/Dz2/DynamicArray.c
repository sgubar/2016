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

	return DynArray;

}

void freeDAInt(DynamicIntArray *anArray)
{
	free(anArray->storage);
	anArray->storage = NULL;
	anArray->logicalSize= anArray->physicalSize = 0;
}


void setValueAtIndex(int anValue, int anIndex, DynamicIntArray *anArray)
{
	if (anArray->logicalSize == anArray->physicalSize) {
		anArray->physicalSize *= 2;
		anArray->storage = (int *)realloc(anArray->storage, anArray->physicalSize * sizeof(int));
	}
	anArray->storage[anArray->physicalSize++] = anValue;
}