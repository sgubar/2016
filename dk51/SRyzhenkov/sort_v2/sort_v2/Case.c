//  Case.c
//  sort_v2
//
//  Created by Ryzhenkov Serhii on 22/04/16.
//  Copyright © 2016 Ryzhenkov Serhii. All rights reserved.

#define SIZE_ARRAY_0 (500)
#define SIZE_ARRAY_1 (1000)
#define SIZE_ARRAY_2 (5000)
#define SIZE_ARRAY_3 (10000)
#include "case.h"
#include <time.h>
#include <stdio.h>

int Sorting_500() {
	FILE * ptr = fopen("Plot.csv", "a+");

	int arrSize;
	int *SortArray = CreateArray(SIZE_ARRAY_0);
	int bubArray[SIZE_ARRAY_0];
	int SelArray[SIZE_ARRAY_0];
	int InsArray[SIZE_ARRAY_0];
	int ShellArray[SIZE_ARRAY_0];
	int QuickArray[SIZE_ARRAY_0];
	int QuickArray_v2[SIZE_ARRAY_0];

	for (int z = 0; z < SIZE_ARRAY_0; z++) {
		bubArray[z] = SortArray[z];
		SelArray[z] = SortArray[z];
		InsArray[z] = SortArray[z];
		ShellArray[z] = SortArray[z];
		QuickArray[z] = SortArray[z];
		QuickArray_v2[z] = SortArray[z];
	}

	//printArray(bubArray, sizeArray);
	bubbleSort(bubArray, SIZE_ARRAY_0);
	//printArray(bubArray, sizeArray);

	selectionSort(SelArray, SIZE_ARRAY_0);

	insertionSort(InsArray, SIZE_ARRAY_0);
	shellSort(ShellArray, SIZE_ARRAY_0);

	clock_t start_t5, end_t5, start_t6, end_t6;

	start_t5 = clock();

	quickSort(QuickArray, 0, 499);

	end_t5 = clock();
	printf("Going to scan a big loop, start_t = %ld\n", start_t5);
	printf("Going to scan a big loop, start_t = %ld\n", end_t5);

	printf("time of quickSort: %.3lf\n", (double)(end_t5 - start_t5) / CLOCKS_PER_SEC);
	fprintf(ptr, "Швидке сортування_1; %.3lf; \n", (double)(end_t5 - start_t5) / CLOCKS_PER_SEC);
	
	start_t6 = clock();
	quickSort_v2(QuickArray_v2, 0, 499);
	end_t6 = clock();
	printf("Going to scan a big loop, start_t = %ld\n", start_t6);
	printf("Going to scan a big loop, start_t = %ld\n", end_t6);

	printf("time of quickSort_v2: %.3lf\n", (double)(end_t6 - start_t6) / CLOCKS_PER_SEC);
	fprintf(ptr, "Швидке сортування_2; %.3lf; \n", (double)(end_t6 - start_t6) / CLOCKS_PER_SEC);
	fclose(ptr);

}

int Sorting_1000() {
	FILE * ptr = fopen("Plot.csv", "a+");

	int arrSize;
	int *SortArray = CreateArray(SIZE_ARRAY_1);
	int bubArray[SIZE_ARRAY_1];
	int SelArray[SIZE_ARRAY_1];
	int InsArray[SIZE_ARRAY_1];
	int ShellArray[SIZE_ARRAY_1];
	int QuickArray[SIZE_ARRAY_1];
	int QuickArray_v2[SIZE_ARRAY_1];

	for (int z = 0; z < SIZE_ARRAY_1; z++) {
		bubArray[z] = SortArray[z];
		SelArray[z] = SortArray[z];
		InsArray[z] = SortArray[z];
		ShellArray[z] = SortArray[z];
		QuickArray[z] = SortArray[z];
		QuickArray_v2[z] = SortArray[z];
	}

	//printArray(bubArray, sizeArray);
	bubbleSort(bubArray, SIZE_ARRAY_1);
	//printArray(bubArray, sizeArray);

	selectionSort(SelArray, SIZE_ARRAY_1);

	insertionSort(InsArray, SIZE_ARRAY_1);
	shellSort(ShellArray, SIZE_ARRAY_1);

	clock_t start_t5, end_t5, start_t6, end_t6;

	start_t5 = clock();
	quickSort(QuickArray, 0, 999); 
	end_t5 = clock();
	printf("Going to scan a big loop, start_t = %ld\n", start_t5);
	printf("Going to scan a big loop, start_t = %ld\n", end_t5);

	printf("time of quickSort: %.3lf\n", (double)(end_t5 - start_t5) / CLOCKS_PER_SEC);
	fprintf(ptr, "Швидке сортування_1; %.3lf; \n", (double)(end_t5 - start_t5) / CLOCKS_PER_SEC);
	

	start_t6 = clock();
	quickSort_v2(QuickArray_v2, 0, 999);
	end_t6 = clock();
	printf("Going to scan a big loop, start_t = %ld\n", start_t6);
	printf("Going to scan a big loop, start_t = %ld\n", end_t6);

	printf("time of quickSort: %.3lf\n", (double)(end_t6 - start_t6) / CLOCKS_PER_SEC);
	fprintf(ptr, "Швидке сортування_2; %.3lf; \n", (double)(end_t6 - start_t6) / CLOCKS_PER_SEC);
	fclose(ptr);
}

int Sorting_5000() {
	FILE * ptr = fopen("Plot.csv", "a+");

	int arrSize;
	int *SortArray = CreateArray(SIZE_ARRAY_2);
	int bubArray[SIZE_ARRAY_2];
	int SelArray[SIZE_ARRAY_2];
	int InsArray[SIZE_ARRAY_2];
	int ShellArray[SIZE_ARRAY_2];
	int QuickArray[SIZE_ARRAY_2];
	int QuickArray_v2[SIZE_ARRAY_2];

	for (int z = 0; z < SIZE_ARRAY_2; z++) {
		bubArray[z] = SortArray[z];
		SelArray[z] = SortArray[z];
		InsArray[z] = SortArray[z];
		ShellArray[z] = SortArray[z];
		QuickArray[z] = SortArray[z];
		QuickArray_v2[z] = SortArray[z];
	}

	//printArray(bubArray, sizeArray);
	bubbleSort(bubArray, SIZE_ARRAY_2);
	//printArray(bubArray, sizeArray);

	selectionSort(SelArray, SIZE_ARRAY_2);

	insertionSort(InsArray, SIZE_ARRAY_2);
	shellSort(ShellArray, SIZE_ARRAY_2);

	clock_t start_t5, end_t5, start_t6, end_t6;

	start_t5 = clock();
	quickSort(QuickArray, 0, 4999);
	end_t5 = clock();
	printf("Going to scan a big loop, start_t = %ld\n", start_t5);
	printf("Going to scan a big loop, start_t = %ld\n", end_t5);

	printf("time of quickSort: %.3lf\n", (double)(end_t5 - start_t5) / CLOCKS_PER_SEC);
	fprintf(ptr, "Швидке сортування_1; %.3lf; \n", (double)(end_t5 - start_t5) / CLOCKS_PER_SEC);


	start_t6 = clock();
	quickSort_v2(QuickArray_v2, 0, 4999);
	end_t6 = clock();
	printf("Going to scan a big loop, start_t = %ld\n", start_t6);
	printf("Going to scan a big loop, start_t = %ld\n", end_t6);

	printf("time of quickSort: %.3lf\n", (double)(end_t6 - start_t6) / CLOCKS_PER_SEC);
	fprintf(ptr, "Швидке сортування_2; %.3lf; \n", (double)(end_t6 - start_t6) / CLOCKS_PER_SEC);
	fclose(ptr);
}

int Sorting_10000() {
	FILE * ptr = fopen("Plot.csv", "a+");

	int arrSize;
	int *SortArray = CreateArray(SIZE_ARRAY_3);
	int bubArray[SIZE_ARRAY_3];
	int SelArray[SIZE_ARRAY_3];
	int InsArray[SIZE_ARRAY_3];
	int ShellArray[SIZE_ARRAY_3];
	int QuickArray[SIZE_ARRAY_3];
	int QuickArray_v2[SIZE_ARRAY_3];

	for (int z = 0; z < SIZE_ARRAY_3; z++) {
		bubArray[z] = SortArray[z];
		SelArray[z] = SortArray[z];
		InsArray[z] = SortArray[z];
		ShellArray[z] = SortArray[z];
		QuickArray[z] = SortArray[z];
		QuickArray_v2[z] = SortArray[z];
	}

	//printArray(bubArray, sizeArray);
	bubbleSort(bubArray, SIZE_ARRAY_3);
	//printArray(bubArray, sizeArray);

	selectionSort(SelArray, SIZE_ARRAY_3);

	insertionSort(InsArray, SIZE_ARRAY_3);
	shellSort(ShellArray, SIZE_ARRAY_3);
	clock_t start_t5, end_t5, start_t6, end_t6;

	start_t5 = clock();
	quickSort(QuickArray, 0, 9999);
	end_t5 = clock();
	printf("Going to scan a big loop, start_t = %ld\n", start_t5);
	printf("Going to scan a big loop, start_t = %ld\n", end_t5);

	printf("time of quickSort: %.3lf\n", (double)(end_t5 - start_t5) / CLOCKS_PER_SEC);
	fprintf(ptr, "Швидке сортування_1; %.3lf; \n", (double)(end_t5 - start_t5) / CLOCKS_PER_SEC);


	start_t6 = clock();
	quickSort_v2(QuickArray_v2, 0, 9999);
	end_t6 = clock();
	printf("Going to scan a big loop, start_t = %ld\n", start_t6);
	printf("Going to scan a big loop, start_t = %ld\n", end_t6);

	printf("time of quickSort: %.3lf\n", (double)(end_t6 - start_t6) / CLOCKS_PER_SEC);
	fprintf(ptr, "Швидке сортування_2; %.3lf; \n", (double)(end_t6 - start_t6) / CLOCKS_PER_SEC);
	fclose(ptr);
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
