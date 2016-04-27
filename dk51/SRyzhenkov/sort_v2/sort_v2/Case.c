//  Case.c
//  sort_v2
//
//  Created by Ryzhenkov Serhii on 22/04/16.
//  Copyright © 2016 Ryzhenkov Serhii. All rights reserved.

#define SIZE_ARRAY_0 (500)
#define SIZE_ARRAY_1 (1000)
#define SIZE_ARRAY_2 (5000)
#define SIZE_ARRAY_3 (10000)


int Sorting_500() {

	int arrSize;
	int *SortArray = CreateArray(SIZE_ARRAY_0);
	int bubArray[SIZE_ARRAY_0];
	int SelArray[SIZE_ARRAY_0];
	int InsArray[SIZE_ARRAY_0];
	int ShellArray[SIZE_ARRAY_0];

	for (int z = 0; z < SIZE_ARRAY_0; z++) {
		bubArray[z] = SortArray[z];
		SelArray[z] = SortArray[z];
		InsArray[z] = SortArray[z];
		ShellArray[z] = SortArray[z];
	}

	//printArray(bubArray, sizeArray);
	bubbleSort(bubArray, SIZE_ARRAY_0);
	//printArray(bubArray, sizeArray);

	selectionSort(SelArray, SIZE_ARRAY_0);

	insertionSort(InsArray, SIZE_ARRAY_0);
	shellSort(ShellArray, SIZE_ARRAY_0);
}

int Sorting_1000() {

	int arrSize;
	int *SortArray = CreateArray(SIZE_ARRAY_1);
	int bubArray[SIZE_ARRAY_1];
	int SelArray[SIZE_ARRAY_1];
	int InsArray[SIZE_ARRAY_1];
	int ShellArray[SIZE_ARRAY_1];

	for (int z = 0; z < SIZE_ARRAY_1; z++) {
		bubArray[z] = SortArray[z];
		SelArray[z] = SortArray[z];
		InsArray[z] = SortArray[z];
		ShellArray[z] = SortArray[z];
	}

	//printArray(bubArray, sizeArray);
	bubbleSort(bubArray, SIZE_ARRAY_1);
	//printArray(bubArray, sizeArray);

	selectionSort(SelArray, SIZE_ARRAY_1);

	insertionSort(InsArray, SIZE_ARRAY_1);
	shellSort(ShellArray, SIZE_ARRAY_1);
}

int Sorting_5000() {

	int arrSize;
	int *SortArray = CreateArray(SIZE_ARRAY_2);
	int bubArray[SIZE_ARRAY_2];
	int SelArray[SIZE_ARRAY_2];
	int InsArray[SIZE_ARRAY_2];
	int ShellArray[SIZE_ARRAY_2];

	for (int z = 0; z < SIZE_ARRAY_2; z++) {
		bubArray[z] = SortArray[z];
		SelArray[z] = SortArray[z];
		InsArray[z] = SortArray[z];
		ShellArray[z] = SortArray[z];
	}

	//printArray(bubArray, sizeArray);
	bubbleSort(bubArray, SIZE_ARRAY_2);
	//printArray(bubArray, sizeArray);

	selectionSort(SelArray, SIZE_ARRAY_2);

	insertionSort(InsArray, SIZE_ARRAY_2);
	shellSort(ShellArray, SIZE_ARRAY_2);
}

int Sorting_10000() {

	int arrSize;
	int *SortArray = CreateArray(SIZE_ARRAY_3);
	int bubArray[SIZE_ARRAY_3];
	int SelArray[SIZE_ARRAY_3];
	int InsArray[SIZE_ARRAY_3];
	int ShellArray[SIZE_ARRAY_3];

	for (int z = 0; z < SIZE_ARRAY_3; z++) {
		bubArray[z] = SortArray[z];
		SelArray[z] = SortArray[z];
		InsArray[z] = SortArray[z];
		ShellArray[z] = SortArray[z];
	}

	//printArray(bubArray, sizeArray);
	bubbleSort(bubArray, SIZE_ARRAY_3);
	//printArray(bubArray, sizeArray);

	selectionSort(SelArray, SIZE_ARRAY_3);

	insertionSort(InsArray, SIZE_ARRAY_3);
	shellSort(ShellArray, SIZE_ARRAY_3);
}