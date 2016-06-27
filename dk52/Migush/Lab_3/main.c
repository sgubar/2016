#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "SimpleSort.h"
#include "shellSort.h"
#include "quickSort.h"

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

static void printArray(int anArray[], int aSize);
int *CreateFillArray(int SizeArr);

int SizeArr;
int main(int argc, const char * argv[])
{
    printf("Enter your array lenght");
    scanf("%d",&SizeArr);


	printf("Test bubble sorting\n");
	int*Array=CreateFillArray(SizeArr);
    clock_t theStart0 = clock();
	bubbleSort(Array,SizeArr);
	clock_t theEnd0 = clock();
	printf ("time of bubble sorting: %.10lf\n", (double)(theEnd0 - theStart0)/CLOCKS_PER_SEC);

	printf("Test insertion sorting\n");
    Array=CreateFillArray(SizeArr);
    clock_t theStart3 = clock();
    insertionSort(Array,SizeArr);
    clock_t theEnd3 = clock();
	printf ("time of insertion sorting: %.10lf\n", (double)(theEnd3 - theStart3)/CLOCKS_PER_SEC);



	printf("\nTest selection sorting\n");
	Array=CreateFillArray(SizeArr);
	clock_t theStart1 = clock();
	selectionSort(Array,SizeArr);
	clock_t theEnd1 = clock();
	printf ("time of Selection sorting: %.10lf\n", (double)(theEnd1 - theStart1)/CLOCKS_PER_SEC);

	printf("\nTest Shell sorting\n");
    Array=CreateFillArray(SizeArr);
    clock_t theStart = clock();
	shellSort(Array,SizeArr);
	clock_t theEnd = clock();
	printf ("time of Shell sorting: %.10lf\n", (double)(theEnd - theStart)/CLOCKS_PER_SEC);

	printf("\nTest Quick sorting\n");
    Array=CreateFillArray(SizeArr);
	clock_t theStartQuick = clock();
	quickSort2(Array,0,SizeArr - 1);
	clock_t theEndQuick = clock();
    printf ("time of sorting: %.10lf\n", (double)(theEndQuick - theStartQuick)/CLOCKS_PER_SEC);


	system("pause");
}

int*CreateFillArray(int SizeArr)
{
    int i;
    int *Arr = malloc(SizeArr*sizeof(int));
    for (i=0;i<SizeArr;i++)
    {
    Arr[i] = rand() %100;
    }
    return Arr;
}
