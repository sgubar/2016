//
//  DynamicArray.c
//  doTest
//
//  Created by Olexandr Tsymbal on 20/05/16.
//  Copyright © 2016 OlTsymbal. All rights reserved.
//
#ifndef DynamicArray_h
#define DynamicArray_h

#include <stdio.h>

typedef struct __dynamicIntArray
{
	int *storage;
	int physicalSize;
	int logicalSize;
}DynamicIntArray;

DynamicIntArray *createDAInt(int aSize);
void freeDAInt(DynamicIntArray *anArray);

int valueAtIndex(DynamicIntArray *anArray, int anIndex);
void setValueAtIndex(DynamicIntArray *anArray, int anValue, int anIndex);

#endif /* DynamicArray_h */
