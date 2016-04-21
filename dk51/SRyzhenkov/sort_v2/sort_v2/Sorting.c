#include "Sorting.h"
#include <time.h>
#include <stdio.h>

void bubbleSort(int anArray[], int aSize)
{
	FILE * ptr = fopen("Plot.csv", "w+");
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
	fprintf(ptr, "Методи сортування;\nСортування бульбашкою; %.3lf\n", (double)(end_t1 - start_t1) / CLOCKS_PER_SEC);
	printf("time of Selection sorting: %.3lf\n", (double)(end_t1 - start_t1) / CLOCKS_PER_SEC);
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
	fprintf(ptr, "Сортування методом вибору; %.3lf\n", (double)(end_t2 - start_t2) / CLOCKS_PER_SEC);
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
	fprintf(ptr, "Сортування вставкою; %.3lf\n", (double)(end_t3 - start_t3) / CLOCKS_PER_SEC);
	printf("time of Selection sorting: %.3lf\n", (double)(end_t3 - start_t3) / CLOCKS_PER_SEC);
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
	fprintf(ptr, "Сортування Шелла; %.3lf\n", (double)(end_t4 - start_t4) / CLOCKS_PER_SEC);
	printf("time of Selection sorting: %.3lf\n", (double)(end_t4 - start_t4) / CLOCKS_PER_SEC);
	fclose(ptr);
}