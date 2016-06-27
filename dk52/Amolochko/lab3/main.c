#include <stdio.h>
#include <time.h> /*This library is used in order for that would take the time*/
#include <stdlib.h> /*This library is used in order to create with a array of random numbers*/
#include "quickSort.h"
#include "SimpleSort.h"
#include "shellSort.h"
#include "Adition.h"

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

//static void printArray(int anArray[], int aSize);
//static void gener_array(int *a,int *b,int *c,int *d,int *e);

void main()
{
	int a[1000]; /*declarete array whith integer values*/
	int b[1000];
	int c[1000];
	int d[1000];
	int e[1000];
	gener_array(a,b,c,d,e); /*fill an array of random numbers*/


	printf("Test bubble sorting\n");
	printArray(a, ARRAY_SIZE(a));
	clock_t theStart1 = clock(); /*starting clock*/
	bubbleSort(a, ARRAY_SIZE(a));
	clock_t theEnd1 = clock(); /*finish clock*/
	printArray(a, ARRAY_SIZE(a));
	printf ("time of Bubble sorting: %.10lf\n", (double)(theEnd1 - theStart1)/CLOCKS_PER_SEC);


	printf("\nTest selection sorting\n");
	printArray(b, ARRAY_SIZE(b));
	clock_t theStart2 = clock(); /*starting clock*/
	selectionSort(b, ARRAY_SIZE(b));
	clock_t theEnd2 = clock(); /*finish clock*/
	printArray(b, ARRAY_SIZE(b));
	printf ("time of Selection sorting: %.10lf\n", (double)(theEnd2 - theStart2)/CLOCKS_PER_SEC);


	printf("\nTest insertion sorting\n");
	printArray(c, ARRAY_SIZE(a));
	clock_t theStart3 = clock(); /*starting clock*/
	insertionSort(c, ARRAY_SIZE(a));
	clock_t theEnd3 = clock(); /*finish clock*/
	printArray(c, ARRAY_SIZE(a));
	printf ("time of Inserton sorting: %.10lf\n", (double)(theEnd3 - theStart3)/CLOCKS_PER_SEC);


	printf("\nTest Shell sorting\n");
	printArray(d, ARRAY_SIZE(a));
	clock_t theStart4 = clock(); /*starting clock*/
	shellSort(d, ARRAY_SIZE(a));
	clock_t theEnd4 = clock(); /*finish clock*/
	printArray(d, ARRAY_SIZE(a));
	printf ("time of Shell sorting: %.20lf\n", (double)(theEnd4 - theStart4)/CLOCKS_PER_SEC);
	

	printf("\nTest quickSort\n");
	printArray(e, ARRAY_SIZE(e));
	clock_t theStart5 = clock();
	quickSort(e, 0, ARRAY_SIZE(e) - 1);
	clock_t theEnd5 = clock();
	printArray(e, ARRAY_SIZE(e));
	printf ("time of quickSort : %.20lf\n", (double)(theEnd5 - theStart5)/CLOCKS_PER_SEC);
}


