//
//  DynamicArray.h
//  doTest
//
//  Created by Slava Gubar on 3/24/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#ifndef DynamicArray_h
#define DynamicArray_h

#include <stdio.h>

typedef struct __dynamicIntArray
{
	int *storage;
	int physicalSize;
	int logicalSize;
        short storvalidity;
        DynamicIntArray.storvalidity=0;//flag of storage validity

}DynamicIntArray;

DynamicIntArray *createDAInt(int aSize);
void freeDAInt(DynamicIntArray *anArray);

int valueAtIndex(int anIndex,DynamicIntArray *anArray);
void setValueAtIndex(int anValue, int anIndex,DynamicIntArray *anArray);


int infofunc(DynamicIntArray *anArray);
#endif /* DynamicArray_h */