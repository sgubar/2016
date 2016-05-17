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
	int theArray[10000];
	int theArray2[10000];
	int theArray3[10000];
	int theArray4[10000];
	srand(time(NULL));
	for (int i = 0;i < 10000;i++)
	{
		theArray[i] = rand();
		theArray2[i] = theArray[i];
		theArray3[i] = theArray[i];
		theArray4[i] = theArray[i];
	}




	printf("Test bubble sorting\n");
	clock_t theStart2 = clock();
	bubbleSort(theArray, ARRAY_SIZE(theArray));
	clock_t theEnd2 = clock();
	printf("time of bubble sorting: %.15lf\n", (double)(theEnd2 - theStart2) / CLOCKS_PER_SEC);

	printf("\nTest selection sorting\n");

	clock_t theStart1 = clock();
	selectionSort(theArray2, ARRAY_SIZE(theArray2));
	clock_t theEnd1 = clock();
	printf("time of selection sorting: %.15lf\n", (double)(theEnd1 - theStart1) / CLOCKS_PER_SEC);

	printf("\nTest insertion sorting\n");

	clock_t theStart0 = clock();
	insertionSort(theArray3, ARRAY_SIZE(theArray3));
	clock_t theEnd0 = clock();
	printf("time of insertion sorting: %.15lf\n", (double)(theEnd0 - theStart0) / CLOCKS_PER_SEC);

	printf("\nTest Shell sorting\n");

	clock_t theStart = clock();
	shellSort(theArray4, ARRAY_SIZE(theArray4));
	clock_t theEnd = clock();

	printf("time of Shell sorting: %.15lf\n", (double)(theEnd - theStart) / CLOCKS_PER_SEC);

	system("pause");
	return 0;
}