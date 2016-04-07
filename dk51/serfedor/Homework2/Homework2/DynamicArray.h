//
//  DynamicArray.h
//  Homework2
//
//  Created by Sergey Fedorenko on 3/24/16.
//  Copyright © 2016 Sergey Fedorenko. All rights reserved.
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

int valueAtIndex(int anIndex, DynamicIntArray*anArray);
void setValueAtIndex(int anValue, int anIndex);

#endif /* DynamicArray_h */