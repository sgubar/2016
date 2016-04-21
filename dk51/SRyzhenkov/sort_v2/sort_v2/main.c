#include <stdio.h>
#include "Sorting.h"

void printArray(int anArray[], int aSize);
int *CreateArray(int Size);

int main()
{
	int sizeArray = 20000;
	//printf_s("SizeArray: \n", &sizeArray);
	//scanf_s("10 = ", &sizeArray);
	//printf_s("SizeArray: \n", &sizeArray);

	int *testArray = CreateArray(sizeArray);

	bubbleSort(testArray, sizeArray);
	selectionSort(testArray, sizeArray);
	insertionSort(testArray, sizeArray);
	shellSort(testArray, sizeArray);

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

