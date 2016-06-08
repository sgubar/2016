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

int main()
{
	int i=0;
	printf("Enter the size of array");
	scanf("%d",&i);
	int theArray[i];
	fillArray( theArray,  i, 99999999);
	
	printf("Test bubble sorting\n");
	
	//printArray(theArray, ARRAY_SIZE(theArray));
	clock_t theStart2 = clock();
	bubbleSort(theArray, ARRAY_SIZE(theArray));
	clock_t theEnd2 = clock();
	//printArray(theArray, ARRAY_SIZE(theArray));
	printf ("time of Bubble sorting: %.20lf\n", (double)(theEnd2 - theStart2)/CLOCKS_PER_SEC);

	printf("\nTest insertion sorting\n");
	int theArray2[i];
    fillArray( theArray2,  i, 99999999);
	//printArray(theArray2, ARRAY_SIZE(theArray2));
			clock_t theStart3 = clock();
	insertionSort(theArray2, ARRAY_SIZE(theArray2));
			clock_t theEnd3 = clock();
	//printArray(theArray2, ARRAY_SIZE(theArray2));
	printf ("time of Insertion sorting: %.20lf\n", (double)(theEnd3 - theStart3)/CLOCKS_PER_SEC);	

	printf("\nTest selection sorting\n");
	int theArray3[i];
	fillArray( theArray3,  i, 99999999);
	//printArray(theArray3, ARRAY_SIZE(theArray3));

	clock_t theStart0 = clock();
	selectionSort(theArray3, ARRAY_SIZE(theArray3));
	clock_t theEnd0 = clock();
	//printArray(theArray3, ARRAY_SIZE(theArray3));
	printf ("time of Selection sorting: %.20lf\n", (double)(theEnd0 - theStart0)/CLOCKS_PER_SEC);

	printf("\nTest Shell sorting\n");
	int theArray4[i];
	fillArray( theArray4,  i, 99999999);
	//printArray(theArray4, ARRAY_SIZE(theArray4));
	
	clock_t theStart = clock();
	shellSort(theArray4, ARRAY_SIZE(theArray4));
	clock_t theEnd = clock();
//	printArray(theArray4, ARRAY_SIZE(theArray4));
	
	printf ("time of Shell sorting: %.40lf\n", (double)(theEnd - theStart)/CLOCKS_PER_SEC);
	
	printf ("Start to make partition of the array\n");
	int theArray5[i];
	fillArray( theArray5,  i, 99999999);
	int thePivot = 99999999; //make the pivot as avarage VALUE
	fillArray(theArray5, ARRAY_SIZE(theArray5), thePivot);
//	printArray(theArray5, ARRAY_SIZE(theArray5));
	
	printf("Finish the partition with a pivot: %d\n", partitionIt(theArray5, 0,
				ARRAY_SIZE(theArray5) - 1, 99999999));
	
	//printArray(theArray5, ARRAY_SIZE(theArray5));

	printf("\nTest Quick sorting\n");
	int theQuickArray[i];
	fillArray(theQuickArray, i, 99999999);
	//printArray(theQuickArray, ARRAY_SIZE(theQuickArray));
	
	clock_t theStartQuick = clock();
	quickSort2(theQuickArray, 0, ARRAY_SIZE(theQuickArray) - 1);
	clock_t theEndQuick = clock();
	//printArray(theQuickArray, ARRAY_SIZE(theQuickArray));
	
	printf ("time of Quick sorting: %.40lf\n", (double)(theEndQuick - theStartQuick)/CLOCKS_PER_SEC);


	
	system("pause");
}


void printArray(int anArray[], int aSize)
{	int i;
	printf("{");
	for ( i = 0; i < aSize; i++)
	{
		printf(" %d ", anArray[i]);
	}

	printf("}\n");
}

void fillArray(int anArray[], int aSize, int aPivot)
{	int i;
	srand(0);
	for ( i = 0; i < aSize; i++)
	{
		anArray[i] = rand() % (2 * aPivot);
	}
}
