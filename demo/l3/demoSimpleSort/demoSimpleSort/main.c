//
//  main.c
//  demoSimpleSort
//
//  Created by Slava Gubar on 4/7/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include "SimpleSort.h"
#include "shellSort.h"

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

	clock_t theStart0 = clock();
	selectionSort(theArray3, ARRAY_SIZE(theArray3));
	clock_t theEnd0 = clock();
	printArray(theArray3, ARRAY_SIZE(theArray3));
	printf ("time of Selection sorting: %.10lf\n", (double)(theEnd0 - theStart0)/CLOCKS_PER_SEC);

	printf("\nTest Shell sorting\n");
	int theArray4[] = {77, 99, 44, 55, 22, 88, 11, 0, 66, 33};
	printArray(theArray4, ARRAY_SIZE(theArray4));
	
	clock_t theStart = clock();
	shellSort(theArray4, ARRAY_SIZE(theArray4));
	clock_t theEnd = clock();
	printArray(theArray4, ARRAY_SIZE(theArray4));
	
	printf ("time of Shell sorting: %.10lf\n", (double)(theEnd - theStart)/CLOCKS_PER_SEC);
	
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