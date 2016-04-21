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
	/*..................................................................................................*/
	int theArray[1000];
	{
		srand(time(NULL));

	for (int i = 0; i < 1000; i++)
		theArray[i] = 0 + rand() % 1000;
	}
	printf("\nTest bubble sorting\n\n");
    printArray(theArray, ARRAY_SIZE(theArray));
    printf("\n");
	clock_t theStart1 = clock();
	BubbleSort(theArray, ARRAY_SIZE(theArray));
    printf("\n");
	clock_t theEnd1 = clock();
	printArray(theArray, ARRAY_SIZE(theArray));
	printf("\ntime of bubble sorting: %.10\n\n", (double)(theEnd1 - theStart1) / CLOCKS_PER_SEC);

/*........................................................................................................*/

	printf("\nTest selection sorting\n\n");
	int theArray2[1000];
	{
		srand(time(NULL));

		for (int i = 0; i < 1000; i++)
			theArray2[i] = 0 + rand() % 1000;
	}
	printArray(theArray2, ARRAY_SIZE(theArray2));
	clock_t theStart2 = clock();
	 printf("\n");
	SelectionSort(theArray2, ARRAY_SIZE(theArray2));
	 printf("\n");
	clock_t theEnd2 = clock();
	 printf("\n");
	printArray(theArray2, ARRAY_SIZE(theArray2));
	printf("\ntime of selection sorting: %.10lf\n", (double)(theEnd2 - theStart2) / CLOCKS_PER_SEC);

/*........................................................................................................*/

	printf("\nTest insertion sorting\n\n");
	int theArray3[1000];
	{
		srand(time(NULL));

		for (int i = 0; i < 1000; i++)
			theArray3[i] = 0 + rand() % 1000;
	}
	printArray(theArray3, ARRAY_SIZE(theArray3));

	clock_t theStart3 = clock();
	 printf("\n");
	SelectionSort(theArray3, ARRAY_SIZE(theArray3));
	clock_t theEnd3 = clock();
	 printf("\n");
	printArray(theArray3, ARRAY_SIZE(theArray3));
	printf("\ntime of insertion sorting: %.10lf\n\n", (double)(theEnd3 - theStart3) / CLOCKS_PER_SEC);

/*........................................................................................................*/

	printf("\nTest Shell sorting\n\n");
	int theArray4[1000];
	{
		srand(time(NULL));

		for (int i = 0; i < 1000; i++)
			theArray4[i] = 0 + rand() % 1000;
	}
	printArray(theArray4, ARRAY_SIZE(theArray4));
    clock_t theStart4 = clock();
	 printf("\n");
	ShellSort(theArray4, ARRAY_SIZE(theArray4));
	clock_t theEnd4 = clock();
	 printf("\n");
	printArray(theArray4, ARRAY_SIZE(theArray4));

	printf("\ntime of Shell sorting: %.10lf\n\n", (double)(theEnd4 - theStart4) / CLOCKS_PER_SEC);

	return 0;

	system("pause");
}
void printArray(int anArray[], int aSize)
{
	printf("{");
	for (int i = 0; i < aSize; i++)
	{
		printf(" %d ", anArray[i]);
	}

	printf("}\n");
}
