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
	free(anArray);
}

int valueAtIndex(int anIndex);
void setValueAtIndex(int anValue, int anIndex);