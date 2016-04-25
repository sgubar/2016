#include <stdio.h>
#include <time.h>
#include "SimpleSort.h"
#include "shellSort.h"
#include <stdlib.h>

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

static void printArray(int anArray[], int aSize);
void gen_array(int *a);

void main()
{
	int a[1000];
	gen_array(a);

	printf("Test bubble sorting\n");
	printArray(a, ARRAY_SIZE(a));

	clock_t theStartt = clock();
	bubbleSort(a, ARRAY_SIZE(a));
	clock_t theEndt = clock();
	printArray(a, ARRAY_SIZE(a));
	printf ("time of bubble sorting: %.10lf\n", (double)(theEndt - theStartt)/CLOCKS_PER_SEC);

	gen_array(a);

	printf("\nTest selection sorting\n");
	printArray(a, ARRAY_SIZE(a));

	clock_t theStart1 = clock();
	selectionSort(a, ARRAY_SIZE(a));
	clock_t theEnd1 = clock();
	printArray(a, ARRAY_SIZE(a));
	printf ("time of Selection sorting: %.10lf\n", (double)(theEnd1 - theStart1)/CLOCKS_PER_SEC);

	gen_array(a);

	printf("\nTest insertion sorting\n");
	printArray(a, ARRAY_SIZE(a));

	clock_t theStart0 = clock();
	insertionSort(a, ARRAY_SIZE(a));
	clock_t theEnd0 = clock();
	printArray(a, ARRAY_SIZE(a));
	printf ("time of Selection sorting: %.10lf\n", (double)(theEnd0 - theStart0)/CLOCKS_PER_SEC);

	gen_array(a);

	printf("\nTest Shell sorting\n");
	printArray(a, ARRAY_SIZE(a));

	clock_t theStart = clock();
	shellSort(a, ARRAY_SIZE(a));
	clock_t theEnd = clock();
	printArray(a, ARRAY_SIZE(a));
	printf ("time of Shell sorting: %.10lf\n", (double)(theEnd - theStart)/CLOCKS_PER_SEC);

}

void printArray(int anArray[], int aSize)
{
	int i;
	printf("{");
	for (i = 0; i < aSize; i++)
	{
		printf(" %d ", anArray[i]);
	}

	printf("}\n");
}

void gen_array(int *a)
{
	int i;
	for(i=0; i<1000; i++)
	{
		a[i] = rand()%10;
	}
	printf("\n");
}
