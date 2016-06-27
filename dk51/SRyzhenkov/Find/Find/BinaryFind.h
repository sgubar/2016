#pragma once


#include <stdio.h>

typedef struct __ordArray
{
	int *storage;
	unsigned size;
	unsigned maxSize;
}ordArray, *ordArrayPtr;

ordArrayPtr create(unsigned aSize);
void destroy(ordArrayPtr anArray);

unsigned insert(ordArrayPtr anArray, int aValue);
unsigned delete(ordArrayPtr anArray, int aValue);
unsigned size(ordArrayPtr);
unsigned find(ordArrayPtr anArray, int aValue);
void print(ordArrayPtr anArray);