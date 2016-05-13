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
#include "quickSort.h"

#define ARRAY_SIZE(a) (sizeof(theArray)/sizeof(theArray[0]))

static void printArray(int anArray[], int aSize);
static void fillArray(int anArray[], int aSize, int aPivot);
int main(int argc, const char * argv[])
{
	/*..................................................................................................*/
	const int ArraySize=5000;
	int theArray[ArraySize];
	int Number;
	int theArray1[ArraySize];
	int theArray2[ArraySize];
	int theArray3[ArraySize];
	int theArray4[ArraySize];
	int theArray5[ArraySize];
    srand(time(NULL));
    for (Number = 0; Number < ArraySize; Number++)
    {
        theArray[Number] = 0 + rand() % ArraySize;
        theArray1[Number]=theArray[Number];
        theArray2[Number]=theArray[Number];
        theArray3[Number]=theArray[Number];
        theArray4[Number]=theArray[Number];
	}

	printf("\nTest bubble sorting\n\n");
//    intArray(theArray1, ARRAY_SIZE(theArray1));
//    printf("\n");
	clock_t theStart1 = clock();
	BubbleSort(theArray1, ARRAY_SIZE(theArray1));
	clock_t theEnd1 = clock();
//    printf("\n");
//	printArray(theArray1, ARRAY_SIZE(theArray4));

/*........................................................................................................*/

	printf("\nTest selection sorting\n\n");

//	printArray(theArray2, ARRAY_SIZE(theArray2));
//    printf("\n");
	clock_t theStart2 = clock();
	SelectionSort(theArray2, ARRAY_SIZE(theArray2));
	clock_t theEnd2 = clock();
//    printf("\n");
//	printArray(theArray2, ARRAY_SIZE(theArray2));

/*........................................................................................................*/

	printf("\nTest insertion sorting\n\n");
//	printArray(theArray3, ARRAY_SIZE(theArray3));
//    printf("\n");
	clock_t theStart3 = clock();
	SelectionSort(theArray3, ARRAY_SIZE(theArray3));
	clock_t theEnd3 = clock();
//    printf("\n");
//	printArray(theArray3, ARRAY_SIZE(theArray3));

/*........................................................................................................*/

	printf("\nTest Shell sorting\n\n");
//	printArray(theArray4, ARRAY_SIZE(theArray4));
//    printf("\n");
    clock_t theStart4 = clock();
	ShellSort(theArray4, ARRAY_SIZE(theArray4));
	clock_t theEnd4 = clock();
//    printf("\n");
//	printArray(theArray4, ARRAY_SIZE(theArray4));

/*........................................................................................................*/

	printf ("\nStart to make partition of the array\n");
	int thePivot = 2500; //make the pivot as avarage VALUE
	fillArray(theArray5, ARRAY_SIZE(theArray5), thePivot);
	//printArray(theArray5, ARRAY_SIZE(theArray5));
	//printArray(theArray5, ARRAY_SIZE(theArray5));

/*........................................................................................................*/

	printf("\nTest Quick sorting\n");
	//fillArray(theArray5, ARRAY_SIZE(theArray5), 100);
	//printArray(theArray5, ARRAY_SIZE(theArray5));
	clock_t theStart5 = clock();
	quickSort2(theArray5, 0, ARRAY_SIZE(theArray5) - 1);
	clock_t theEnd5 = clock();
	//printArray(theArray5, ARRAY_SIZE(theArray5));

/*........................................................................................................*/

    printf("\ntime of bubble sorting: %.10f\n", (double)(theEnd1 - theStart1) / CLOCKS_PER_SEC);
    printf("\ntime of selection sorting: %.10f\n", (double)(theEnd2 - theStart2) / CLOCKS_PER_SEC);
    printf("\ntime of insertion sorting: %.10f\n", (double)(theEnd3 - theStart3) / CLOCKS_PER_SEC);
	printf("\ntime of Shell sorting: %.10f\n\n", (double)(theEnd4 - theStart4) / CLOCKS_PER_SEC);
	printf("Finish the partition with a pivot: %d\n", partitionIt(theArray5, 0, ARRAY_SIZE(theArray5) - 1, 99));
	printf ("time of Quick sorting: %.10lf\n", (double)(theEnd5 - theStart5)/CLOCKS_PER_SEC);
	//return 0;

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
