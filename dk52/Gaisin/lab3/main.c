#include <stdio.h>
#include <time.h> /*This library is used in order for that would take the time*/
#include "SimpleSort.h"
#include "shellSort.h"
#include <stdlib.h> /*This library is used in order to create with a array of random numbers*/

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

static void printArray(int anArray[], int aSize);
void gen_array(int *a); /*declarete function*/

void main()
{
	int a[1000]; /*declarete array whith integer values*/
	gen_array(a); /*fill an array of random numbers*/


	printf("Test bubble sorting\n");
	printArray(a, ARRAY_SIZE(a));

	clock_t theStartt = clock(); /*starting clock*/
	bubbleSort(a, ARRAY_SIZE(a));
	clock_t theEndt = clock(); /*finish clock*/
	printArray(a, ARRAY_SIZE(a));
	printf ("time of Bubble sorting: %.10lf\n", (double)(theEndt - theStartt)/CLOCKS_PER_SEC);


	gen_array(a); /*assigned array new value*/


	printf("\nTest selection sorting\n");
	printArray(a, ARRAY_SIZE(a));

	clock_t theStart1 = clock(); /*starting clock*/
	selectionSort(a, ARRAY_SIZE(a));
	clock_t theEnd1 = clock(); /*finish clock*/
	printArray(a, ARRAY_SIZE(a));
	printf ("time of Selection sorting: %.10lf\n", (double)(theEnd1 - theStart1)/CLOCKS_PER_SEC);


	gen_array(a); /*assigned array new value*/


	printf("\nTest insertion sorting\n");
	printArray(a, ARRAY_SIZE(a));

	clock_t theStart0 = clock(); /*starting clock*/
	insertionSort(a, ARRAY_SIZE(a));
	clock_t theEnd0 = clock(); /*finish clock*/
	printArray(a, ARRAY_SIZE(a));
	printf ("time of Inserton sorting: %.10lf\n", (double)(theEnd0 - theStart0)/CLOCKS_PER_SEC);


	gen_array(a); /*assigned array new value*/


	printf("\nTest Shell sorting\n");
	printArray(a, ARRAY_SIZE(a));

	clock_t theStart = clock(); /*starting clock*/
	shellSort(a, ARRAY_SIZE(a));
	clock_t theEnd = clock(); /*finish clock*/
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

void gen_array(int *a) /*fanction that craete numbers*/
{
	int i;
	for(i=0; i<1000; i++)
	{
		a[i] = rand()%10; /*assigned cell array random number (0<= number <10)*/
	}
	printf("\n");
}
