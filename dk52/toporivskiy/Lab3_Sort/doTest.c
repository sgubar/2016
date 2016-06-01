//
//  doTest.c
//  Lab3_Sort
//
//  Created by Andrew Toporivskyi on 02/06/2016.
//  Copyright © 2016 Andrew Toporivskyi. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "SimpleSort.h"
#include "shellSort.h"
#include "quickSort.h"

#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

int doTest(int anArray[], int aSize)
{
	// Aaaand we start this code that will calculating runnig time of function
	printf("Test bubble sorting\n");
	fillArray(anArray, aSize);
	clock_t theStartBubble = clock();
	bubbleSort(anArray, aSize);
	clock_t theEndBubble = clock();
	printf("time of Bubble sorting: %.10lf\n", (double)(theEndBubble - theStartBubble) / CLOCKS_PER_SEC);

	printf("\nTest selection sorting\n");
	fillArray(anArray, aSize);
	clock_t theStartSelection = clock();
	selectionSort(anArray, aSize);
	clock_t theEndSelection = clock();
	printf("time of Selection sorting: %.10lf\n", (double)(theEndSelection - theStartSelection) / CLOCKS_PER_SEC);

	printf("\nTest insertion sorting\n");
	fillArray(anArray, aSize);
	clock_t theStartInsertion = clock();
	insertionSort(anArray, aSize);
	clock_t theEndInsertion = clock();
	printf("time of Insetion sorting: %.10lf\n", (double)(theEndInsertion - theStartInsertion) / CLOCKS_PER_SEC);

	printf("\nTest Shell sorting\n");
	clock_t theStartShell = clock();
	shellSort(anArray, aSize);
	clock_t theEndShell = clock();
	printf("time of Shell sorting: %.10lf\n", (double)(theEndShell - theStartShell) / CLOCKS_PER_SEC);

	printf("\nTest Quick sorting\n");
	fillArray(anArray, aSize);
	clock_t theStartQuick = clock();
	quickSort2(anArray, 0, aSize - 1);
	clock_t theEndQuick = clock();
	printf("time of Quick sorting: %.10lf\n", (double)(theEndQuick - theStartQuick) / CLOCKS_PER_SEC);

	// Here it is!
	// Now I want to ask you - would you like this and wanna again? ;)
	printf("\n");
	printf("GOT IT!\n");
	printf("Repeat?\n");
	printf("1) Yes\n");
	printf("2) No\n");
	printf("\n");
	int operation;
	// Choose operation and checkup
	do {
		printf("Enter number of operation:\n");
		scanf_s
			("%d", &operation);
		printf("\n");
	} while (operation != 1 && operation != 2);
	// Output operation on the screen
	if (operation == 1) {
		doTest(anArray, aSize);
		system("pause");
	}
	else if (operation == 2) {
		return 0;
	}
	else {
		printf("FATAL ERROR!!!\n"); // Be on the safe side ;)
	}
	return 0;
}