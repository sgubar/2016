#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "QuickSort.h"
#include "ShellSort.h"
#include "SimpleSort.h"
#define arraySize(a)	sizeof(a)/sizeof(a[0])


void comparison();
int *copyIntArray(int *intArray, int intArraySize);
void fillIntArray(int *intArray, int arraySize);
int *newIntArray(int intArraySize);
void printIntArray(int *intArray, int intArraySize);

int main()
{
	comparison();

	system("pause");
	return 0;
}

void comparison(void)
{
	int i = 5000;
		for (int q = 0; q < 5; q++)
		{
			int *array0 = newIntArray(i);
			int arraySize = i;
			fillIntArray(array0, arraySize);

			int *array2 = newIntArray(arraySize);
			int *array3 = newIntArray(arraySize);
			int *array4 = newIntArray(arraySize);
			int *array5 = newIntArray(arraySize);

			array2 = copyIntArray(array0, arraySize);
			array3 = copyIntArray(array0, arraySize);
			array4 = copyIntArray(array0, arraySize);
			array5 = copyIntArray(array0, arraySize);
			/*
				printIntArray(array0, arraySize);
				printIntArray(array2, arraySize);
				printIntArray(array3, arraySize);
				printIntArray(array4, arraySize);
				printIntArray(array5, arraySize);
			*/
			clock_t timeDifference = 0;
			clock_t bubbleSortTime = 0;
			clock_t selectionSortTime = 0;
			clock_t insertionSortTime = 0;
			clock_t shellSortTime = 0;
			clock_t quickSortTime = 0;

			timeDifference = clock();
			bubbleSort(array0, arraySize);
			bubbleSortTime = clock() - timeDifference;

			timeDifference = clock();
			selectionSort(array2, arraySize);
			selectionSortTime = clock() - timeDifference;

			timeDifference = clock();
			insertionSort(array3, arraySize);
			insertionSortTime = clock() - timeDifference;

			timeDifference = clock();
			shellSort(array4, arraySize);
			shellSortTime = clock() - timeDifference;

			timeDifference = clock();
			quickSort(array5, 0, arraySize - 1);
			quickSortTime = clock() - timeDifference;
			/*
				printIntArray(array0, arraySize);
				printIntArray(array2, arraySize);
				printIntArray(array3, arraySize);
				printIntArray(array4, arraySize);
				printIntArray(array5, arraySize);
			*/

			printf("N = %d:\n", i);
			printf("BubbleSort: %d\n", bubbleSortTime);
			printf("SelectionSort: %d\n", selectionSortTime);
			printf("InsertionSort: %d\n", insertionSortTime);
			printf("ShellSort: %d\n", shellSortTime);
			printf("QuickSort: %d\n", quickSortTime);

			i = i * 2;
			printf("\n");
		}
}

int *copyIntArray(int *intArray, int intArraySize)
{
	
	int *returnArray = (int *)malloc(intArraySize * sizeof(int));
	int *ret = returnArray;
	for (int i = 0; i < intArraySize; i++)
	{
		*returnArray++ = *intArray++;
	}
	return ret;
}

void fillIntArray(int *intArray, int intArraySize)
{
	for (int i = 0; i < intArraySize; i++)
	{
		*intArray++ = rand();
	}
}

int *newIntArray(int intArraySize)
{
	int *returnArray = (int *)malloc(intArraySize * sizeof(int));
	return returnArray;
}

void printIntArray(int *intArray, int intArraySize)
{
	for (int i = 0, j = 0; i < intArraySize; i++, j++)
	{
		printf("%d\t", *intArray++);
		if (j > 9)
		{
			printf("\n");
			j = 0;
		}
	}
	printf("\n");
}