//
//  main.c
//  demoSimpleSort
//
//  Created by Slava Gubar on 4/7/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#include <stdio.h>
#include "SimpleSort.h"

#define ARRAY_SIZE(a) (sizeof(theArray)/sizeof(theArray[0]))

static void printArray(int anArray[], int aSize);

int main(int argc, const char * argv[])
{
	int theArray[] = {77, 99, 44, 55, 22, 88, 11, 0, 66, 33};
	
	printf("Test bubble sorting\n");
	
	printArray(theArray, ARRAY_SIZE(theArray));
	bubbleSort(theArray, ARRAY_SIZE(theArray));
	printArray(theArray, ARRAY_SIZE(theArray));

	printf("\nTest selection sorting\n");
	int theArray2[] = {77, 99, 44, 55, 22, 88, 11, 0, 66, 33};
	printArray(theArray2, ARRAY_SIZE(theArray2));
	selectionSort(theArray2, ARRAY_SIZE(theArray2));
	printArray(theArray2, ARRAY_SIZE(theArray2));	

	printf("\nTest insertion sorting\n");
	int theArray3[] = {77, 99, 44, 55, 22, 88, 11, 0, 66, 33};
	printArray(theArray3, ARRAY_SIZE(theArray3));
	selectionSort(theArray3, ARRAY_SIZE(theArray3));
	printArray(theArray3, ARRAY_SIZE(theArray3));

	// insert code here...
	printf("Hello, World!\n");
	return 0;
}

#pragma mark -
void printArray(int anArray[], int aSize)
{
	printf("{");
	for (int i = 0; i < aSize; i++)
	{
		printf(" %d ", anArray[i]);
	}

	printf("}\n");
}