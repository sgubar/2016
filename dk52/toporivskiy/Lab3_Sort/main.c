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



int main()
{
	// Entry point
	printf("CHOOSE OPERATION:\n");
	printf("1) Time to sort the array with 500 elements\n");
	printf("2) Time to sort the array with 1000 elements\n");
	printf("3) Time to sort the array with 10 000 elements\n");
	printf("4) Time to sort the array with 50 000 elements\n");
	printf("5) Exit\n");
	printf("\n");
	int operation;
	// Choose operation and checkup
	do {
		printf("Enter number of operation:\n");
		scanf("%d", &operation);
		printf("\n");
	} while (operation != 1 && operation != 2 && operation != 3 && operation != 4 && operation != 5);
	// Output operation on the screen
	if (operation == 1) {
		int anArray[500];
		int aSize = ARRAY_SIZE(anArray);
		fillArray(anArray, aSize);
			printf("{");
			for (int i = 0; i < aSize; i++)
			{
				printf(" %d ", anArray[i]);
			}

			printf("}\n");
			system("pause");
	}
	else if (operation == 2) {
		int anArray[1000];
		int aSize = ARRAY_SIZE(anArray);
		fillArray(anArray, aSize);
	}
	else if (operation == 3) {
	}
	else if (operation == 4) {
	}
	else if (operation == 5) {
		return 0;
	}
	else {
		printf("FATAL ERROR!!!\n"); // Be on the safe side ;)
	}
	return 0;
}
