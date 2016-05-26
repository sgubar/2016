#include "sort_lib.h"


void bubbleSort(int *anArray, int aSize)
{
	for (int theOut = aSize - 1; theOut > 1; theOut--)
	{
		for (int theIn = 0; theIn < theOut; theIn++)
		{
			if (*(anArray+theIn) > *(anArray+theIn+1))
			{
				int theTmp = *(anArray+theIn);
				*(anArray+theIn) = *(anArray+theIn+1);
				*(anArray+theIn+1) = theTmp;
			}
		}
	}
}

void selectionSort(int *anArray, int aSize)
{
	for (int theOut = 0; theOut < aSize - 1; theOut++)
	{
		int theMinIndex = theOut;

		for (int theIn = theOut + 1; theIn < aSize; theIn++)
		{
			if (*(anArray+theIn) < *(anArray+theMinIndex))
			{
				theMinIndex = theIn;
			}
		}

		int theTmp = *(anArray+theOut);
		*(anArray+theOut) = *(anArray+theMinIndex);
		*(anArray+theMinIndex) = theTmp;
	}
}

void insertionSort(int *anArray, int aSize)
{
	for (int theOut = 1; theOut < aSize; theOut++)
	{
		int theTmp = *(anArray+theOut);
		int theIn = theOut;

		while (theIn > 0 && *(anArray+theIn-1) >= theTmp)
		{
			*(anArray+theIn) = *(anArray+theIn-1);
			--theIn;
		}

		*(anArray+theIn) = theTmp;
	}
}
void shellSort(int *anArray, int aCount)
{
	int theInner = 0;
	int theOuter = 0;
	int theH = 1;
	while (theH <= aCount / 3)
	{
		theH = theH * 3 + 1;
	}
	while (theH > 0)
	{
		for (theOuter = theH; theOuter < aCount; theOuter++)
		{
			int theTmp = *(anArray+theOuter);
			theInner = theOuter;

			while (theInner > theH - 1 && *(anArray+theInner-theH) >= theTmp)
			{
				*(anArray+theInner) = *(anArray+theInner-theH);
				theInner -= theH;
			}

			*(anArray+theInner) = theTmp;
		}

		theH = (theH - 1) / 3;
	}
}



