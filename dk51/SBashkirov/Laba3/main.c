//
//  main.c
//  demoSimpleSort
//
//  Created by Slava Gubar on 4/7/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include "SimpleSort.h"
#include "shellSort.h"

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

static void printArray(int anArray[], int aSize);

int theArrayB1[100000];
int theArrayS1[100000];
int theArrayI1[100000];
int theArraySh1[100000];
int theArrayQ1[100000];

int theArrayB3[50000];
int theArrayS3[50000];
int theArrayI3[50000];
int theArraySh3[50000];
int theArrayQ3[50000];

int theArrayB2[10000];
int theArrayS2[10000];
int theArrayI2[10000];
int theArraySh2[10000];
int theArrayQ2[10000];

int main(int argc, const char * argv[])
{
	srand(time(NULL));
	for (int i = 0;i < 10000;i++)
	{
		theArrayB2[i] = rand();
		theArrayS2[i] = theArrayB2[i];
		theArrayI2[i] = theArrayB2[i];
		theArraySh2[i] = theArrayB2[i];
		theArrayQ2[i] = theArrayB2[i];
	}


	srand(time(NULL));
	for (int i = 0;i < 50000;i++)
	{
		theArrayB3[i] = rand();
		theArrayS3[i] = theArrayB3[i];
		theArrayI3[i] = theArrayB3[i];
		theArraySh3[i] = theArrayB3[i];
		theArrayQ3[i] = theArrayB3[i];
	}

	srand(time(NULL));
	for (int i = 0;i < 100000;i++)
	{
		theArrayB1[i] = rand();
		theArrayS1[i] = theArrayB1[i];
		theArrayI1[i] = theArrayB1[i];
		theArraySh1[i] = theArrayB1[i];
		theArrayQ1[i] = theArrayB1[i];
	} 


	printf("            10000           50000          100000\n");

	printf("Buble       ");
	clock_t theStart2 = clock();
	bubbleSort(theArrayB2, ARRAY_SIZE(theArrayB2));
	clock_t theEnd2 = clock();
	printf("%.6lf        ", (double)(theEnd2 - theStart2) / CLOCKS_PER_SEC);
	clock_t theStart5 = clock();
	bubbleSort(theArrayB3, ARRAY_SIZE(theArrayB3));
	clock_t theEnd5 = clock();
	printf("%.6lf       ", (double)(theEnd5 - theStart5) / CLOCKS_PER_SEC);
	clock_t theStart6 = clock();
	bubbleSort(theArrayB1, ARRAY_SIZE(theArrayB1));
	clock_t theEnd6 = clock();
	printf("%.6lf\n", (double)(theEnd6 - theStart6) / CLOCKS_PER_SEC);

	printf("Selection   ");
	clock_t theStart7 = clock();
	selectionSort(theArrayS2, ARRAY_SIZE(theArrayS2));
	clock_t theEnd7 = clock();
	printf("%.6lf        ", (double)(theEnd7 - theStart7) / CLOCKS_PER_SEC);
	clock_t theStart8 = clock();
	selectionSort(theArrayS3, ARRAY_SIZE(theArrayS3));
	clock_t theEnd8 = clock();
	printf("%.6lf       ", (double)(theEnd8 - theStart8) / CLOCKS_PER_SEC);
	clock_t theStart9 = clock();
	selectionSort(theArrayS1, ARRAY_SIZE(theArrayB1));
	clock_t theEnd9 = clock();
	printf("%.6lf\n", (double)(theEnd9 - theStart9) / CLOCKS_PER_SEC);

	printf("Insertion   ");
	clock_t theStart10 = clock();
	insertionSort(theArrayI2, ARRAY_SIZE(theArrayI2));
	clock_t theEnd10 = clock();
	printf("%.6lf        ", (double)(theEnd10 - theStart10) / CLOCKS_PER_SEC);
	clock_t theStart11 = clock();
	insertionSort(theArrayI3, ARRAY_SIZE(theArrayI3));
	clock_t theEnd11 = clock();
	printf("%.6lf       ", (double)(theEnd11 - theStart11) / CLOCKS_PER_SEC);
	clock_t theStart12 = clock();
	insertionSort(theArrayI1, ARRAY_SIZE(theArrayI1));
	clock_t theEnd12 = clock();
	printf("%.6lf\n", (double)(theEnd12 - theStart12) / CLOCKS_PER_SEC);

	printf("Shell       ");
	clock_t theStart13 = clock();
	shellSort(theArraySh2, ARRAY_SIZE(theArraySh2));
	clock_t theEnd13 = clock();
	printf("%.6lf        ", (double)(theEnd13 - theStart13) / CLOCKS_PER_SEC);
	clock_t theStart14 = clock();
	shellSort(theArraySh3, ARRAY_SIZE(theArraySh3));
	clock_t theEnd14 = clock();
	printf("%.6lf       ", (double)(theEnd14 - theStart14) / CLOCKS_PER_SEC);
	clock_t theStart15 = clock();
	shellSort(theArraySh1, ARRAY_SIZE(theArraySh1));
	clock_t theEnd15 = clock();
	printf("%.6lf\n", (double)(theEnd15 - theStart15) / CLOCKS_PER_SEC);

	printf("Quick       ");
	clock_t theStart16 = clock();
	quickSort2(theArrayQ2,0, ARRAY_SIZE(theArrayQ2)-1);
	clock_t theEnd16 = clock();
	printf("%.6lf        ", (double)(theEnd16 - theStart16) / CLOCKS_PER_SEC);
	clock_t theStart17 = clock();
	quickSort2(theArrayQ3, 0, ARRAY_SIZE(theArrayQ3) - 1);
	clock_t theEnd17 = clock();
	printf("%.6lf       ", (double)(theEnd17 - theStart17) / CLOCKS_PER_SEC);
	clock_t theStart18 = clock();
	quickSort2(theArrayQ1, 0, ARRAY_SIZE(theArrayQ1) - 1);
	clock_t theEnd18 = clock();
	printf("%.6lf\n", (double)(theEnd18 - theStart18) / CLOCKS_PER_SEC);
	


	system("pause");
}