//
//  main.c
//  
//
//  Created by Sergey Fedorenko on 5/18/16.
//  Copyright © 2016 Sergey Fedorenko. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Simplesort.h"
#include "quicksort.h"
#include "Shellsort.h"

#define ARRAY_SIZE(a) (sizeof(theArray)/sizeof(theArray[0]))
#define ArraySize 25000
static void printArray(int anArray[], int aSize);

int main(int argc, const char * argv[])
{
	int theArray[ArraySize];
	int Num;
	int theArray1[ArraySize];
	int theArray2[ArraySize];
	int theArray3[ArraySize];
	int theArray4[ArraySize];
	int theArray5[ArraySize];
	srand(time(NULL));
	for (Num = 0; Num < ArraySize; Num++)
	{
		theArray[Num] = 0 + rand() % ArraySize;
		theArray1[Num] = theArray[Num];
		theArray2[Num] = theArray[Num];
		theArray3[Num] = theArray[Num];
		theArray4[Num] = theArray[Num];
		theArray5[Num] = theArray[Num];
	}

	printf("Wait, until program test the bubble sorting...");

	clock_t theStart1 = clock();
	bubbleSort(theArray1, ARRAY_SIZE(theArray1));
	clock_t theEnd1 = clock();
	printf("Done\n");


	printf("Wait, until program test the selection sorting...");
	clock_t theStart2 = clock();
	selectionSort(theArray2, ARRAY_SIZE(theArray2));
	clock_t theEnd2 = clock();
	printf("Done\n");

	

	printf("Wait, until program test the insertion sorting...");
	clock_t theStart3 = clock();
	insertionSort(theArray3, ARRAY_SIZE(theArray3));
	clock_t theEnd3 = clock();
	printf("Done\n");

	
	printf("Wait, until program test the quick sorting...");
	clock_t theStart4 = clock();
	quickSort2(theArray4, 0, ARRAY_SIZE(theArray4) - 1);
	clock_t theEnd4 = clock();
	printf("Done\n");



	printf("Wait, until program test the Shell sorting...");
	clock_t theStart5 = clock();
	ShellSort(theArray5, ARRAY_SIZE(theArray5));
	clock_t theEnd5 = clock();
	printf("Done\n\n");


	printf("It's done:\n");
	printf("Time of bubble sorting: %.10f\n", (double)(theEnd1 - theStart1) / CLOCKS_PER_SEC);
	printf("Time of selection sorting: %.10f\n", (double)(theEnd2 - theStart2) / CLOCKS_PER_SEC);
	printf("Time of insertion sorting: %.10f\n", (double)(theEnd3 - theStart3) / CLOCKS_PER_SEC);
	printf("Time of Shell sorting: %.10f\n", (double)(theEnd5 - theStart5) / CLOCKS_PER_SEC);
	printf("Time of Quick sorting: %.20f\n\n", (double)(theEnd4 - theStart4) / CLOCKS_PER_SEC);




	system("pause");
}



