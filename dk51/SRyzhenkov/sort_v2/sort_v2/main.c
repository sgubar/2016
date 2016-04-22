//  main.c
//  sort_v2
//
//  Created by Ryzhenkov Serhii on 21/04/16.
//  Copyright © 2016 Ryzhenkov Serhii. All rights reserved.

#define sizeArray (20000)
#include <stdio.h>
#include "Sorting.h"


void printArray(int anArray[], int aSize);
int *CreateArray(int Size);

int main()
{
	
	//printf("SizeArray:  %d \n", sizeArray);
	//scanf("Size = %d \n", &sizeArray);
	//printf("SizeArray: %d \n", sizeArray);

	int *SortArray = CreateArray(sizeArray);
	int bubArray[sizeArray];
	int SelArray[sizeArray];
	int InsArray[sizeArray];
	int ShellArray[sizeArray];
	for (int z = 0; z < sizeArray; z++) {
		bubArray[z] = SortArray[z];
		SelArray[z] = SortArray[z];
		InsArray[z] = SortArray[z];
		ShellArray[z] = SortArray[z];
	}

	//printArray(bubArray, sizeArray);
	bubbleSort(bubArray, sizeArray);
	//printArray(bubArray, sizeArray);

	selectionSort(SelArray, sizeArray);

	insertionSort(InsArray, sizeArray);
	shellSort(ShellArray, sizeArray);

	system("pause");
}

#pragma mark -

static int *CreateArray(int size) {
	srand(time(NULL));
	int *anArray = (int *)malloc(sizeof(int)*size);
	for (int i = 0; i<size; i++) {
		*(anArray + i) = rand() % 1000;
	}
	return anArray;
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

