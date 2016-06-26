/*																 /
/  compare.c			                                         /
/  compare sort                                                  /
/                                                                /
/  Created by Sergey Ninoshvili on 25/6/16.                      /
/  Copyright © 2016 Sergey Ninoshvili. All rights reserved.      /
/																*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "compare.h"

int *createArray(int size, int pivot)
{
	int *Array = (int*)malloc(size*sizeof(int));
	int i;

	srand(time(NULL));

	for (i = 0; i < size; i++)
		Array[i] = 1 + rand() % pivot;
	return Array;
}

void PArray(int *Array, int size)
{
	printf("{");
	int i;
	for (i = 0; i != size; i++)
		printf(" %d ", Array[i]);
	printf("}\n");
}

void bubbleRezult()
{
	int size = 10;
	int *Array;

	do
	{
		Array = createArray(size, size);

		if (size == 10)
		{
			printf("\ntesting bubble sort\n");
			PArray(Array, size);
		}
		clock_t Start = clock();
		bubbleSort(Array, size);
		clock_t Finish = clock();

		if(size == 10)
			PArray(Array, size);

		printf("time for %5d elements = %43.40lf\n", size, (double)((Finish - Start) / CLOCKS_PER_SEC));

		size = (size == 10000) ? 50000 : (size * 10);
	} while (size < 60000);

	free(Array);
}

void selectionRezult()
{
	int size = 10;
	int *Array;

	do
	{
		Array = createArray(size, size);

		if (size == 10)
		{
			printf("\ntesting selection sort\n");
			PArray(Array, size);
		}
		clock_t Start = clock();
		selectionSort(Array, size);
		clock_t Finish = clock();

		if (size == 10)
			PArray(Array, size);

		printf("time for %6d elements = %43.40lf\n", size, (double)((Finish - Start) / CLOCKS_PER_SEC));

		size = (size == 10000) ? 50000 : (size * 10);
	} while (size < 60000);

	free(Array);
}

void insertionRezult()
{
	int size = 10;
	int *Array;

	do
	{
		Array = createArray(size, size);

		if (size == 10)
		{
			printf("\ntesting insertion sort\n");
			PArray(Array, size);
		}
		clock_t Start = clock();
		insertionSort(Array, size);
		clock_t Finish = clock();

		if (size == 10)
			PArray(Array, size);

		printf("time for %6d elements = %43.40lf\n", size, (double)((Finish - Start) / CLOCKS_PER_SEC));

		size = (size == 10000) ? 50000 : (size * 10);
	} while (size < 60000);
}

void shellRezult()
{
	int size = 10;
	int *Array;

	do
	{
		Array = createArray(size, size);

		if (size == 10)
		{
			printf("\ntesting Shell sort\n");
			PArray(Array, size);
		}
		clock_t Start = clock();
		shellSort(Array, size);
		clock_t Finish = clock();

		if (size == 10)
			PArray(Array, size);

		printf("time for %6d elements = %43.40lf\n", size, (double)((Finish - Start) / CLOCKS_PER_SEC));

		size = (size == 10000) ? 50000 : (size * 10);
	} while (size < 60000);
}

void quickRezult()
{
	int size = 10;
	int *Array;
	int pivot;
	do
	{
		Array = createArray(size, size);

		if (size == 10)
		{
			printf("\ntesting quick sort\n");
			PArray(Array, size);
		}
		pivot = size / 2;
		partitionIt(Array, 0, size - 1, pivot);
		clock_t Start = clock();
		quickSort2(Array, 0, size - 1);
		clock_t Finish = clock();

		if (size == 10)
			PArray(Array, size);

		printf("time for %6d elements = %43.40lf\n", size, (double)((Finish - Start) / CLOCKS_PER_SEC));

		size = (size == 10000) ? 50000 : (size * 10);
	} while (size < 60000);
}