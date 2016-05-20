#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "SimpleSort.h"
#include "shellSort.h"
#include "quickSort.h"

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
#define ArraySize 10000
static void printArray(int anArray[], int aSize);

int main(int argc, const char * argv[])
{
	clock_t time, time1, time2, time3;
	int theArray[ArraySize];
	int theArray1[ArraySize];
	int theArray2[ArraySize];
	int theArray3[ArraySize];

	for (int i = 0; i < 10000; i++)
	{
		theArray[i] = rand();
		theArray1[i] = theArray[i];
		theArray2[i] = theArray[i];
		theArray3[i] = theArray[i];
	}

	printf("Bubble sorting\n");
	clock_t theStart = clock();
	bubbleSort(theArray, ARRAY_SIZE(theArray));
	clock_t theEnd = clock();
	printf("Bubble sorting Done\n");

	printf("Insertion sorting\n");
	clock_t theStart1 = clock();
	insertionSort(theArray1, ARRAY_SIZE(theArray1));
	clock_t theEnd1 = clock();
	printf("insertion sorting Done\n");

	printf("Shell sorting\n");
	clock_t theStart2 = clock();
	bubbleSort(theArray2, ARRAY_SIZE(theArray2));
	clock_t theEnd2 = clock();
	printf("Shell sorting Done\n");

	printf("Selection sorting\n");
	clock_t theStart3 = clock();
	selectionSort(theArray3, ARRAY_SIZE(theArray3));
	clock_t theEnd3 = clock();
	printf("Selection sorting Done\n");

	printf("All sorting is done\n");
	printf("Results of sorting:\n");
	printf("Bubble sorting: %.5f\n", (double)(theEnd - theStart) / CLOCKS_PER_SEC);
	printf("Insertion sorting: %.5f\n", (double)(theEnd1 - theStart1) / CLOCKS_PER_SEC);
	printf("Selection sorting: %.5f\n", (double)(theEnd3 - theStart3) / CLOCKS_PER_SEC);
	printf("Shell sorting: %.5f\n", (double)(theEnd2 - theStart2) / CLOCKS_PER_SEC);

	system("pause");
}