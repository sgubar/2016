
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "SimpleSort.h"
#include "shellSort.h"

#define ARRAY_SIZE(a) (sizeof(theArray)/sizeof(theArray[0]))

static void printArray(int anArray[], int aSize);

int main(int argc, const char * argv[])
{
	int theArray[12000];
	int theArray2[12000];
	int theArray3[12000];
	int theArray4[12000];
	srand(time(NULL));
	for (int i = 0; i < 12000; i++)
	{
		theArray[i] = rand();
		theArray2[i] = theArray[i];
		theArray3[i] = theArray[i];
		theArray4[i] = theArray[i];
	}




	printf("Bubble sort\n");
	clock_t theStart2 = clock();
	bubbleSort(theArray, ARRAY_SIZE(theArray));
	clock_t theEnd2 = clock();
	printf("Time of bubble sorting: %.15lf\n", (double)(theEnd2 - theStart2) / CLOCKS_PER_SEC);

	printf("\nSelection sort\n");

	clock_t theStart1 = clock();
	selectionSort(theArray2, ARRAY_SIZE(theArray2));
	clock_t theEnd1 = clock();
	printf("Time of selection sorting: %.15lf\n", (double)(theEnd1 - theStart1) / CLOCKS_PER_SEC);

	printf("\nInsertion sort\n");

	clock_t theStart0 = clock();
	insertionSort(theArray3, ARRAY_SIZE(theArray3));
	clock_t theEnd0 = clock();
	printf("Time of insertion sorting: %.15lf\n", (double)(theEnd0 - theStart0) / CLOCKS_PER_SEC);

	printf("\nShell sort\n");

	clock_t theStart = clock();
	shellSort(theArray4, ARRAY_SIZE(theArray4));
	clock_t theEnd = clock();

	printf("Time of Shell sorting: %.15lf\n", (double)(theEnd - theStart) / CLOCKS_PER_SEC);

	system("pause");
	return 0;
}