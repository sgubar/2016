#include"Sorting.h"

#include <stdio.h>
#include <time.h>

void bubbleSort(int anArray[], int aSize)
{
	clock_t start1, end1;
	start1 = clock();
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
	end1 = clock();
	//printf("Time of start = %.15f", start1);
	//printf("Time of End = %.15f", end1);
	printf("Time of bubble sorting = %.15f\n", (double)(end1 - start1) / CLOCKS_PER_SEC);
}

void selectionSort(int anArray[], int aSize)
{
	clock_t start2, end2;
	start2 = clock();
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
	end2 = clock();
	//printf("Time of start = %.15f", start2);
	//printf("Time of End = %.15f", end2);
	printf("Time of selection sorting = %.15f\n", (double)(end2 - start2) / CLOCKS_PER_SEC);
}

void insertionSort(int anArray[], int aSize)
{
	clock_t start3, end3;
	start3 = clock();
	for (int theOut = 1; theOut < aSize; theOut++)
	{
		for (int theIn = theOut; theIn > 0 && anArray[theIn - 1] >= anArray[theIn]; theIn--)
		{
			int theTmp = anArray[theIn - 1];
			anArray[theIn - 1] = anArray[theIn];
			anArray[theIn] = theTmp;
		}
	}
	end3 = clock();
	//printf("Time of start = %.15f", start3);
	//printf("Time of End = %.15f", end3);
	printf("Time of insertion sorting = %.15f\n", (double)(end3 - start3) / CLOCKS_PER_SEC);
}
