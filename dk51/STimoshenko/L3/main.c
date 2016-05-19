//
//  main.c
//  
//
//  Created by Serj Timoshenko on 5/18/16.
//  Copyright © 2016 Serj Timoshenko. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Simplesort.h"
#include "quicksort.h"
#include "Shellsort.h"

#define ARRAY_SIZE(a) (sizeof(theArray)/sizeof(theArray[0]))
#define ArraySize 30000
static void printArray(int anArray[], int aSize);

int main(int argc, const char * argv[])
{
		int theArray[ArraySize];
	
		int theArrayFB[ArraySize];
		int theArrayFS[ArraySize];
		int theArrayFI[ArraySize];
		int theArrayFSh[ArraySize];
		int theArrayFQu[ArraySize];

	srand(time(NULL));
	for (int Number = 0; Number < ArraySize; Number++)
	{
		theArray[Number] = rand();
		theArrayFB[Number] = theArray[Number];
		theArrayFS[Number] = theArray[Number];
		theArrayFI[Number] = theArray[Number];
		theArrayFSh[Number] = theArray[Number];
		theArrayFQu[Number] = theArray[Number];

	}

	printf("Wait, until program test the bubble sorting...");

	clock_t theStart1 = clock();
	bubbleSort(theArrayFB, ARRAY_SIZE(theArrayFB));
	clock_t theEnd1 = clock();
	printf(" 100 percent. Done\n");

// The bubble sorting //

	printf("Wait, until program test the selection sorting...");
	clock_t theStart2 = clock();
	selectionSort(theArrayFS, ARRAY_SIZE(theArrayFS));
	clock_t theEnd2 = clock();
	printf(" 100 percent. Done\n");

// The selection sorting //

	printf("Wait, until program test the insertion sorting...");
	clock_t theStart3 = clock();
	insertionSort(theArrayFI, ARRAY_SIZE(theArrayFI));
	clock_t theEnd3 = clock();
	printf(" 100 percent. Done\n");

// The insertion sorting //

	printf("Wait, until program test the quick sorting...");
	clock_t theStart4 = clock();
	quickSort2(theArrayFQu, 0, ARRAY_SIZE(theArrayFQu) - 1);
	clock_t theEnd4 = clock();
	printf(" 100 percent. Done\n");
	
// The Quick sort //

	printf("Wait, until program test the Shell sorting...");
	clock_t theStart5 = clock();
	ShellSort(theArrayFSh, ARRAY_SIZE(theArrayFSh));
	clock_t theEnd5 = clock();
	printf(" 100 percent. Done\n\n");

// The Shell sort // 


// Results:
	printf("It's done:\n");
	printf("Time of bubble sorting: %.10f\n", (double)(theEnd1 - theStart1) / CLOCKS_PER_SEC);
	printf("Time of selection sorting: %.10f\n", (double)(theEnd2 - theStart2) / CLOCKS_PER_SEC);
	printf("Time of insertion sorting: %.10f\n", (double)(theEnd3 - theStart3) / CLOCKS_PER_SEC);
	printf("Time of Shell sorting: %.10f\n", (double)(theEnd5 - theStart5) / CLOCKS_PER_SEC);
	printf("Time of Quick sorting: %.20f\n\n", (double)(theEnd4 - theStart4) / CLOCKS_PER_SEC);

	
	

	system("pause");
}







