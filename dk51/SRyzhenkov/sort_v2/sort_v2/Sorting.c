//  Sorting.c
//  sort_v2
//
//  Created by Ryzhenkov Serhii on 21/04/16.
//  Copyright © 2016 Ryzhenkov Serhii. All rights reserved.

#include "Sorting.h"
#include <time.h>
#include <stdio.h>

void bubbleSort(int anArray[], int aSize)
{
	FILE * ptr = fopen("Plot.csv", "a+");
	clock_t start_t1, end_t1;

	start_t1 = clock();

	for (int theOut = aSize - 1; theOut > 1; theOut--)
	{
		for (int theIn = 0; theIn < theOut; theIn++)
		{
			if (anArray[theIn] > anArray[theIn + 1])
			{
				int theTmp = anArray[theIn];
				anArray[theIn] = anArray[theIn + 1];
				anArray[theIn + 1] = theTmp;
			}
		}
	}

	end_t1 = clock();
	printf("Going to scan a big loop, start_t = %ld\n", start_t1);
	printf("Going to scan a big loop, start_t = %ld\n", end_t1);
	fprintf(ptr, "Методи сортування;\nСортування бульбашкою; %.3lf; %i\n", (double)(end_t1 - start_t1) / CLOCKS_PER_SEC, aSize);
	printf("time of bubbleSort: %.3lf\n", (double)(end_t1 - start_t1) / CLOCKS_PER_SEC);
	fclose(ptr);
}

void selectionSort(int anArray[], int aSize)
{	
	FILE * ptr = fopen("Plot.csv", "a+");
	clock_t start_t2, end_t2;

	start_t2 = clock();

	for (int theOut = 0; theOut < aSize - 1; theOut++)
	{
		int theMinIndex = theOut;

		for (int theIn = theOut + 1; theIn < aSize; theIn++)
		{
			if (anArray[theIn] < anArray[theMinIndex])
			{
				theMinIndex = theIn;
			}
		}

		int theTmp = anArray[theOut];
		anArray[theOut] = anArray[theMinIndex];
		anArray[theMinIndex] = theTmp;
	}

	end_t2 = clock();
	printf("Going to scan a big loop, start_t = %ld\n", start_t2);
	printf("Going to scan a big loop, start_t = %ld\n", end_t2);
	fprintf(ptr, "Сортування методом вибору; %.3lf; %i\n", (double)(end_t2 - start_t2) / CLOCKS_PER_SEC, aSize);
	printf("time of Selection sorting: %.3lf\n", (double)(end_t2 - start_t2) / CLOCKS_PER_SEC);
	fclose(ptr);
}

void insertionSort(int anArray[], int aSize)
{	
	FILE * ptr = fopen("Plot.csv", "a+");
	clock_t start_t3, end_t3;

	start_t3 = clock();

	for (int theOut = 1; theOut < aSize; theOut++)
	{
		int theTmp = anArray[theOut];
		int theIn = theOut;

		while (theIn > 0 && anArray[theIn - 1] >= theTmp)
		{
			anArray[theIn] = anArray[theIn - 1];
			--theIn;
		}

		anArray[theIn] = theTmp;
	}
	end_t3 = clock();
	printf("Going to scan a big loop, start_t = %ld\n", start_t3);
	printf("Going to scan a big loop, start_t = %ld\n", end_t3);
	fprintf(ptr, "Сортування вставкою; %.3lf; %i\n", (double)(end_t3 - start_t3) / CLOCKS_PER_SEC, aSize);
	printf("time of insertionSort: %.3lf\n", (double)(end_t3 - start_t3) / CLOCKS_PER_SEC);
	fclose(ptr);
}

void shellSort(int anArray[], int aCount)
{
	FILE * ptr = fopen("Plot.csv", "a+");
	clock_t start_t4, end_t4;
	int theInner = 0;
	int theOuter = 0;
	int theH = 1; // start h = 1
	
				  //1. Calculate start value of h
	while (theH <= aCount / 3)
	{
		theH = theH * 3 + 1; // 1, 4, 13, 40, 121, ....
	}
	

	start_t4 = clock();
	//2. Sequental decrease h to 1
	while (theH > 0)
	{
		for (theOuter = theH; theOuter < aCount; theOuter++)
		{
			int theTmp = anArray[theOuter];
			theInner = theOuter;

			// the first sub-array {0, 4, 8}
			while (theInner > theH - 1 && anArray[theInner - theH] >= theTmp)
			{
				anArray[theInner] = anArray[theInner - theH];
				theInner -= theH;
			}

			anArray[theInner] = theTmp;
		}

		theH = (theH - 1) / 3; //decrease h
	}
	end_t4 = clock();
	printf("Going to scan a big loop, start_t = %ld\n", start_t4);
	printf("Going to scan a big loop, start_t = %ld\n", end_t4);
	fprintf(ptr, "Сортування Шелла; %.3lf; %i\n", (double)(end_t4 - start_t4) / CLOCKS_PER_SEC, aCount);
	printf("time of shellSort: %.3lf\n", (double)(end_t4 - start_t4) / CLOCKS_PER_SEC);
	fclose(ptr);
}

static void swap(int anArray[], int aLeftIndex, int aRightIndex);
static int mediana(int anArray[], int aLeftIndex, int aRightIndex);
static int m_partitionIt(int anArray[], int aLeftIndex, int aRightIndex, int aPivot);
static void m_manualSort(int anArray[], int aLeftIndex, int aRightIndex);

#if 0 //{
int partitionIt(int anArray[], int aLeftIndex, int aRightIndex, int aPivot)
{
	int theLeft = aLeftIndex - 1;
	int theRight = aRightIndex + 1;

	while (1)
	{
		// search the bigest element
		while (theLeft < aRightIndex && anArray[++theLeft] < aPivot);

		// search the lowest element
		while (theRight > aLeftIndex && anArray[--theRight] > aPivot);

		if (theLeft >= theRight) // pointer are the same 
		{
			break;
		}
		else
		{
			//lets to swap elements
			int theTmp = anArray[theLeft];
			anArray[theLeft] = anArray[theRight];
			anArray[theRight] = theTmp;
		}
	}

	return theLeft; // return break position
}
#else //}{

int partitionIt(int anArray[], int aLeftIndex, int aRightIndex, int aPivot)
{
	int theLeft = aLeftIndex - 1;
	int theRight = aRightIndex;

	while (1)
	{
		// search the bigest element
		while (anArray[++theLeft] < aPivot);

		// search the lowest element
		while (theRight > 0 && anArray[--theRight] > aPivot);

		if (theLeft >= theRight) // pointer are the same 
		{
			break;
		}
		else
		{
			//lets to swap elements
			int theTmp = anArray[theLeft];
			anArray[theLeft] = anArray[theRight];
			anArray[theRight] = theTmp;
		}
	}

	//lets to swap elements
	int theTmp = anArray[theLeft];
	anArray[theLeft] = anArray[aRightIndex];
	anArray[aRightIndex] = theTmp;

	return theLeft; // return break position
}
#endif

void quickSort(int anArray[], int aLeftIndex, int aRightIndex)
{
	
	
	if (aRightIndex - aLeftIndex <= 0)
	{
		return; // the array size equals to 1 - the array is fully sorted
	}

	int thePivot = anArray[aRightIndex];
	int thePartitionIndex = partitionIt(anArray, aLeftIndex, aRightIndex, thePivot);

	//left part sorting
	quickSort(anArray, aLeftIndex, thePartitionIndex - 1);

	//right part sorting
	quickSort(anArray, thePartitionIndex + 1, aRightIndex);

	
}

void swap(int anArray[], int aLeftIndex, int aRightIndex)
{
	int theTmp = anArray[aLeftIndex];
	anArray[aLeftIndex] = anArray[aRightIndex];
	anArray[aRightIndex] = theTmp;
}

int mediana(int anArray[], int aLeftIndex, int aRightIndex)
{
	int theCenter = (aLeftIndex + aRightIndex) / 2;

	if (anArray[aLeftIndex] > anArray[theCenter])
	{
		swap(anArray, aLeftIndex, theCenter);
	}

	if (anArray[aLeftIndex] > anArray[aRightIndex])
	{
		swap(anArray, aLeftIndex, aRightIndex);
	}

	if (anArray[theCenter] > anArray[aRightIndex])
	{
		swap(anArray, theCenter, aRightIndex);
	}

	swap(anArray, theCenter, aRightIndex - 1);

	return anArray[aRightIndex - 1];
}

int m_partitionIt(int anArray[], int aLeftIndex, int aRightIndex, int aPivot)
{
	int theLeft = aLeftIndex;
	int theRight = aRightIndex - 1;

	while (1)
	{
		// search the bigest element
		while (anArray[++theLeft] < aPivot);

		// search the lowest element
		while (anArray[--theRight] > aPivot);

		if (theLeft >= theRight) // pointer are the same 
		{
			break;
		}
		else
		{
			//lets to swap elements
			swap(anArray, theLeft, theRight);
		}
	}

	//lets to swap elements
	swap(anArray, theLeft, aRightIndex - 1);

	return theLeft; // return break position
}

void quickSort_v2(int anArray[], int aLeftIndex, int aRightIndex)
{
	
	int theSize = aRightIndex - aLeftIndex + 1;

	if (theSize <= 3)
	{
		m_manualSort(anArray, aLeftIndex, aRightIndex);
	}
	else
	{
		int thePivot = mediana(anArray, aLeftIndex, aRightIndex);
		int thePartitionIndex = m_partitionIt(anArray, aLeftIndex, aRightIndex, thePivot);

		//left part sorting
		quickSort(anArray, aLeftIndex, thePartitionIndex - 1);

		//right part sorting
		quickSort(anArray, thePartitionIndex + 1, aRightIndex);
	}
	
}

void  m_manualSort(int anArray[], int aLeftIndex, int aRightIndex)
{
	int theSize = aRightIndex - aLeftIndex + 1;

	if (theSize <= 1)
	{
		return;
	}

	if (2 == theSize)
	{
		if (anArray[aLeftIndex] > anArray[aRightIndex])
		{
			swap(anArray, aLeftIndex, aRightIndex);
		}
		return;
	}
	else
	{
		// 3 elementes
		if (anArray[aLeftIndex] > anArray[aRightIndex - 1])
		{
			swap(anArray, aLeftIndex, aRightIndex - 1);
		}

		if (anArray[aLeftIndex] > anArray[aRightIndex])
		{
			swap(anArray, aLeftIndex, aRightIndex);
		}

		if (anArray[aRightIndex - 1] > anArray[aRightIndex])
		{
			swap(anArray, aRightIndex - 1, aRightIndex);
		}
	}
}

