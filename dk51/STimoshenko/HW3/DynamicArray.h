//
//  DynamicArray.h
//  doTest
//
//  Created by Serj Timoshenko on 5/219/16.
//  Copyright © 2016 Serj Timoshenko. All rights reserved.
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

#endif 
