//
//  DynamicArray.c
//  doTest
//
//  Created by Slava Gubar and Anrew Toporivskiy on 4/18/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#include "DynamicArray.h"
#include <stdio.h>
#include <stdlib.h>

DynamicIntArray * createDAInt(int aSize)
{
	DynamicIntArray *DA = (DynamicIntArray*) malloc(sizeof(DynamicIntArray));;
	DA->physicalSize = aSize;
	DA->logicalSize = 0;
	DA->storage = (int*) malloc(aSize * sizeof(int));
	return DA;
}

void freeDAInt(DynamicIntArray * anArray)
{
	free(anArray->storage);
	free(anArray);
}

int valueAtIndex(DynamicIntArray * anArray, int anIndex)
{
	if (anIndex > anArray->physicalSize)
	{
		return 0;
	}
	else {

		int value;
		value = anArray->storage[anIndex];
		return value;
	}
}

void setValueAtIndex(DynamicIntArray * anArray, int anValue, int anIndex)
{
	if (anIndex > anArray->physicalSize)
	{
		anArray->storage = (int*) realloc(anArray->storage, (anIndex + 10) * sizeof(int));
		anArray->physicalSize = anIndex + 10;
	}
	anArray->storage[anIndex] = anValue;
}
