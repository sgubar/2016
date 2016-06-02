#include "SimpleSort.h"

//Metod sortirovki "puzirkom"
void bubbleSort(int anArray[], int simpleSize)
{
	for (int theOut = simpleSize - 1; theOut > 1; theOut--)
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
}

//Metod sortirovki "viborom"
void selectionSort(int anArray[], int simpleSize)
{
	for (int theOut = 0; theOut < simpleSize - 1; theOut++)
	{
		int theMinIndex = theOut;

		for (int theIn = theOut + 1; theIn < simpleSize; theIn++)
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
}

//Metod sortirovki 'Vstavkoi"
void insertionSort(int anArray[], int simpleSize)
{
	for (int theOut = 1; theOut < simpleSize; theOut++)
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
}
