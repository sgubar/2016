//
//  Main.c
//  
//
//  Created by Bogdan Maximovich on 4/21/16.
//  Copyright © 2016 Bogdan Maximovich. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "ShellSort.h"


#define ARRAY_SIZE(a) (sizeof(theArray)/sizeof(theArray[0]))

static void printArray(int anArray[], int aSize);

int main(int argc, const char * argv[])
{
	int theArray[1000];
	{
		srand(time(NULL));

	for (int i = 0; i < 1000; i++)
		theArray[i] = 0 + rand() % 1000;
	}
	printf("Test bubble sorting\n");
    printArray(theArray, ARRAY_SIZE(theArray));
	clock_t theStart1 = clock();
	BubbleSort(theArray, ARRAY_SIZE(theArray));
	clock_t theEnd1 = clock();
	printArray(theArray, ARRAY_SIZE(theArray));
	printf("time of bubble sorting: %.10lf\n", (double)(theEnd1 - theStart1) / CLOCKS_PER_SEC);

	printf("\nTest selection sorting\n");
	int theArray2[1000];
	{
		srand(time(NULL));

		for (int i = 0; i < 1000; i++)
			theArray2[i] = 0 + rand() % 1000;
	}
	printArray(theArray2, ARRAY_SIZE(theArray2));
	clock_t theStart2 = clock();
	SelectionSort(theArray2, ARRAY_SIZE(theArray2));
	clock_t theEnd2 = clock();
	printArray(theArray2, ARRAY_SIZE(theArray2));
	printf("time of selection sorting: %.10lf\n", (double)(theEnd2 - theStart2) / CLOCKS_PER_SEC);

	printf("\nTest insertion sorting\n");
	int theArray3[1000];
	{
		srand(time(NULL));

		for (int i = 0; i < 1000; i++)
			theArray3[i] = 0 + rand() % 1000;
	}
	printArray(theArray3, ARRAY_SIZE(theArray3));

	clock_t theStart3 = clock();
	SelectionSort(theArray3, ARRAY_SIZE(theArray3));
	clock_t theEnd3 = clock();
	printArray(theArray3, ARRAY_SIZE(theArray3));
	printf("time of insertion sorting: %.10lf\n", (double)(theEnd3 - theStart3) / CLOCKS_PER_SEC);

	printf("\nTest Shell sorting\n");
	int theArray4[1000];
	{
		srand(time(NULL));

		for (int i = 0; i < 1000; i++)
			theArray4[i] = 0 + rand() % 1000;
	}
	printArray(theArray4, ARRAY_SIZE(theArray4));

	clock_t theStart4 = clock();
	ShellSort(theArray4, ARRAY_SIZE(theArray4));
	clock_t theEnd4 = clock();
	printArray(theArray4, ARRAY_SIZE(theArray4));

	printf("time of Shell sorting: %.10lf\n", (double)(theEnd4 - theStart4) / CLOCKS_PER_SEC);

	printf("Hello, World!\n");
	return 0;
}

void printArray(int anArray[], int aSize)
{
	printf("{");
	for (int i = 0; i < aSize; i++)
	{
		printf(" %d ", anArray[i]);
	}

	printf("}\n");
	system("pause");
}