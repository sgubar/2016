//
//  main.c
//  demoSimpleSort
//
//  Created by Slava Gubar on 4/7/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "SimpleSort.h"
#include "shellSort.h"
#include "quickSort.h"
//#include <graphics.h>

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

static void printArray(int anArray[], int aSize);
static void fillArray(int anArray[], int aSize);

int main(int argc, const char * argv[])
{
	clock_t  theStart, theEnd;

	int theArray4[10000];
	int theArray3[1000];
	int theArray2[100];
	int theArray1[10];

	fillArray(theArray4, ARRAY_SIZE(theArray4));
	fillArray(theArray3, ARRAY_SIZE(theArray3));
	fillArray(theArray2, ARRAY_SIZE(theArray2));
	fillArray(theArray1, ARRAY_SIZE(theArray1));

	////////////////////////////////////////////-test bubble sorting
	
	printf("**********Test bubble sorting**********\n");
	int theArrayA[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	printf("Unsorted array:\n");
	printArray(theArrayA, ARRAY_SIZE(theArrayA));
	bubbleSort(theArrayA, ARRAY_SIZE(theArrayA));
	printf("Sorted array:\n");
	printArray(theArrayA, ARRAY_SIZE(theArrayA));

	theStart = clock();
	bubbleSort(theArray4, ARRAY_SIZE(theArray4));
	theEnd = clock();
	printf("time of sorting 10000 numbers using Bubble sort: %.10lf\n", (double)(theEnd - theStart) / CLOCKS_PER_SEC);
	
	theStart = clock();
	bubbleSort(theArray3, ARRAY_SIZE(theArray3));
	theEnd = clock();
	printf("time of sorting 1000 numbers using Bubble sort: %.10lf\n", (double)(theEnd - theStart) / CLOCKS_PER_SEC);
	
	theStart = clock();
	bubbleSort(theArray2, ARRAY_SIZE(theArray2));
	theEnd = clock();
	printf("time of sorting 100 numbers using Bubble sort: %.10lf\n", (double)(theEnd - theStart) / CLOCKS_PER_SEC);
	
	theStart = clock();
	bubbleSort(theArray1, ARRAY_SIZE(theArray1));
	theEnd = clock();
	printf("time of sorting 10 numbers using Bubble sort: %.10lf\n", (double)(theEnd - theStart) / CLOCKS_PER_SEC);

	//printArray(theArray, ARRAY_SIZE(theArray));

	//////////////////////////////////////////////

	
	//////////////////////////////////////////////-test selection sorting
	printf("\n**********Test selection sorting**********\n");
	int theArrayB[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	printf("Unsorted array:\n");
	printArray(theArrayB, ARRAY_SIZE(theArrayB));
	selectionSort(theArrayB, ARRAY_SIZE(theArrayB));
	printf("Sorted array:\n");
	printArray(theArrayB, ARRAY_SIZE(theArrayB));

	theStart = clock();
	selectionSort(theArray4, ARRAY_SIZE(theArray4));
	theEnd = clock();
	printf("time of sorting 10000 numbers using Selection sort: %.10lf\n", (double)(theEnd - theStart) / CLOCKS_PER_SEC);

	theStart = clock();
	selectionSort(theArray3, ARRAY_SIZE(theArray3));
	theEnd = clock();
	printf("time of sorting 1000 numbers using Selection sort: %.10lf\n", (double)(theEnd - theStart) / CLOCKS_PER_SEC);

	theStart = clock();
	selectionSort(theArray2, ARRAY_SIZE(theArray2));
	theEnd = clock();
	printf("time of sorting 100 numbers using Selection sort: %.10lf\n", (double)(theEnd - theStart) / CLOCKS_PER_SEC);

	theStart = clock();
	selectionSort(theArray1, ARRAY_SIZE(theArray1));
	theEnd = clock();
	printf("time of sorting 10 numbers using Selection  sort: %.10lf\n", (double)(theEnd - theStart) / CLOCKS_PER_SEC);

	//////////////////////////////////////////////


	///////////////////////////////////////////////-test insertion sorting

	printf("\n**********Test insertion sorting**********\n");
	int theArrayC[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	printf("Unsorted array:\n");
	printArray(theArrayC, ARRAY_SIZE(theArrayC));
	insertionSort(theArrayC, ARRAY_SIZE(theArrayC));
	printf("Sorted array:\n");
	printArray(theArrayC, ARRAY_SIZE(theArrayC));

	theStart = clock();
	insertionSort(theArray4, ARRAY_SIZE(theArray4));
	theEnd = clock();
	printf("time of sorting 10000 numbers using Insertion sort: %.10lf\n", (double)(theEnd - theStart) / CLOCKS_PER_SEC);

	theStart = clock();
	insertionSort(theArray3, ARRAY_SIZE(theArray3));
	theEnd = clock();
	printf("time of sorting 1000 numbers using Insertion sort: %.20lf\n", (double)(theEnd - theStart) / CLOCKS_PER_SEC);

	theStart = clock();
	insertionSort(theArray2, ARRAY_SIZE(theArray2));
	theEnd = clock();
	printf("time of sorting 100 numbers using Insertion sort: %.10lf\n", (double)(theEnd - theStart) / CLOCKS_PER_SEC);

	theStart = clock();
	insertionSort(theArray1, ARRAY_SIZE(theArray1));
	theEnd = clock();
	printf("time of sorting 10 numbers using Insertion sort: %.10lf\n", (double)(theEnd - theStart) / CLOCKS_PER_SEC);

	//////////////////////////////////////////////
	

	///////////////////////////////////////////// -test Shell sorting
	
	printf("\n**********Test Shell sorting**********\n");
	int theArrayD[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	printf("Unsorted array:\n");
	printArray(theArrayD, ARRAY_SIZE(theArrayD));
	shellSort(theArrayD, ARRAY_SIZE(theArrayD));
	printf("Sorted array:\n");
	printArray(theArrayD, ARRAY_SIZE(theArrayD));

	theStart = clock();
	shellSort(theArray4, ARRAY_SIZE(theArray4));
	theEnd = clock();
	printf("time of sorting 10000 numbers using Shell sort: %.10lf\n", (double)(theEnd - theStart) / CLOCKS_PER_SEC);

	theStart = clock();
	shellSort(theArray3, ARRAY_SIZE(theArray3));
	theEnd = clock();
	printf("time of sorting 1000 numbers using Shell sort: %.10lf\n", (double)(theEnd - theStart) / CLOCKS_PER_SEC);

	theStart = clock();
	shellSort(theArray2, ARRAY_SIZE(theArray2));
	theEnd = clock();
	printf("time of sorting 100 numbers using Shell sort: %.10lf\n", (double)(theEnd - theStart) / CLOCKS_PER_SEC);

	theStart = clock();
	shellSort(theArray1, ARRAY_SIZE(theArray1));
	theEnd = clock();
	printf("time of sorting 10 numbers using Shell sort: %.10lf\n", (double)(theEnd - theStart) / CLOCKS_PER_SEC);

	/////////////////////////////////////////////

	/////////////////////////////////////////// - test Quick sort

	printf("\n**********Test Quick sorting**********\n");
	int theArrayE[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	printf("Unsorted array:\n");
	printArray(theArrayE, ARRAY_SIZE(theArrayE) );
	quickSort(theArrayE, 0, ARRAY_SIZE(theArrayE)-1);
	printf("Sorted array:\n");
	printArray(theArrayE, ARRAY_SIZE(theArrayE));

	/*
	theStart = clock();
	quickSort(theArray4, 0, ARRAY_SIZE(theArray4)-1);
	theEnd = clock();
	printf("time of sorting 10000 numbers using Quick sort: %.10lf\n", (double)(theEnd - theStart) / CLOCKS_PER_SEC);
	*/
	
	theStart = clock();
	quickSort(theArray3, 0, ARRAY_SIZE(theArray3)-1);
	theEnd = clock();
	printf("time of sorting 1000 numbers using Quick sort: %.10lf\n", (double)(theEnd - theStart) / CLOCKS_PER_SEC);
	
	theStart = clock();
	quickSort(theArray2, 0, ARRAY_SIZE(theArray2)-1);
	theEnd = clock();
	printf("time of sorting 100 numbers using Quick sort: %.10lf\n", (double)(theEnd - theStart) / CLOCKS_PER_SEC);
	
	theStart = clock();
	quickSort(theArray1, 0, ARRAY_SIZE(theArray1)-1);
	theEnd = clock();
	printf("time of sorting 10 numbers using Quick sort: %.10lf\n", (double)(theEnd - theStart) / CLOCKS_PER_SEC);

	/////////////////////////////////////////////

	//////////////////////////////////////////// -test quick sort 2

	printf("\n**********Test Quick sorting 2**********\n");
	int theArrayF[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	printf("Unsorted array:\n");
	printArray(theArrayF, ARRAY_SIZE(theArrayF));
	quickSort2(theArrayF, 0, ARRAY_SIZE(theArrayF) - 1);
	printf("Sorted array:\n");
	printArray(theArrayF, ARRAY_SIZE(theArrayF));

	/*
	theStart = clock();
	quickSort(theArray4, 0, ARRAY_SIZE(theArray4)-1);
	theEnd = clock();
	printf("time of sorting 10000 numbers using Quick sort 2: %.10lf\n", (double)(theEnd - theStart) / CLOCKS_PER_SEC);
	*/

	theStart = clock();
	quickSort2(theArray3, 0, ARRAY_SIZE(theArray3) - 1);
	theEnd = clock();
	printf("time of sorting 1000 numbers using Quick sort 2: %.10lf\n", (double)(theEnd - theStart) / CLOCKS_PER_SEC);

	theStart = clock();
	quickSort2(theArray2, 0, ARRAY_SIZE(theArray2) - 1);
	theEnd = clock();
	printf("time of sorting 100 numbers using Quick sort 2: %.10lf\n", (double)(theEnd - theStart) / CLOCKS_PER_SEC);

	theStart = clock();
	quickSort2(theArray1, 0, ARRAY_SIZE(theArray1) - 1);
	theEnd = clock();
	printf("time of sorting 10 numbers using Quick sort 2: %.10lf\n", (double)(theEnd - theStart) / CLOCKS_PER_SEC);

	///////////////////////////////////////////


	printf("Done!\n");
	return 0;
}

#pragma mark -
void printArray(int anArray[], int aSize)
{
	printf("{");
	for (int i = 0; i < aSize; i++)
	{
		printf(" %d ", anArray[i]);
	}

	printf("}\n");
}

void fillArray(int anArray[], int aSize)
{
	for (int i=0; i<aSize; i++)
	{
		anArray[i] = rand();
	}
}