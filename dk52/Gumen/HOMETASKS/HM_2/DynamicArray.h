
//  DynamicArray.c
//  doTest
//
//  Created by Slava Gubar on 3/24/16.
//  Modified by Dima Humeniuk on 5/6/16
//  Copyright © 2016 Slava Gubar. All rights reserved.
//  Copyright © 2016 Dima Humeniuk. All rights reserved.
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

DynamicIntArray *anArray;
DynamicIntArray *createDAInt(int aSize);
void freeDAInt(DynamicIntArray *anArray);

int valueAtIndex(DynamicIntArray *anArray, int anIndex);
void setValueAtIndex(DynamicIntArray *anArray, int anValue, int anIndex, int memoryflag);

void printTheArray(DynamicIntArray *anArray);
void printTheArrayInfo(DynamicIntArray *anArray);
int IndexNegativeCheck(int anIndex);
int IndexMemoryCheck(DynamicIntArray *anArray, int anIndex);
int SizeCheck(int aSize);

#endif /* DynamicArray_h */

