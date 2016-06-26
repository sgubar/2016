//
//  main.c
//  demoSimpleSort
//
//  Created by Slava Gubar on 4/7/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "SimpleSort.h"
#include "shellSort.h"
#include "quickSort.h"

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

static void printArray(int anArray[], int aSize);
static void fillArray(int anArray[], int aSize, int aPivot);

int main(int argc, const char * argv[])
{
	clock_t  theStart, theEnd;

	int theArray1[1000];
	fillArray(theArray1, ARRAY_SIZE(theArray1));
	
	printf("Test bubble sorting\n");
	
	theStart = clock();
	bubbleSort(theArray1, ARRAY_SIZE(theArray1));
	theEnd = clock();
	printf("time for sorting 1000 elements by Bubble sort: %d \n", (double)(theEnd - theStart) / CLOCKS_PER_SEC);
	

	printf("\nTest selection sorting\n");
	
	theStart = clock();
	selectionSort(theArray1, ARRAY_SIZE(theArray1));
	theEnd = clock();
	printf("time for sorting 1000 elements by selection sort: %d \n", (double)(theEnd - theStart) / CLOCKS_PER_SEC);

	printf("\nTest insertion sorting\n");
	theStart = clock();
	insertionSort(theArray1, ARRAY_SIZE(theArray1));
	theEnd = clock();
	printf ("time for sorting 1000 elements by insertion sort: %.10lf\n", (double)(theEnd - theStart)/CLOCKS_PER_SEC);

	printf("\nTest Shell sorting\n");
	theStart = clock();
	shellSort(theArray1, ARRAY_SIZE(theArray1));
	theEnd = clock();
	printf ("time for sorting 1000 elements by Shell sort: %.10lf\n", (double)(theEnd - theStart)/CLOCKS_PER_SEC);
	
	printf ("Start to make partition of the array\n");
	int theArray[1000];
	int thePivot = 99; //make the pivot as avarage VALUE
	fillArray(theArray, ARRAY_SIZE(theArray), thePivot);
	printArray(theArray, ARRAY_SIZE(theArray));
	
	printf("Finish the partition with a pivot: %d\n", partitionIt(theArray, 0,
				ARRAY_SIZE(theArray) - 1, 99));
	
	printArray(theArray, ARRAY_SIZE(theArray));

	printf("\nTest Quick sorting\n");
	int theQuickArray[1000];
	fillArray(theQuickArray, ARRAY_SIZE(theQuickArray), 100);
	printArray(theQuickArray, ARRAY_SIZE(theQuickArray));
	
	theStart = clock();
	shellSort(theArray1, ARRAY_SIZE(theArray1));
	theEnd = clock();
	printf ("time for sorting 1000 elements by Quick sort: %.10lf\n", (double)(theEnd - theStart)/CLOCKS_PER_SEC);
	
	printf("Tests have finished\n");
	
	system("pause");
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

void fillArray(int anArray[], int aSize, int aPivot)
{
	srand(0);
	for (int i = 0; i < aSize; i++)
	{
		anArray[i] = rand();
	}
}
