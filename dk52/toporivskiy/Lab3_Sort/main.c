//
//  main.c
//  Lab3_Sort
//
//  Created by Andrew Toporivskiy on 09/05/16 (DD/MM/YY).
//  Copyright (C) 2016 Andrew Toporivskiy. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

#include <stdio.h>
#include "fillArray.h"
#include "SimpleSort.h"
#include "shellSort.h"
#include "quickSort.h"
#include "doTest.h"



int main()
{
	// Entry point
	printf("CHOOSE OPERATION:\n");
	printf("1) Time to sort the array with 10000 elements\n");
	printf("2) Exit\n");
	printf("\n");
	int operation;
	// Choose operation and checkup
	do {
		printf("Enter number of operation:\n");
		scanf("%d", &operation);
		printf("\n");
	} while (operation != 1 && operation != 2);
	// Output operation on the screen
	if (operation == 1) {
		// So we initialization our array with 10'000 cells and calculate size number of array.
		int anArray[10000];
		int aSize = ARRAY_SIZE(anArray);
		// Call function that will testing time of running sort fuction
		doTest(anArray, aSize);
	}
	else if (operation == 2) {
		return 0;
	}
	else {
		printf("FATAL ERROR!!!\n"); // Be on the safe side ;)
	}
	return 0;
}
